/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:28:38 by malsabah          #+#    #+#             */
/*   Updated: 2026/01/12 20:25:35 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	create_image(t_fractol *f)
{
	f->img.img = mlx_new_image(f->mlx, WIN_W, WIN_H);
	if (!f->img.img)
		return (0);
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bpp, &f->img.line_len,
			&f->img.endian);
	if (!f->img.addr)
		return (0);
	return (1);
}

int	init_fractol(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		close_hook(f);
	f->win = mlx_new_window(f->mlx, WIN_W, WIN_H, "fractol");
	if (!f->win)
		close_hook(f);
	if (!create_image(f))
		close_hook(f);
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->max_iter = 100;
	if (f->fractal == 0)
		f->offset_x = -0.5;
	mlx_hook(f->win, 2, 1L << 0, key_hook, f);
	mlx_mouse_hook(f->win, mouse_hook, f);
	mlx_hook(f->win, 17, 0L, (void *)close_hook, f);
	return (1);
}
