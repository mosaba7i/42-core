/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 06:50:35 by malsabah          #+#    #+#             */
/*   Updated: 2025/09/11 08:54:34 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long n)
{
	char	*base;
	char	buf[17];
	int		i;
	int		len;

	base = "0123456789abcdef";
	i = 0;
	len = 0;
	if (n == 0)
		return (write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	while (n)
	{
		buf[i++] = base[n % 16];
		n /= 16;
	}
	while (i--)
		len += write(1, &buf[i], 1);
	return (len);
}
