#include "minitalk.h"

char	*strnew(char c)
{
	char	*ret;

	ret = malloc (sizeof(char) * 2);
	ret[0] = c;
	ret[1] = 0;
	return (ret);
}

void	append_byte(char c)
{
	static char	*msg;
	char		*tmp;
	char		char_str[2];

	if (!c)
	{
		write(1, msg, ft_strlen(msg));
		write(1, "\n", 1);
		free(msg);
		msg = NULL;
	}
	char_str[0] = c;
	char_str[1] = 0;
	//write(1, &c, 1);
	if (!msg)
		msg = strnew(c);
	else
	{
		tmp = msg;
		//printf("%c -> %s\n", c, tmp);
		msg = ft_strjoin(tmp, char_str);
		free(tmp);
		//printf("new msg: %s\n", msg);
	}
}

void	append_bit(char c)
{
	static char	*str;
	int			chr;

	//write(1, &c, 1);
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
		append_byte(chr);
		//write(1, &chr, 1);
		free(str);
		str = NULL;
	}
}

void	handle_signal(int id)
{
	if (id == SIGUSR1)
		append_bit('0');
	else if (id == SIGUSR2)
		append_bit('1');
}

int	main(void)
{
	printf("Server started. PID: %s%d%s\n", HGREEN, getpid(), RESET);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		;
}
