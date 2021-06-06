#include "minitalk.h"

char	*strnew(char c)
{
	char	*ret;

	ret = malloc (sizeof(char) * 2);
	ret[0] = c;
	ret[1] = 0;
	return (ret);
}
