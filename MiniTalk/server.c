#include <signal.h>
#include <unistd.h>

static void	brain(int vibe)
{
	static unsigned char	blob;
	static int				step;

	if (vibe == SIGUSR1)
		blob |= (1 << (7 - step));
	step++;
	if (step == 8)
	{
		if (blob == 0)
			write(1, "\n", 1);
		else
			write(1, &blob, 1);
		blob = 0;
		step = 0;
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
	signal(SIGUSR1, brain);
	signal(SIGUSR2, brain);
	while (1)
		pause();
	return (0);
}
