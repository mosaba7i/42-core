/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:42:43 by malsabah          #+#    #+#             */
/*   Updated: 2026/01/07 11:42:44 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
#include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define WIN_W 800
# define WIN_H 600

typedef enum e_fract
{
	MANDELBROT,
	JULIA
}	t_fract;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	t_img	img;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		max_iter;
	double	jr;
	double	ji;
	t_fract	fractal;
}	t_fractol;

/* main */
int		parse_args(int argc, char **argv, t_fractol *f);

/* init */
int		init_fractol(t_fractol *f);

/* events */
int		key_hook(int keycode, void *param);
int		mouse_hook(int button, int x, int y, void *param);
int		close_hook(void *param);

/* render */
void	render(t_fractol *f);
void	put_pixel(t_img *img, int x, int y, int color);

/* fractals */
int		mandelbrot_iter(double cr, double ci, int max_iter);
int		julia_iter(double zr, double zi, double cr, double ci, int max_iter);

/* utils */
double	ft_atof(const char *s);
double	map_x(int x, t_fractol *f);
double	map_y(int y, t_fractol *f);
int		error_exit(const char *msg);

/* colors */
int		color_from_iter(int iter, int max_iter);

#endif
