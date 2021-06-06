#include "minitalk.h"

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

void	handle_response(int id)
{
	if (id == SIGUSR1)
	{
		printf("Bien recu !\n");
		exit(0);
	}
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
	signal(SIGUSR1, handle_response);
	pid = ft_atoi(av[1]);
	msg = av[2];
	send_msg(msg, pid);
	send_null(pid);
	send_pid(pid);
	send_null(pid);
	while (1)
		;
}
