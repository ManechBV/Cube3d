/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarolla <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:09:36 by adarolla          #+#    #+#             */
/*   Updated: 2026/10/06 13:27:21 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_render	*ft_create_render(int x, int y, int w, int h)
{
	t_render	*new;

	new = malloc(sizeof(t_render));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->w = w;
	new->h = h;
	return (new);
}

t_map	*ft_alloc_map(t_game *game)
{
	t_map	*new;

	new = malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->scale = 20;
	new->size_x = game->map_width;
	new->size_y = game->map_height;
	new->nb_elements = new->size_x * new->size_y;
	new->tiles = malloc(sizeof(int) * (new->size_x * new->size_y));
	if (new->tiles == NULL)
	{
		free(new);
		return (NULL);
	}
	return (new);
}

t_map	*ft_convert_map(t_game *game)
{
	t_map			*new;
	unsigned int	x;
	unsigned int	y;
	unsigned int	i;

	new = ft_alloc_map(game);
	if (new == NULL)
		return (NULL);
	i = 0;
	y = 0;
	while (y < (unsigned int) new->size_y)
	{
		x = 0;
		while (x < (unsigned int) new->size_x)
		{
			new->tiles[i] = 0;
			if (x < ft_strlen(game->map[y]) && game->map[y][x] == '1')
				new->tiles[i] = 1;
			i++;
			x++;
		}
		y++;
	}
	return (new);
}

void	ft_main_second(t_game *game)
{
	game->vars = ft_init_vars(game, SCREEN_W, SCREEN_H, "paf");
	if (game->vars->init_failed == 0)
		mlx_loop(game->vars->mlx);
	ft_destroy_vars(game->vars);
	if (game->vars->mlx)
	{
		if (game->vars->win)
			mlx_destroy_window(game->vars->mlx, game->vars->win);
		mlx_destroy_display(game->vars->mlx);
	}
	if (game->vars != NULL)
		free(game->vars);
	if (game->map)
		free_double(game->map);
	free_textures(game->textures);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_putendl_fd("I need a file ??", 2);
		return (1);
	}
	ft_bzero(&game, sizeof(t_game));
	if (init_textures(&game))
		return (1);
	if (parse_data(av[1], &game) == 1)
	{
		if (game.map)
			free_double(game.map);
		if (game.textures)
			free_textures(game.textures);
		return (1);
	}
	init_engine(&game);
	ft_main_second(&game);
	return (0);
}
