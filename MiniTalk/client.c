#include <signal.h>
#include <unistd.h>

static int	numberify(char *dust)
{
	int	out;

	out = 0;
	while (*dust)
	{
		if (*dust < '0' || *dust > '9')
			return (-1);
		out = out * 10 + (*dust - '0');
		dust++;
	}
	return (out);
}

static void	beam(int target, unsigned char spark)
{
	int	jump;

	jump = 0;
	while (jump < 8)
	{
		if (spark & (1 << (7 - jump)))
			kill(target, SIGUSR1);
		else
			kill(target, SIGUSR2);
		usleep(120);
		jump++;
	}
}

int	main(int count, char **args)
{
	int	cursor;
	int	receiver;

	if (count != 3)
		return (write(2, "bad args\n", 9), 1);
	receiver = numberify(args[1]);
	if (receiver <= 0)
		return (write(2, "bad pid\n", 8), 1);
	cursor = 0;
	while (args[2][cursor])
		beam(receiver, args[2][cursor++]);
	beam(receiver, 0);
	return (0);
}
