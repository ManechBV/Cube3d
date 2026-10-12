/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarolla <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 23:33:25 by adarolla          #+#    #+#             */
/*   Updated: 2026/09/15 02:26:33 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

static int	count_sprites(char **map)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("23", map[y][x]))
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	init_sprites_second(t_game *game, int x, int y, int i)
{
	game->sprites[i].x = (double)x + 0.5;
	game->sprites[i].y = (double)y + 0.5;
	game->sprites[i].type = game->map[y][x] - '0';
	game->sprites[i].state = 0;
	game->map[y][x] = '0';
}

int	init_sprites(t_game *game)
{
	int	x;
	int	y;
	int	i;

	game->num_sprites = count_sprites(game->map);
	if (game->num_sprites == 0)
		return (0);
	game->sprites = ft_calloc(game->num_sprites, sizeof(t_sprite));
	if (!game->sprites)
		return (1);
	y = -1;
	i = 0;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (ft_strchr("23", game->map[y][x]))
			{
				init_sprites_second(game, x, y, i);
				i++;
			}
		}
	}
	return (0);
}
