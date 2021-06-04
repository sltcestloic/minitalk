#include "minitalk.h"

int	ft_splitlen(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return (0);
	while (split[i])
		i++;
	return (i);
}

char	*compute_args(char **args)
{
	char	*ret;
	char	*swap;
	int		i;

	i = 0;
	if (ft_splitlen(args) == 0)
		return (NULL);
	ret = malloc(1);
	*ret = 0;
	while (args[++i])
	{
		swap = ft_strjoin(ret, args[i]);
		free(ret);
		ret = swap;
		swap = ft_strjoin(ret, " ");
		free(ret);
		ret = swap;
	}
	ret[ft_strlen(ret) - 1] = 0;
	return (ret);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*msg;
	char	*binary;
	size_t	i;
	size_t	j;

	if (ac < 3)
	{
		printf("%sUsage: ./client <PID> <message>\n%s", HRED, RESET);
		exit(1);
	}
	i = 0;
	j = 0;
	pid = ft_atoi(av[1]);
	msg = compute_args(&av[1]);
	while (msg[i])
	{
		binary = ascii_to_binary(msg[i]);
		while (binary[j])
		{
			if (binary[j] == '0')
			{
				kill(pid, SIGUSR1);
				usleep(50);
			}
			else if (binary[j] == '1')
			{
				kill(pid, SIGUSR2);
				usleep(50);
			}
			j++;
		}
		j = 0;
		i++;
	}
	/* while (j < 8) TODO null terminer le string pr tout print d'un coup au lieu de char par char
	{
		kill(pid, SIGUSR1);
		usleep(100);
		j++;
	} */
	free(msg);
}
