#include "minitalk.h"

char	*ascii_to_binary(unsigned char nbr)
{
	int		i;
	char	*ret;
	char	base[2];

	i = 7;
	ft_strcpy(base, "01");
	ret = ft_strdup("00000000");
	while (nbr)
	{
		ret[i--] = base[nbr % 2];
		nbr /= 2;
	}
	return (ret);
}
