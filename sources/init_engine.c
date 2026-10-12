/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarolla <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 23:34:38 by adarolla          #+#    #+#             */
/*   Updated: 2026/09/16 23:23:09 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	get_map_dimensions(t_game *game)
{
	int	y;
	int	max_x;
	int	len;

	y = 0;
	max_x = 0;
	while (game->map[y])
	{
		len = (int)ft_strlen(game->map[y]);
		if (len > max_x)
			max_x = len;
		y++;
	}
	game->map_height = y;
	game->map_width = max_x;
}

int	init_engine(t_game *game)
{
	get_map_dimensions(game);
	init_player_camera(game);
	if (init_sprites(game) != 0)
		return (ft_putendl_fd("Error\nFailed to allocate sprites", 2), 1);
	return (0);
}
