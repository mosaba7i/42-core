/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:52:06 by malsabah          #+#    #+#             */
/*   Updated: 2025/09/10 13:52:07 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *fmt, ...);

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putunsigned(unsigned int n);
int	ft_puthex(unsigned int n, int upper);
int	ft_putptr(unsigned long n);

#endif