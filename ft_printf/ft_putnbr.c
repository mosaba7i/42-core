/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 06:07:19 by malsabah          #+#    #+#             */
/*   Updated: 2025/09/10 06:12:44 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	buf[12];
	int		i;
	int		len;
	long	nb;

	i = 0;
	len = 0;
	nb = n;
	if (nb == 0)
		return (write(1, "0", 1));
	if (nb < 0)
	{
		len += write(1, "-", 1);
		nb = -nb;
	}
	while (nb)
	{
		buf[i++] = '0' + (nb % 10);
		nb /= 10;
	}
	while (i--)
		len += write(1, &buf[i], 1);
	return (len);
}
