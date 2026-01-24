/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:28:56 by malsabah          #+#    #+#             */
/*   Updated: 2026/01/20 19:38:11 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_from_iter(int iter, int max_iter, int shift)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter >= max_iter)
		return (0x000000);
	t = (double)iter / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	r = (r + shift) % 256;
	g = (g + shift * 2) % 256;
	b = (b + shift * 3) % 256;
	return ((r << 16) | (g << 8) | b);
}
