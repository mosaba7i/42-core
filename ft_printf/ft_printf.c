/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:51:59 by malsabah          #+#    #+#             */
/*   Updated: 2025/09/10 16:50:40 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	helper_function(char spec, va_list ap)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (spec == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (spec == 'u')
		return (ft_putunsigned(va_arg(ap, unsigned int)));
	else if (spec == 'x')
		return (ft_puthex(va_arg(ap, unsigned int), 0));
	else if (spec == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), 1));
	else if (spec == 'p')
		return (ft_putptr(va_arg(ap, unsigned long)));
	else if (spec == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, fmt);
	if (!fmt)
		return (-1);
	while (fmt[i])
	{
		if (fmt[i] == '%')
			count += helper_function(fmt[++i], ap);
		else
			count += write(1, &fmt[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
