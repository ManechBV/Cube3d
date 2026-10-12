/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarolla <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:59:26 by adarolla          #+#    #+#             */
/*   Updated: 2025/11/13 12:59:26 by adarolla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

void			*ft_calloc(size_t nmemb, size_t size);

char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(const char *s, int c);

unsigned int	ft_strlen(char *s);

#endif
