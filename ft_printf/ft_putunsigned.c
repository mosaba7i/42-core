/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 07:23:03 by malsabah          #+#    #+#             */
/*   Updated: 2025/09/10 16:36:01 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	char	buf[11];
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (n == 0)
		return (write(1, "0", 1));
	while (n)
	{
		buf[i++] = '0' + (n % 10);
		n /= 10;
	}
	while (i--)
		len += write(1, &buf[i], 1);
	return (len);
}
