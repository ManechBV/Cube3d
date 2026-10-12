/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarolla <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:38:45 by adarolla          #+#    #+#             */
/*   Updated: 2025/11/14 11:38:45 by adarolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*get_free(char *buf, char *buffer)
{
	free(buf);
	free(buffer);
	return (NULL);
}

char	*stock_after(char *buffer)
{
	int		j;
	char	*str;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i] || !buffer[i + 1])
	{
		free(buffer);
		return (NULL);
	}
	str = ft_calloc(ft_strlen(buffer) - i + 1, 1);
	if (!str)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	free(buffer);
	return (str);
}

char	*read_buffer(int fd, char *buffer, int byte)
{
	char	*buf;
	char	*tmp;

	buf = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buf)
		return (NULL);
	while (byte > 0 && (!ft_strchr(buffer, '\n')))
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == -1)
			return (get_free(buf, buffer));
		buf[byte] = '\0';
		tmp = ft_strjoin(buffer, buf);
		if (!tmp)
			return (get_free(buf, buffer));
		buffer = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (buffer);
}

char	*extract_line(char *buffer)
{
	size_t	i;
	char	*line;

	if (!buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1025];
	char		*line;
	int			byte;

	byte = 1;
	line = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_buffer(fd, buffer[fd], byte);
	if (!buffer[fd])
		return (NULL);
	if (buffer[fd][0] == '\0')
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	line = extract_line(buffer[fd]);
	buffer[fd] = stock_after(buffer[fd]);
	return (line);
}
