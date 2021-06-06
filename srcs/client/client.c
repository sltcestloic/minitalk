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

void	msg_loop(char *msg, int pid)
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

void	send_null(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(SLEEP_TIME);
		i++;
	}
}

void	send_pid(int pid)
{
	char	*pid_str;
	char	*binary;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	pid_str = ft_itoa(getpid());
	while (pid_str[i])
	{
		binary = ascii_to_binary(pid_str[i]);
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
	free(pid_str);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*msg;

	if (ac != 3)
	{
		printf("%sUsage: ./client <PID> <message>\n%s", HRED, RESET);
		exit(1);
	}
	printf("PID client: %s%d%s\n", HGREEN, getpid(), RESET);
	pid = ft_atoi(av[1]);
	msg = av[2];
	msg_loop(msg, pid);
	send_null(pid);
	send_pid(pid);
	send_null(pid);
}
