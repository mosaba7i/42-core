/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:27:22 by malsabah          #+#    #+#             */
/*   Updated: 2026/01/12 18:06:01 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	offset = (y * img->line_len) + (x * (img->bpp / 8));
	dst = img->addr + offset;
	*(unsigned int *)dst = (unsigned int)color;
}

static void	draw_pixel(t_fractol *f, int x, int y)
{
	int			iter;
	t_complex	z;
	t_complex	c;

	c.r = map_x(x, f);
	c.i = map_y(y, f);
	if (f->fractal == 0)
	{
		z.r = 0.0;
		z.i = 0.0;
		iter = mandelbrot_iter(z, c, f->max_iter);
	}
	else
	{
		z.r = c.r;
		z.i = c.i;
		iter = julia_iter(z, f->jc, f->max_iter);
	}
	put_pixel(&f->img, x, y, color_from_iter(iter, f->max_iter));
}

void	render(t_fractol *f)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			draw_pixel(f, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}
