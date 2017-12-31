#include <stdlib.h>

int		get_num_long(value, base)
{
	int i;
	i = 0;
	while (value >= base)
	{
		value /= base;
		i++;
	}
	i++;
	return (i);
}


char	*ft_itoa_base(int value, int base)
{
	char tab[16] = "0123456789ABCDEF";
	char *ret;
	int ret_len;
	int neg_flag;
	char min_int[12] = "-2147483648";
	int i = 0;

	neg_flag = 0;

	if (value == -2147483648 && base == 10)
	{
		if (!(ret = (char *)malloc(sizeof(char) * 12)))
			return (NULL);
		while (i < 12)
		{
			ret[i] = min_int[i];
			i++;
		}
		ret[i] = '\0';
		return (ret);
	}

	if (value < 0)
	{
		if (base == 10)
			neg_flag = 1;
		value = -value;
	}
	
	ret_len = get_num_long(value, base);

	ret = (char *)malloc(sizeof(char) * ret_len + neg_flag + 1);

	ret[ret_len + neg_flag] = '\0';

	i = ret_len + neg_flag - 1;
	while (i >= neg_flag)
	{
		ret[i] = tab[value % base];
		value /= base;
		i--;
	}

	if (neg_flag)
		ret[0] = '-';

	return (ret);
}

/*
int	main(int ac, char **av)
{
	(void)ac;
	// 8. A handy way of testing
	printf("%s\n", ft_itoa_base(atoi(av[1]), atoi(av[2])));
	return (0);
}
*/
