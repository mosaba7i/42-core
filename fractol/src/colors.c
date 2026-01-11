/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:28:56 by malsabah          #+#    #+#             */
/*   Updated: 2026/01/11 14:16:36 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_from_iter(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;
	int		a;

	if (iter >= max_iter)
		return (0x000000);
	t = (double)iter / max_iter;
	r = (0 + t * 100);
	g = (0 + t * 180);
	b = (51 + t * 204);
	a = ((r << 16) | (g << 8) | b);
	return (a);
}
