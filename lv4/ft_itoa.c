#include <stdlib.h>

int ft_abs(int nbr)
{
	return (nbr >= 0 ? nbr : -nbr);
}

static int cnt_len(int n)
{
	if (!n)
		return (0);
	return (cnt_len(n / 10) + 1);
}

char	*ft_itoa(int nbr)
{
	int signe = (nbr >= 0 ? 0 : 1);
	int len = (nbr ? cnt_len(nbr) : 1);
	char *str = (char *)malloc(sizeof(char) * len + signe);
	str[len + signe] = '\0';
	while ((str[--len + signe] = ft_abs(nbr % 10) + '0') && (nbr /= 10))
		;
	if (signe)
		str[0] = '-';
	return (str);
}
