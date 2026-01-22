/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:27:49 by malsabah          #+#    #+#             */
/*   Updated: 2026/01/12 20:20:31 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

double	map_x(int x, t_fractol *f)
{
	double	range;
	double	a;

	range = 3.5 / f->zoom;
	a = ((x - WIN_W / 2.0) * (range / WIN_W) + f->offset_x);
	return (a);
}

double	map_y(int y, t_fractol *f)
{
	double	range;
	double	aspect;
	double	a;

	aspect = (double)WIN_H / (double)WIN_W;
	range = (3.5 * aspect) / f->zoom;
	a = (-((y - WIN_H / 2.0) * (range / WIN_H) + f->offset_y));
	return (a);
}

void	error_exit(const char *msg)
{
	if (msg)
	{
		write(2, msg, ft_strlen(msg));
	}
	return ;
}
