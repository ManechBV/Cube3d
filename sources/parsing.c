/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarolla <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 15:28:24 by adarolla          #+#    #+#             */
/*   Updated: 2026/09/17 02:15:47 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	ft_compare_id_check_dir(char *line, t_game *game, int i)
{
	if (ft_strncmp(line + i, "SO ", 3) == 0 && !game->textures->so)
	{
		game->textures->so = ft_strtrim(line + i + 3, "\n ");
		return (1);
	}
	else if (ft_strncmp(line + i, "NO ", 3) == 0 && !game->textures->no)
	{
		game->textures->no = ft_strtrim(line + i + 3, "\n ");
		return (1);
	}
	else if (ft_strncmp(line + i, "WE ", 3) == 0 && !game->textures->we)
	{
		game->textures->we = ft_strtrim(line + i + 3, "\n ");
		return (1);
	}
	else if (ft_strncmp(line + i, "EA ", 3) == 0 && !game->textures->ea)
	{
		game->textures->ea = ft_strtrim(line + i + 3, "\n ");
		return (1);
	}
	return (0);
}

int	compare_identifier(char *line, t_game *game, int i, int res)
{
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (0);
	if (ft_compare_id_check_dir(line, game, i) == 1)
		return (0);
	else if (ft_strncmp(line + i, "F ", 2) == 0
		&& game->textures->floor == -1)
	{
		res = take_rgb_colors(line + i + 2);
		if (res == -1)
			return (1);
		game->textures->floor = res;
	}
	else if (ft_strncmp(line + i, "C ", 2) == 0
		&& game->textures->celling == -1)
	{
		res = take_rgb_colors(line + i + 2);
		if (res == -1)
			return (1);
		game->textures->celling = res;
	}
	else
		return (ft_putendl_fd("Error\nWrong or duplicated identifier!", 2), 1);
	return (0);
}

int	parse_file_loop(t_game *game, int fd, char **line, int i)
{
	while (1)
	{
		*line = get_next_line(fd);
		if (!(*line))
			break ;
		i = 0;
		while ((*line)[i] == ' ' || ((*line)[i] >= 9 && (*line)[i] <= 13))
			i++;
		if ((*line)[i] != '\0' && (*line)[i] != '\n')
		{
			if (all_data_collected(game)
				&& ((*line)[i] == '1' || (*line)[i] == '0'))
				break ;
			if (compare_identifier((*line), game, 0, 0) != 0)
			{
				free(*line);
				clean_gnl(fd);
				close(fd);
				return (1);
			}
		}
		free(*line);
	}
	return (0);
}

int	parse_file(t_game *game, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	if (parse_file_loop(game, fd, &line, 0) == 1)
		return (1);
	if (check_path(game) != 0 || !all_data_collected(game))
	{
		free(line);
		clean_gnl(fd);
		close(fd);
		return (ft_putendl_fd("Error\nMissing or bad textures/colors", 2), 1);
	}
	if (get_map(game, fd, line) != 0)
	{
		clean_gnl(fd);
		return (close(fd), 1);
	}
	if (parse_map(game, 0, 0, 0) != 0)
		return (close(fd), 1);
	close(fd);
	return (0);
}

int	parse_data(char *filename, t_game *game)
{
	if (verify_filename(filename))
		return (1);
	if (parse_file(game, filename))
		return (1);
	return (0);
}
