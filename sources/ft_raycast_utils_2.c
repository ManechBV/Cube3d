/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 22:21:18 by mabenois          #+#    #+#             */
/*   Updated: 2026/09/16 23:21:48 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>

int	ft_darken_color(int color, int value)
{
	int	r;
	int	g;
	int	b;
	int	ret_color;

	r = get_r(color) - value;
	g = get_g(color) - value;
	b = get_b(color) - value;
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	ret_color = create_trgb(255, r, g, b);
	return (ret_color);
}

void	ft_correct_dir(double *dir)
{
	if (*dir > 2.0f * M_PI)
		*dir -= 2.0f * M_PI;
	if (*dir < 0)
		*dir += 2.0f * M_PI;
}

void	ft_draw_ray_hitpoint(t_vars *vars, t_ray *shortest)
{
	ft_image_draw_circle(vars->frame_img,
		(int [5]){(shortest->ray_x * vars->level->scale) - 3,
		(shortest->ray_y * vars->level->scale) - 3,
		6, 6, 0xFF00FF00});
}

void	ft_raycast_calculate_screen(t_vars *vars, double *screen_x,
		double *screen_y, int i)
{
	*screen_x = vars->player->smooth_x
		+ (cos(vars->player->dir) * vars->player->screen_dist)
		+ (cos(vars->player->dir - (M_PI / 2.0f))
			* (vars->player->screen_vec_len / 2.0f));
	*screen_y = vars->player->smooth_y
		+ (sin(vars->player->dir) * vars->player->screen_dist)
		+ (sin(vars->player->dir - (M_PI / 2.0f))
			* (vars->player->screen_vec_len / 2.0f));
	*screen_x += cos(vars->player->screen_vec_dir)
		* ((vars->player->screen_vec_len * (double)i)
			/ (double)vars->render->w);
	*screen_y += sin(vars->player->screen_vec_dir)
		* ((vars->player->screen_vec_len * (double)i)
			/ (double)vars->render->w);
}
