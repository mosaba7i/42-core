/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 12:08:16 by malsabah          #+#    #+#             */
/*   Updated: 2026/01/03 13:10:00 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_state;

static void	print_pid(void)
{
	char	buf[12];
	int		i;
	int		pid;

	pid = getpid();
	i = 0;
	if (pid == 0)
		buf[i++] = '0';
	while (pid > 0)
	{
		buf[i++] = (pid % 10) + '0';
		pid /= 10;
	}
	write(1, "PID: ", 5);
	while (--i >= 0)
		write(1, &buf[i], 1);
	write(1, "\n", 1);
}

static void	get_bit(int sig)
{
	static unsigned char	c;
	static int				bit;

	if (sig == SIGUSR1)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		g_state = c + 1;
		c = 0;
		bit = 0;
	}
}

static char	*append_char(char *msg, int len, char c)
{
	char	*new;
	int		i;

	new = malloc(len + 2);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = msg[i];
		i++;
	}
	new[len] = c;
	new[len + 1] = '\0';
	free(msg);
	return (new);
}

static void	print_msg(char **msg, int *len)
{
	write(1, *msg, *len);
	write(1, "\n", 1);
	free(*msg);
	*msg = NULL;
	*len = 0;
}

int	main(void)
{
	char	*msg;
	int		len;
	char	received;

	msg = NULL;
	len = 0;
	print_pid();
	signal(SIGUSR1, get_bit);
	signal(SIGUSR2, get_bit);
	while (1)
	{
		pause();
		if (g_state != 0)
		{
			received = (char)(g_state - 1);
			if (received == '\0')
				print_msg(&msg, &len);
			else
			{
				msg = append_char(msg, len, received);
				len++;
			}
			g_state = 0;
		}
	}
}
