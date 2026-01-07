/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:29:55 by malsabah          #+#    #+#             */
/*   Updated: 2026/01/07 11:29:56 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	usage(void)
{
	write(1, "Usage:\n", 6);
	write(1, "  ./fractol mandelbrot\n", 23);
	write(1, "  ./fractol julia <real> <imag>\n", 31);
}

static int	ft_atoi(const char *str)
{
	int	s;
	int	i;
	int	r;

	s = 1;
	i = 0;
	r = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			s = s * -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - '0');
		i++;
	}
	return (s * r);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s1[i] != '\0'
		&& (unsigned char)s2[i] == (unsigned char)s1[i] && i < n)
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	parse_args(int argc, char **argv, t_fractol *f)
{
	if (argc < 2)
	{
		usage();
		return (0);
	}
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0 || ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
	{
		f->fractal = MANDELBROT;
	}
	else if (ft_strncmp(argv[1], "julia", 6) == 0 || ft_strncmp(argv[1], "Julia", 6) == 0)

	{
		f->fractal = JULIA;
		if (argc >= 4)
		{
			f->jr = ft_atoi(argv[2]);
			f->ji = ft_atoi(argv[3]);
		}
		else
		{
			f->jr = -0.7;
			f->ji = 0.27015;
		}
	}
	else
	{
		usage();
		return (0);
	}
	return (1);
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
