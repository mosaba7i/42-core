/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 15:22:26 by malsabah          #+#    #+#             */
/*   Updated: 2025/09/28 14:43:23 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(len1 + len2 + 1);
	if (!res)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	ft_copy(res, s1, 0);
	ft_copy(res, s2, len1);
	res[len1 + len2] = '\0';
	if (s1)
		free(s1);
	return (res);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s || start >= ft_strlen(s))
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	ft_copy(char *d, char *s, size_t start)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		d[start + i] = s[i];
		i++;
	}
}
