#include "minitalk.h"

char	*rev_str(char *str)
{
	int	i;
	int	swap;
	int	size;

	size = ft_strlen(str);
	i = 0;
	while (i < size / 2)
	{
		swap = str[i];
		str[i] = str[size - (i + 1)];
		str[size - (i + 1)] = swap;
		++i;
	}
	return (str);
}

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
