/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 13:07:52 by malsabah          #+#    #+#             */
/*   Updated: 2026/01/11 15:18:52 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_valid_double(const char *s)
{
	int	dot;
	int	digit;

	dot = 0;
	digit = 0;
	if (!s || *s == '\0')
		return (0);
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (*s == '.')
		{
			if (dot)
				return (0);
			dot = 1;
		}
		else if (*s >= '0' && *s <= '9')
			digit = 1;
		else
			return (0);
		s++;
	}
	return (digit);
}

static double	parse_fraction(const char *s, double res)
{
	double	frac;

	frac = 0.1;
	while (*s >= '0' && *s <= '9')
	{
		res += (*s - '0') * frac;
		frac *= 0.1;
		s++;
	}
	return (res);
}

double	ft_a2double(const char *s)
{
	double	res;
	int		sign;

	res = 0.0;
	sign = 1;
	if (!s)
		return (0.0);
	while ((*s == 32) || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		res = (res * 10.0 + (*s++ - '0'));
	if (*s == '.')
	{
		s++;
		res = parse_fraction(s, res);
	}
	return (res * sign);
}

int	in_range(double v)
{
	if (v >= -2.0 && v <= 2.0)
		return (1);
	return (0);
}
