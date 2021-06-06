#include "minitalk.h"

void	send_signal(int pid, int signal)
{
	if (signal == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			printf("%sError: process with id %d doesn't exist.%s",
				HRED, pid, RESET);
			exit(1);
		}
	}
	else if (signal == 1)
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			printf("%sError: process with id %d doesn't exist.%s",
				HRED, pid, RESET);
			exit(1);
		}
	}
	usleep(SLEEP_TIME);
}

void	send_null(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		send_signal(pid, 0);
		usleep(SLEEP_TIME);
		i++;
	}
	usleep(SLEEP_TIME);
}

void	send_msg(char *msg, int pid)
{
	char	*binary;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (msg[i])
	{
		binary = ascii_to_binary(msg[i]);
		while (binary[j])
		{
			if (binary[j] == '0')
				send_signal(pid, 0);
			else if (binary[j] == '1')
				send_signal(pid, 1);
			j++;
		}
		free(binary);
		j = 0;
		i++;
	}
}
