/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:28:38 by malsabah          #+#    #+#             */
/*   Updated: 2026/01/07 11:28:39 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	create_image(t_fractol *f)
{
	f->img.img = mlx_new_image(f->mlx, WIN_W, WIN_H);
	if (!f->img.img)
		return (0);
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bpp,
			&f->img.line_len, &f->img.endian);
	return (1);
}

int	init_fractol(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		return (0);
	f->win = mlx_new_window(f->mlx, WIN_W, WIN_H, "fractol");
	if (!f->win)
		return (0);
	if (!create_image(f))
		return (0);
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->max_iter = 100;
	mlx_hook(f->win, 2, 1L<<0, key_hook, f);
	mlx_mouse_hook(f->win, mouse_hook, f);
	mlx_hook(f->win, 17, 0L, close_hook, f);
	return (1);
}
