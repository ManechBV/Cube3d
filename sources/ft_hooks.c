/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 22:40:48 by mabenois          #+#    #+#             */
/*   Updated: 2026/09/17 02:34:11 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	my_mouse_hook(int button, int x, int y, void *param)
{
	t_vars	*vars;

	vars = (t_vars *) param;
	if (button == 1)
	{
		if (ft_map_get_value(vars, x / vars->level->scale,
				y / vars->level->scale) == 0)
		{
			ft_map_set_value(vars, x / vars->level->scale,
				y / vars->level->scale, 1);
		}
		else
		{
			ft_map_set_value(vars, x / vars->level->scale,
				y / vars->level->scale, 0);
		}
	}
	return (0);
}

int	my_key_hook(int keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *) param;
	if (keycode == 0xff1b)
		mlx_loop_end(vars->mlx);
	if (keycode == 111)
		vars->level->scale += 5;
	if (keycode == 112)
		vars->level->scale -= 5;
	if (vars->level->scale < 1)
		vars->level->scale = 1;
	ft_update_player_rotation(vars, keycode, 0.3f);
	ft_update_player_movement(vars, keycode, 0.4f);
	return (0);
}

int	ft_close_window(void *param)
{
	t_vars	*vars;

	vars = (t_vars *) param;
	mlx_loop_end(vars->mlx);
	return (0);
}

int	update_hook(void *param)
{
	t_vars	*vars;

	vars = (t_vars *) param;
	vars->player->smooth_x += (vars->player->x - vars->player->smooth_x) / 18;
	vars->player->smooth_y += (vars->player->y - vars->player->smooth_y) / 18;
	ft_clear_img(vars->frame_img, vars->win_width,
		vars->win_height, 0x00404040);
	ft_raycast(vars);
	ft_draw_minimap(vars);
	ft_draw_player(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frame_img->img, 0, 0);
	return (0);
}
