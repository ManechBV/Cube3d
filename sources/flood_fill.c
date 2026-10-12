/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarolla <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 18:05:41 by adarolla          #+#    #+#             */
/*   Updated: 2026/07/15 00:07:24 by adarolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	check_neighbors(char **map, int y, int x)
{
	if (y == 0 || !map[y + 1] || x == 0 || !map[y][x + 1])
		return (1);
	if ((int)ft_strlen(map[y - 1]) <= x || map[y - 1][x] == ' ')
		return (1);
	if ((int)ft_strlen(map[y + 1]) <= x || map[y + 1][x] == ' ')
		return (1);
	if (map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
		return (1);
	return (0);
}

int	is_closed_by_walls(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				if (check_neighbors(map, y, x) == 1)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
