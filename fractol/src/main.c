/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 13:12:21 by malsabah          #+#    #+#             */
/*   Updated: 2026/01/11 15:22:44 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	usage(void)
{
	write(1, "Usage:\n", 7);
	write(1, "  ./fractol mandelbrot\n", 23);
	write(1, "  ./fractol julia <real> <imag>\n", 31);
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	parse_julia(int argc, char **argv, t_fractol *f)
{
	if (argc == 4)
	{
		if (!is_valid_double(argv[2]) || !is_valid_double(argv[3]))
			return (error_exit("Error: parameters must be numbers\n"));
		f->jc.r = ft_a2double(argv[2]);
		f->jc.i = ft_a2double(argv[3]);
		if (!in_range(f->jc.r) || !in_range(f->jc.i))
			return (error_exit("Error: parameters must be within [-2, 2]\n"));
	}
	else
	{
		f->jc.r = -0.835;
		f->jc.i = -0.2321;
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_fractol *f)
{
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		f->fractal = 0;
		return (1);
	}
	if ((argc == 2 || argc == 4) && ft_strncmp(argv[1], "julia", 6) == 0)
	{
		f->fractal = 1;
		return (parse_julia(argc, argv, f));
	}
	usage();
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	f.zoom = 1.0;
	f.offset_x = 0.0;
	f.offset_y = 0.0;
	f.max_iter = 100;
	if (!parse_args(argc, argv, &f))
		return (0);
	if (!init_fractol(&f))
		return (error_exit("Failed to initialize MLX\n"));
	render(&f);
	mlx_loop(f.mlx);
	return (0);
}
