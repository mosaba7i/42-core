/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 07:32:24 by malsabah          #+#    #+#             */
/*   Updated: 2025/09/10 15:56:25 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int upper)
{
	char	*base;
	char	buf[9];
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n == 0)
		return (write(1, "0", 1));
	while (n)
	{
		buf[i++] = base[n % 16];
		n /= 16;
	}
	while (i--)
		len += write(1, &buf[i], 1);
	return (len);
}
