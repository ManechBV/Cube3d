/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_utils_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 22:23:25 by mabenois          #+#    #+#             */
/*   Updated: 2026/09/17 02:22:39 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>

void	ft_raycast_vert_travel_ray(t_vars *vars, t_ray *r,
		double oriented_right)
{
	while (1)
	{
		r->map_x = (int)(r->ray_x - (0.5f - oriented_right * 0.5f));
		r->map_y = (int)r->ray_y;
		r->map_val = ft_map_get_value(vars, r->map_x, r->map_y);
		if (r->map_val != 0)
			break ;
		r->ray_x += r->delta_x;
		r->ray_y += r->delta_y - (oriented_right * r->delta_y * 2);
		if (r->ray_x < (double) vars->level->size_x
			&& r->ray_y < (double) vars->level->size_y)
			my_mlx_pixel_put(vars->frame_img,
				r->ray_x * vars->level->scale -1,
				r->ray_y * vars->level->scale - 1, 0xFF00FFFF);
	}
}

double	ft_raycast_vert_ray_first(t_vars *vars, t_ray *r, double dir)
{
	double	oriented_right;

	r->ray_dir = dir;
	r->ray_x = vars->player->smooth_x;
	r->ray_y = vars->player->smooth_y;
	oriented_right = 0;
	if (r->ray_dir > (M_PI * 1.5f) || r->ray_dir < (M_PI / 2.0f))
		oriented_right = 1;
	r->side_x = (double)((int)(r->ray_x + oriented_right));
	r->side_y = ft_abs(r->side_x - vars->player->smooth_x)
		* tan((M_PI * 2.0f) - r->ray_dir);
	return (oriented_right);
}

void	ft_raycast_vert_ray(t_vars *vars, t_ray *r, double dir)
{
	double	oriented_right;

	oriented_right = ft_raycast_vert_ray_first(vars, r, dir);
	r->ray_x = r->side_x;
	r->delta_x = -1.0f + (oriented_right * 2);
	r->ray_y += r->side_y - ((r->side_y * 2.0f) * oriented_right);
	r->delta_y = tan((M_PI * 2.0f) - r->ray_dir);
	ft_raycast_vert_travel_ray(vars, r, oriented_right);
	r->len = ft_double_coord_dist(vars->player->smooth_x,
			vars->player->smooth_y, r->ray_x, r->ray_y);
	r->fixed_len = r->len * cos(r->ray_dir - vars->player->dir);
	r->wall_orientation = 3;
	if (oriented_right == 1.0f)
	{
		r->wall_orientation = 1;
		r->texture_x = ft_abs(((double)((int) r->ray_y))
				- r->ray_y) * vars->texture_w->width;
	}
	else
		r->texture_x = vars->texture_e->width
			- ft_abs(((double)((int) r->ray_y))
				- r->ray_y) * vars->texture_e->width;
}

void	ft_raycast_hori_travel_ray(t_vars *vars, t_ray *r, double oriented_down)
{
	while (1)
	{
		r->map_y = (int)(r->ray_y - (0.5f - oriented_down * 0.5f));
		r->map_x = (int)r->ray_x;
		r->map_val = ft_map_get_value(vars, r->map_x, r->map_y);
		if (r->map_val != 0)
			break ;
		r->ray_x += (-1.0f * r->delta_x)
			+ (r->delta_x * (2.0f * oriented_down));
		r->ray_y += r->delta_y;
		if (r->ray_x < (double) vars->level->size_x
			&& r->ray_y < (double) vars->level->size_y)
			my_mlx_pixel_put(vars->frame_img,
				r->ray_x * vars->level->scale -1,
				r->ray_y * vars->level->scale - 1, 0xFF228888);
	}
}

double	ft_raycast_hori_ray_first(t_vars *vars, t_ray *r, double dir)
{
	double	oriented_down;

	r->ray_dir = dir;
	r->ray_x = vars->player->smooth_x;
	r->ray_y = vars->player->smooth_y;
	oriented_down = 0;
	if (r->ray_dir < M_PI)
		oriented_down = 1;
	r->side_y = (double)((int)(r->ray_y + oriented_down));
	r->side_x = ft_abs(vars->player->smooth_y - r->side_y)
		* tan((M_PI * 1.5f) - r->ray_dir);
	return (oriented_down);
}
