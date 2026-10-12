/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarolla <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 13:40:57 by adarolla          #+#    #+#             */
/*   Updated: 2026/06/30 17:23:08 by adarolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	init_textures(t_game *game)
{
	game->textures = ft_calloc(1, sizeof(t_textures));
	if (!game->textures)
		return (1);
	game->textures->ea = NULL;
	game->textures->no = NULL;
	game->textures->so = NULL;
	game->textures->we = NULL;
	game->textures->celling = -1;
	game->textures->floor = -1;
	return (0);
}
