/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 23:23:33 by mabenois          #+#    #+#             */
/*   Updated: 2026/09/17 02:22:07 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>

void	ft_raycast_hori_ray(t_vars *vars, t_ray *r, double dir)
{
	double	oriented_down;

	oriented_down = ft_raycast_hori_ray_first(vars, r, dir);
	r->ray_y = r->side_y;
	r->delta_y = -1.0f + (2.0f * oriented_down);
	r->ray_x += (-1.0f * r->side_x) + (oriented_down * (2.0f * r->side_x));
	r->delta_x = tan((M_PI * 1.5f) - r->ray_dir);
	ft_raycast_hori_travel_ray(vars, r, oriented_down);
	r->len = ft_double_coord_dist(vars->player->smooth_x,
			vars->player->smooth_y, r->ray_x, r->ray_y);
	r->fixed_len = r->len * cos(r->ray_dir - vars->player->dir);
	r->wall_orientation = 0;
	if (oriented_down == 1.0f)
	{
		r->wall_orientation = 2;
		r->texture_x = vars->texture_n->width
			- ft_abs(((double)((int) r->ray_x))
				- r->ray_x) * vars->texture_n->width;
	}
	else
		r->texture_x = ft_abs(((double)((int) r->ray_x)) - r->ray_x)
			* vars->texture_s->width;
}

t_img_data	*ft_choose_texture(t_vars *vars, t_ray *r)
{
	t_img_data	*texture;

	texture = vars->frame_img;
	if (r->wall_orientation == 0)
		texture = vars->texture_s;
	if (r->wall_orientation == 1)
		texture = vars->texture_w;
	if (r->wall_orientation == 2)
		texture = vars->texture_n;
	if (r->wall_orientation == 3)
		texture = vars->texture_e;
	return (texture);
}

// col_len 0, start_y 1, i 2, draw_x 3, draw_y 4,
// draw_w 5, draw_h 6, darken_value 7
void	ft_render_ceil_floor(int *i, t_vars *vars, double len_div, t_ray *r)
{
	i[0] = vars->render->h / len_div;
	i[1] = vars->render->y + (vars->render->h * 0.5f);
	i[7] = 0;
	if (r->wall_orientation % 2 == 0)
		i[7] = 30;
	i[3] = vars->render->x + i[8] * i[9];
	i[4] = i[1] - i[0] / 2;
	i[5] = i[9];
	i[6] = i[0];
	ft_image_draw_rec(vars->frame_img, (int [5]){i[3], vars->render->y, i[5],
		((vars->render->h - i[6]) / 2) + 1, vars->ceil});
	ft_image_draw_rec(vars->frame_img, (int [5]){i[3], i[4] + i[6], i[5],
		((vars->render->h - i[6]) / 2), vars->floor});
}

void	ft_raycast_render_ray(t_vars *vars, t_ray *r, int render_x, int scale)
{
	int				i[10];	
	double			len_div;
	unsigned int	color;
	double			texture_y_offset;
	t_img_data		*texture;

	texture = ft_choose_texture(vars, r);
	texture_y_offset = 0;
	len_div = r->fixed_len;
	if (len_div < 1.0f)
	{
		texture_y_offset = (1.0f - len_div) * ((double)texture->height / 2);
		len_div = 1.0f;
	}
	i[8] = render_x;
	i[9] = scale;
	ft_render_ceil_floor(i, vars, len_div, r);
	i[2] = -1;
	while (++(i[2]) < i[0])
	{
		color = my_mlx_pixel_get(texture, r->texture_x, texture_y_offset
				+ (i[2] * texture->height) / (vars->render->h / r->fixed_len));
		color = ft_darken_color(color, i[7]);
		my_mlx_pixel_put(vars->frame_img, i[3], i[4] + i[2], color);
	}
}

void	ft_raycast(t_vars *vars)
{
	t_ray		rays[2];
	double		player_dir;
	double		screen[2];
	t_ray		*shortest;
	int			i;

	i = -1;
	while (++i < vars->render->w)
	{
		ft_raycast_calculate_screen(vars, &screen[0], &screen[1], i);
		player_dir = M_PI_2 - (atan2(vars->player->smooth_x - screen[0],
					vars->player->smooth_y - screen[1]) + M_PI);
		ft_correct_dir(&player_dir);
		ft_raycast_vert_ray(vars, &rays[0], player_dir);
		ft_raycast_hori_ray(vars, &rays[1], player_dir);
		shortest = &rays[0];
		if (rays[1].len < shortest->len)
			shortest = &rays[1];
		ft_draw_ray_hitpoint(vars, shortest);
		ft_raycast_render_ray(vars, shortest, i, 1);
	}
}
