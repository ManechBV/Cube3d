/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 00:49:10 by mabenois          #+#    #+#             */
/*   Updated: 2026/09/16 23:15:24 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/*
t_map	*ft_generate_empty_map(int w, int h)
{
	t_map	*new;

	new = malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->scale = 20;
	new->size_x = w;
	new->size_y = h;
	new->nb_elements = w * h;
	new->tiles = malloc(sizeof(int) * (h * w));
	if (new->tiles == NULL)
	{
		free(new);
		return (NULL);
	}
	int i = 0;
	while (i < h * w)
	{
		new->tiles[i] = 0;
		if ((i < w) || (i > (w * h) - w) || (i % w == 0) || ((i + 1) % w == 0))
			new->tiles[i] = 1;
		i++;
	}
	return (new);
}
*/

int	ft_map_get_value(t_vars *vars, int x, int y)
{
	if (x >= vars->level->size_x || y >= vars->level->size_y)
		return (-1);
	if (x < 0 || y < 0)
		return (-1);
	return (vars->level->tiles[(y * vars->level->size_x) + x]);
}

int	ft_map_set_value(t_vars *vars, int x, int y, int val)
{
	if (x >= vars->level->size_x || y >= vars->level->size_y)
		return (-1);
	if (x < 0 || y < 0)
		return (-1);
	vars->level->tiles[(y * vars->level->size_x) + x] = val;
	return (val);
}

void	ft_draw_minimap(t_vars *vars)
{
	int	x;
	int	y;
	int	i;
	int	color;

	x = 0;
	y = 0;
	i = 0;
	while (i < vars->level->nb_elements)
	{
		color = 0xFF999999;
		if (vars->level->tiles[i] == 1)
			color = 0xFFFFFFFF;
		ft_image_draw_rec(vars->frame_img, (int [5]){x, y,
			vars->level->scale - 1, vars->level->scale - 1, color});
		x += vars->level->scale;
		i++;
		if (i % vars->level->size_x == 0)
		{
			y += vars->level->scale;
			x = 0;
		}
	}
}
