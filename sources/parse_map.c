/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarolla <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 23:17:08 by adarolla          #+#    #+#             */
/*   Updated: 2026/09/17 02:14:54 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	is_valid_character(char c)
{
	if (c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'E'
		&& c != 'W' && c != ' ')
		return (1);
	return (0);
}

int	is_player(char c)
{
	if (c == 'W' || c == 'E' || c == 'S' || c == 'N')
		return (0);
	else
		return (1);
}

int	parse_map(t_game *game, int x, int y, int player_count)
{
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (is_valid_character(game->map[y][x]))
				return (ft_putendl_fd("Invalid character", 2), 1);
			if (is_player(game->map[y][x]) == 0)
			{
				player_count++;
				game->player_x = (double)x + 0.5;
				game->player_y = (double)y + 0.5;
				game->player_dir = game->map[y][x];
				game->map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	if (player_count != 1)
		return (ft_putendl_fd("Where's the player ?", 2), 1);
	if (is_closed_by_walls(game->map) == 1)
		return (ft_putendl_fd("Error\nMap is not closed by walls !", 2), 1);
	return (0);
}
