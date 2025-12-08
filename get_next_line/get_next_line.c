/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:40:18 by malsabah          #+#    #+#             */
/*   Updated: 2025/09/28 15:06:54 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char **s)
{
	if (*s)
		free(*s);
	*s = NULL;
	return (NULL);
}

static char	*ft_extract_line(char **leftover)
{
	char	*line;
	char	*rest;
	char	*next_line;
	size_t	len;

	if (!*leftover || **leftover == '\0')
		return (NULL);
	next_line = ft_strchr(*leftover, '\n');
	if (next_line)
		len = next_line - *leftover + 1;
	else
		len = ft_strlen(*leftover);
	line = ft_substr(*leftover, 0, len);
	if (!line)
		return (ft_free(leftover));
	rest = ft_substr(*leftover, len, ft_strlen(*leftover) - len);
	free(*leftover);
	if (rest && *rest == '\0')
	{
		free(rest);
		rest = NULL;
	}
	*leftover = rest;
	return (line);
}

static int	ft_read_fd(int fd, char **leftover)
{
	char	*buf;
	ssize_t	read_;

	buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	read_ = read(fd, buf, BUFFER_SIZE);
	if (read_ <= 0)
	{
		free(buf);
		return ((int)read_);
	}
	buf[read_] = '\0';
	*leftover = ft_strjoin(*leftover, buf);
	free(buf);
	if (!*leftover)
		return (-1);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!(ft_strchr(leftover, '\n')))
	{
		n = ft_read_fd(fd, &leftover);
		if (n == -1)
			return (ft_free(&leftover));
		if (n == 0)
			break ;
	}
	return (ft_extract_line(&leftover));
}
