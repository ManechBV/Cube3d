/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 23:07:18 by mabenois          #+#    #+#             */
/*   Updated: 2026/09/16 23:07:52 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>

void	ft_draw_player_second(t_vars *vars)
{
	double	screen_x;
	double	screen_y;

	screen_x = vars->player->smooth_x + (cos(vars->player->dir)
			* vars->player->screen_dist) + (cos(vars->player->dir
				- (M_PI / 2.0f)) * (vars->player->screen_vec_len / 2.0f));
	screen_x += cos(vars->player->screen_vec_dir)
		* vars->player->screen_vec_len;
	screen_y = vars->player->smooth_y + (sin(vars->player->dir)
			* vars->player->screen_dist) + (sin(vars->player->dir
				- (M_PI / 2.0f)) * (vars->player->screen_vec_len / 2.0f));
	screen_y += sin(vars->player->screen_vec_dir)
		* vars->player->screen_vec_len;
	screen_x *= (double)vars->level->scale;
	screen_y *= (double)vars->level->scale;
	my_mlx_pixel_put(vars->frame_img, screen_x, screen_y, 0xFF000000);
}

void	ft_draw_player(t_vars *vars)
{
	double	screen_x;
	double	screen_y;

	ft_image_draw_circle(vars->frame_img,
		(int [5]){(vars->player->smooth_x * vars->level->scale) - 10,
		(vars->player->smooth_y * vars->level->scale) - 10,
		20, 20, 0xFF0000FF});
	ft_image_draw_circle(vars->frame_img, (int [5]){(vars->player->smooth_x
			* vars->level->scale) - 4 + (cos(vars->player->dir) * 6),
		(vars->player->smooth_y * vars->level->scale) - 4
		+ (sin(vars->player->dir) * 6), 8, 8, 0xFF00FFFF});
	screen_x = vars->player->smooth_x + (cos(vars->player->dir)
			* vars->player->screen_dist) + (cos(vars->player->dir
				- (M_PI / 2.0f)) * (vars->player->screen_vec_len / 2.0f));
	screen_y = vars->player->smooth_y + (sin(vars->player->dir)
			* vars->player->screen_dist) + (sin(vars->player->dir
				- (M_PI / 2.0f)) * (vars->player->screen_vec_len / 2.0f));
	screen_x *= (double)vars->level->scale;
	screen_y *= (double)vars->level->scale;
	my_mlx_pixel_put(vars->frame_img, screen_x, screen_y, 0xFF000000);
	ft_draw_player_second(vars);
}
