/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:29:50 by malsabah          #+#    #+#             */
/*   Updated: 2026/01/11 13:44:57 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_iter(t_complex z, t_complex c, int max_iter)
{
	double	tmp;
	int		i;

	i = 0;
	while (z.r * z.r + z.i * z.i <= 4.0 && i < max_iter)
	{
		tmp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2.0 * z.r * z.i + c.i;
		z.r = tmp;
		i++;
	}
	return (i);
}
