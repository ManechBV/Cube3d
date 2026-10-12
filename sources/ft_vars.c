/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 22:37:30 by mabenois          #+#    #+#             */
/*   Updated: 2026/09/17 02:33:23 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_vars	*ft_init_vars_second(t_game *game, t_vars *vars, int width, int height)
{
	double			dir;

	if ((char)game->player_dir == 'E')
		dir = 0.001f;
	else if ((char)game->player_dir == 'S')
		dir = M_PI_2;
	else if ((char)game->player_dir == 'W')
		dir = M_PI;
	else
		dir = M_PI + M_PI_2;
	vars->player = ft_create_player(vars, game->player_x, game->player_y, dir);
	if (vars->player == NULL)
		return (vars);
	vars->render = ft_create_render(0, 0, width, height);
	if (vars->render == NULL)
		return (vars);
	mlx_key_hook(vars->win, my_key_hook, vars);
	mlx_mouse_hook(vars->win, my_mouse_hook, vars);
	mlx_loop_hook(vars->mlx, update_hook, vars);
	mlx_hook(vars->win, 17, 1L << 0, ft_close_window, vars);
	vars->init_failed = 0;
	return (vars);
}

t_vars	*ft_init_vars(t_game *game, int width, int height, char *title)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (NULL);
	vars->init_failed = 1;
	vars->level = ft_convert_map(game);
	vars->win_width = width;
	vars->win_height = height;
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		return (vars);
	vars->win = mlx_new_window(vars->mlx, vars->win_width,
			vars->win_height, title);
	if (vars->win == NULL)
		return (vars);
	vars->frame_img = ft_new_img(vars->mlx, vars->win_width, vars->win_height);
	if (vars->frame_img == NULL)
		return (vars);
	if (ft_load_textures(game, vars) == 1)
		return (vars);
	return (ft_init_vars_second(game, vars, width, height));
}

void	ft_destroy_vars(t_vars *vars)
{
	if (vars == NULL)
		return ;
	if (vars->render)
		free(vars->render);
	if (vars->player)
		free(vars->player);
	ft_free_img(vars->mlx, vars->texture_e);
	ft_free_img(vars->mlx, vars->texture_n);
	ft_free_img(vars->mlx, vars->texture_s);
	ft_free_img(vars->mlx, vars->texture_w);
	ft_free_img(vars->mlx, vars->frame_img);
	if (vars->level)
	{
		if (vars->level->tiles)
			free(vars->level->tiles);
		free(vars->level);
	}
}
