/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:27:22 by malsabah          #+#    #+#             */
/*   Updated: 2026/01/07 11:27:24 by malsabah         ###   ########.fr       */
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

void	render(t_fractol *f)
{
	int		x;
	int		y;
	int		iter;
	double	cr;
	double	ci;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			cr = map_x(x, f);
			ci = map_y(y, f);
			if (f->fractal == MANDELBROT)
				iter = mandelbrot_iter(cr, ci, f->max_iter);
			else
				iter = julia_iter(cr, ci, f->jr, f->ji, f->max_iter);
			put_pixel(&f->img, x, y,
				color_from_iter(iter, f->max_iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}

