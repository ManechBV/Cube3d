/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 19:08:37 by mabenois          #+#    #+#             */
/*   Updated: 2026/09/20 16:32:45 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

float	ft_int_coord_dist(int x1, int y1, int x2, int y2)
{
	float	res;
	float	a;
	float	b;

	a = (float)(x2 - x1);
	b = (float)(y2 - y1);
	res = sqrtf((a * a) + (b * b));
	return (res);
}

double	ft_double_coord_dist(double x1, double y1, double x2, double y2)
{
	double	res;
	double	a;
	double	b;

	a = x2 - x1;
	b = y2 - y1;
	res = sqrt((a * a) + (b * b));
	return (res);
}

int	ft_int_error(char *msg, int ret)
{
	printf("\n%s", msg);
	return (ret);
}

void	*ft_error(char *msg)
{
	printf("\n%s", msg);
	return (NULL);
}

void	ft_player_move(t_vars *vars, double x, double y)
{
	vars->player->x += x;
	if (x > 0.0f)
	{
		if (ft_map_get_value(vars, vars->player->x + 0.15f,
				vars->player->y) != 0)
			vars->player->x -= x;
	}
	else if (ft_map_get_value(vars, vars->player->x - 0.15f,
			vars->player->y) != 0)
		vars->player->x -= x;
	vars->player->y += y;
	if (y > 0.0f)
	{
		if (ft_map_get_value(vars, vars->player->x,
				vars->player->y + 0.15f) != 0)
			vars->player->y -= y;
	}
	else if (ft_map_get_value(vars, vars->player->x,
			vars->player->y - 0.15f) != 0)
		vars->player->y -= y;
	if (vars->player->x < 0.0f)
		vars->player->x = 0.0f;
	if (vars->player->y < 0.0f)
		vars->player->y = 0.0f;
}
