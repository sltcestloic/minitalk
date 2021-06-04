#include "minitalk.h"

void	append_nbr(char c)
{
	static char	*str;
	int			chr;

	if (!str)
	{
		str = malloc(sizeof(char) * 9);
		ft_bzero(str, 9);
		str[0] = c;
	}
	else
		str[ft_strlen(str)] = c;
	if (ft_strlen(str) == 8)
	{
		chr = ft_atoi_base(str, "01");
		write(1, &chr, 1);
		free(str);
		str = NULL;
	}
}

void	handle_signal(int id)
{
	if (id == SIGUSR1)
		append_nbr('0');
	else if (id == SIGUSR2)
		append_nbr('1');
}

int	main(void)
{
	printf("Server started. PID: %s%d%s\n", HGREEN, getpid(), RESET);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		;
}
