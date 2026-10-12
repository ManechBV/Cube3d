/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarolla <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 23:29:47 by adarolla          #+#    #+#             */
/*   Updated: 2026/07/14 23:33:23 by adarolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	set_north_south(t_game *game)
{
	if (game->player_dir == 'N')
	{
		game->dir_x = 0.0;
		game->dir_y = -1.0;
		game->plane_x = 0.66;
		game->plane_y = 0.0;
	}
	else if (game->player_dir == 'S')
	{
		game->dir_x = 0.0;
		game->dir_y = 1.0;
		game->plane_x = -0.66;
		game->plane_y = 0.0;
	}
}

static void	set_east_west(t_game *game)
{
	if (game->player_dir == 'E')
	{
		game->dir_x = 1.0;
		game->dir_y = 0.0;
		game->plane_x = 0.0;
		game->plane_y = 0.66;
	}
	else if (game->player_dir == 'W')
	{
		game->dir_x = -1.0;
		game->dir_y = 0.0;
		game->plane_x = 0.0;
		game->plane_y = -0.66;
	}
}

void	init_player_camera(t_game *game)
{
	set_north_south(game);
	set_east_west(game);
}
