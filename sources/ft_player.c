/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 23:32:21 by mabenois          #+#    #+#             */
/*   Updated: 2026/09/20 15:54:09 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <math.h>

void	ft_player_rotate(t_vars *vars, double radians)
{
	vars->player->dir += radians;
	if (radians > 0.0f)
		if (vars->player->dir > 2.0f * M_PI)
			vars->player->dir -= 2.0f * M_PI;
	if (radians < 0.0f)
		if (vars->player->dir < 0)
			vars->player->dir += 2.0f * M_PI;
	vars->player->screen_vec_dir = ft_rotate_dir(vars->player->dir, M_PI_2);
}

void	ft_update_player_rotation(t_vars *vars, int keycode, double rot_speed)
{
	if (keycode == 65361)
		ft_player_rotate(vars, rot_speed * -1);
	if (keycode == 65363)
		ft_player_rotate(vars, rot_speed);
}

void	ft_update_player_movement(t_vars *vars, int keycode,
		double player_speed)
{
	if (keycode == 119)
	{
		ft_player_move(vars, cos(vars->player->dir) * player_speed,
			sin(vars->player->dir) * player_speed);
	}
	if (keycode == 115)
	{
		ft_player_move(vars, cos(vars->player->dir) * player_speed * -1.0f,
			sin(vars->player->dir) * player_speed * -1.0f);
	}
	if (keycode == 97)
	{
		ft_player_move(vars, cos(vars->player->dir
				- (M_PI / 2.0f)) * player_speed,
			sin(vars->player->dir
				- (M_PI / 2.0f)) * player_speed);
	}
	if (keycode == 100)
	{
		ft_player_move(vars, cos(vars->player->dir
				+ (M_PI / 2.0f)) * player_speed,
			sin(vars->player->dir
				+ (M_PI / 2.0f)) * player_speed);
	}
}

double	ft_rotate_dir(double dir, double radians)
{
	dir += radians;
	if (radians > 0.0f)
		if (dir > 2.0f * M_PI)
			dir -= 2.0f * M_PI;
	if (radians < 0.0f)
		if (dir < 0)
			dir += 2.0f * M_PI;
	return (dir);
}

t_player	*ft_create_player(t_vars *vars, double x, double y, double dir)
{
	t_player	*new;

	new = malloc(sizeof(t_player));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->dir = dir;
	new->smooth_x = x;
	new->smooth_y = y;
	new->fov = M_PI_4;
	new->screen_vec_len = (double)vars->win_width / (double)vars->win_height;
	new->screen_dist = tan(new->fov / 2) / (new->screen_vec_len / 2);
	new->screen_vec_dir = ft_rotate_dir(new->dir, M_PI_2);
	return (new);
}
