/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:42:43 by malsabah          #+#    #+#             */
/*   Updated: 2026/01/24 19:24:14 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# define WIN_W 500
# define WIN_H 500

typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	t_img		img;
	double		zoom;
	double		offset_x;
	double		offset_y;
	int			max_iter;
	int			fractal;
	int			color_shift;
	t_complex	jc;
}				t_fractol;

int				is_valid_double(const char *s);
int				in_range(double v);
double			ft_a2double(const char *s);
int				parse_args(int argc, char **argv, t_fractol *f);
int				init_fractol(t_fractol *f);
int				key_hook(int keycode, void *param);
int				mouse_hook(int button, int x, int y, void *param);
void			close_hook(void *param);
void			render(t_fractol *f);
void			put_pixel(t_img *img, int x, int y, int color);
void			error_exit(const char *msg);
int				mandelbrot_iter(t_complex z, t_complex c, int max_iter);
int				julia_iter(t_complex z, t_complex c, int max_iter);
double			map_x(int x, t_fractol *f);
double			map_y(int y, t_fractol *f);
int				color_from_iter(int iter, int max_iter, int shift);

#endif