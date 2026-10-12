/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarolla <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:54:02 by adarolla          #+#    #+#             */
/*   Updated: 2026/09/16 23:27:37 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game.h"

int	get_map(t_game *game, int fd, char *first_line)
{
	char	*temp;
	char	*line;
	char	*big_str;

	if (!first_line)
		return (1);
	big_str = ft_strdup(first_line);
	free(first_line);
	if (!big_str)
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = ft_strjoin(big_str, line);
		free(line);
		if (!temp)
			return (1);
		big_str = temp;
	}
	game->map = ft_split(big_str, '\n');
	free(big_str);
	return (game->map == NULL);
}

int	check_path(t_game *game)
{
	int	fd;

	fd = open(game->textures->ea, O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("Error\nBad texture path (EA)", 2), 1);
	close(fd);
	fd = open(game->textures->so, O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("Error\nBad texture path (SO)", 2), 1);
	close(fd);
	fd = open(game->textures->we, O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("Error\nBad texture path (WE)", 2), 1);
	close(fd);
	fd = open(game->textures->no, O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("Error\nBad texture path (NO)", 2), 1);
	close(fd);
	return (0);
}
