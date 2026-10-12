/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 22:34:12 by mabenois          #+#    #+#             */
/*   Updated: 2026/09/17 02:26:08 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	ft_load_textures_third(t_game *game, t_vars *vars)
{
	vars->texture_s->addr = mlx_get_data_addr(vars->texture_s->img,
			&vars->texture_s->bpp, &vars->texture_s->line_length,
			&vars->texture_s->endian);
	if (vars->texture_s->addr == NULL)
		return (1);
	vars->texture_w = ft_alloc_img_data();
	if (vars->texture_w == NULL)
		return (1);
	vars->texture_w->img = mlx_xpm_file_to_image(vars->mlx, game->textures->we,
			&vars->texture_w->width, &vars->texture_w->height);
	if (vars->texture_w->img == NULL)
		return (1);
	vars->texture_w->addr = mlx_get_data_addr(vars->texture_w->img,
			&vars->texture_w->bpp, &vars->texture_w->line_length,
			&vars->texture_w->endian);
	if (vars->texture_w->addr == NULL)
		return (1);
	return (0);
}

int	ft_load_textures_second(t_game *game, t_vars *vars)
{
	vars->texture_e = ft_alloc_img_data();
	if (vars->texture_e == NULL)
		return (1);
	vars->texture_e->img = mlx_xpm_file_to_image(vars->mlx,
			game->textures->ea, &vars->texture_e->width,
			&vars->texture_e->height);
	if (vars->texture_e->img == NULL)
		return (1);
	vars->texture_e->addr = mlx_get_data_addr(vars->texture_e->img,
			&vars->texture_e->bpp, &vars->texture_e->line_length,
			&vars->texture_e->endian);
	if (vars->texture_e->addr == NULL)
		return (1);
	vars->texture_s = ft_alloc_img_data();
	if (vars->texture_s == NULL)
		return (1);
	vars->texture_s->img = mlx_xpm_file_to_image(vars->mlx, game->textures->so,
			&vars->texture_s->width, &vars->texture_s->height);
	if (vars->texture_s->img == NULL)
		return (1);
	return (ft_load_textures_third(game, vars));
}

int	ft_load_textures(t_game *game, t_vars *vars)
{
	vars->ceil = game->textures->celling;
	vars->floor = game->textures->floor;
	vars->texture_n = ft_alloc_img_data();
	if (vars->texture_n == NULL)
		return (1);
	vars->texture_n->img = mlx_xpm_file_to_image(vars->mlx, game->textures->no,
			&vars->texture_n->width, &vars->texture_n->height);
	if (vars->texture_n->img == NULL)
		return (1);
	vars->texture_n->addr = mlx_get_data_addr(vars->texture_n->img,
			&vars->texture_n->bpp,
			&vars->texture_n->line_length, &vars->texture_n->endian);
	if (vars->texture_n->addr == NULL)
		return (1);
	return (ft_load_textures_second(game, vars));
}
