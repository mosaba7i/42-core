/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:29:50 by malsabah          #+#    #+#             */
/*   Updated: 2026/01/07 11:29:51 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_iter(double zr, double zi, double cr, double ci, int max_iter)
{
	double	tmp;
	int		i;

	i = 0;
	while (zr * zr + zi * zi <= 4.0 && i < max_iter)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = tmp;
		i++;
	}
	return (i);
}
