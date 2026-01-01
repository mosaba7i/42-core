#include <signal.h>
#include <unistd.h>

static void	get_bit(int bit)
{
	static unsigned char	built_char;
	static int				bit_cursor;

	if (bit == SIGUSR1)
		built_char |= (1 << (7 - bit_cursor));
	bit_cursor++;
	if (bit_cursor == 8)
	{
		if (built_char == 0)
			write(1, "\n", 1);
		else
			write(1, &built_char, 1);
		built_char = 0;
		bit_cursor = 0;
	}
}

int	main(void)
{
	char	buff[12];
	int		spin;
	int		id;

	id = getpid();
	spin = 10;
	buff[11] = '\n';
	while (spin >= 0)
	{
		buff[spin--] = (id % 10) + '0';
		id /= 10;
		if (!id)
			break ;
	}
	write(1, "PID: ", 5);
	write(1, &buff[spin + 1], 11 - spin);
	signal(SIGUSR1, get_bit);
	signal(SIGUSR2, get_bit);
	while (1)
		pause();
	return (0);
}