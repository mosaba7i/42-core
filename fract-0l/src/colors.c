/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:28:56 by malsabah          #+#    #+#             */
/*   Updated: 2026/01/07 11:28:57 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_from_iter(int iter, int max_iter)
{
	int	r;
	int	g;
	int	b;
	int	t;

	if (iter >= max_iter) //mandelbrot
		return (0x000000);
	t = iter * 255 / max_iter;
	r = (t * 9) % 256;
	g = (t * 2) % 256;
	b = (t * 5) % 256;
	return ((r << 16) | (g << 8) | b);
}
