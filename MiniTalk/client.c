/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 12:08:12 by malsabah          #+#    #+#             */
/*   Updated: 2026/01/03 12:16:34 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(char *pid)
{
	int	out;

	out = 0;
	while (*pid)
	{
		if (*pid < '0' || *pid > '9')
			return (-1);
		out = out * 10 + (*pid - '0');
		pid++;
	}
	return (out);
}

static void	send_char(int target, unsigned char spark)
{
	int	bit_cursor;

	bit_cursor = 0;
	while (bit_cursor < 8)
	{
		if (spark & (1 << (7 - bit_cursor)))
			kill(target, SIGUSR1);
		else
			kill(target, SIGUSR2);
		usleep(500);
		bit_cursor++;
	}
}

static void	print_batman(void)
{
	write(1, "\n", 1);
	write(1, "---------------(Message Sent Successfully)---------------\n", 59);
	write(1, "              *         *      *         *\n", 44);
	write(1, "          ***          **********          ***\n", 48);
	write(1, "       *****           **********           *****\n", 51);
	write(1, "     *******           **********           *******\n", 53);
	write(1, "   **********         ************         **********\n", 55);
	write(1, "  ****************************************************\n", 56);
	write(1, " ******************************************************\n", 57);
	write(1, "********************************************************\n", 58);
	write(1, "********************************************************\n", 58);
	write(1, "********************************************************\n", 58);
	write(1, " ******************************************************\n", 57);
	write(1, "  ********      ************************      ********\n", 56);
	write(1, "   *******       *     *********      *       *******\n", 55);
	write(1, "     ******             *******              ******\n", 53);
	write(1, "       *****             *****              *****\n", 51);
	write(1, "          ***             ***              ***\n", 48);
	write(1, "            **             *              **\n", 46);
}

int	main(int argc, char **argv)
{
	int	char_cursor;
	int	receiver;

	if (argc != 3)
	{
		write(2, "bad args\n", 9);
		return (1);
	}
	receiver = ft_atoi(argv[1]);
	if (receiver <= 0)
	{
		write(2, "bad pid\n", 8);
		return (1);
	}
	char_cursor = 0;
	while (argv[2][char_cursor])
	{
		send_char(receiver, argv[2][char_cursor]);
		char_cursor++;
	}
	send_char(receiver, 0);
	print_batman();
	return (0);
}
