/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 02:11:53 by mabenois          #+#    #+#             */
/*   Updated: 2026/10/06 14:05:40 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "libft.h"

int	all_data_collected(t_game *game)
{
	if (game->textures->no && game->textures->so && game->textures->we
		&& game->textures->ea && game->textures->floor != -1
		&& game->textures->celling != -1)
		return (1);
	return (0);
}

int	verify_filename(char *filename)
{
	int	size;

	size = ft_strlen(filename);
	if (size < 4 || ft_strncmp(filename + size - 4, ".cub", 4) != 0)
	{
		write(STDERR_FILENO, "Error it must be '.cub' format.\n", 32);
		return (1);
	}
	return (0);
}

int	ft_str_is_nb(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if (s[i] < '0' || s[i] > '9')
		{
			printf("Colors only accept decimal notation.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_colors(char *r, char *g, char *b)
{
	if (ft_str_is_nb(r) != 0)
		return (1);
	if (ft_str_is_nb(g) != 0)
		return (1);
	if (ft_str_is_nb(b) != 0)
		return (1);
	return (0);
}

int	take_rgb_colors(char *line)
{
	char	**split;
	int		r;
	int		g;
	int		b;
	int		i;

	i = 0;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	split = ft_split(line + i, ',');
	if (!split)
		return (-1);
	if (!split[0] || !split[1] || !split[2] || split[3])
	{
		free_double(split);
		return (-1);
	}
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	i = ft_check_colors(split[0], split[1], split[2]);
	free_double(split);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255 || i != 0)
		return (ft_int_error("Colors are not in the good format.", -1));
	return ((r << 16 | g << 8) | b);
}
