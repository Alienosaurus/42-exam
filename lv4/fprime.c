#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_atoi(char *nb)
{
	int		sign;
	int		result;
	char	*pos;

	sign = 0;
	result = 0;
	pos = nb;
	while (*pos == ' ' || *pos == '\t' || *pos == '\n' || *pos == '\v' ||
			*pos == '\f' || *pos == '\r')
		pos++;
	sign = (*pos == '-') ? -1 : 1;
	pos = (*pos == '+' || *pos == '-') ? pos + 1 : pos;
	while (*pos >= '0' && *pos <= '9')
		result = (result * 10) + (*pos++ - 48);
	return (result * sign);
}

void	ft_putnbr(int nb)
{
	unsigned int i;

	if (nb < 0)
	{
		i = nb * -1;
		ft_putchar('-');
	}
	else
		i = nb;
	if (i < 10)
	{
		ft_putchar(i + 48);
		return ;
	}
	ft_putnbr(i / 10);
	ft_putchar(i % 10 + 48);
}

void	fprime(int nb)
{
	int	prime;

	if (nb == 1)
		ft_putchar('1');
	while (1)
	{
		prime = 1;
		while (++prime <= nb)
		{
			if (nb % prime == 0)
			{
				ft_putnbr(prime);
				nb = nb / prime;
				break ;
			}
		}
		if (nb == 1)
			break ;
		else
			ft_putchar('*');
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		fprime(ft_atoi(av[1]));
	}
	ft_putchar('\n');
	return(0) ;
}
