#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if(nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar('0' + (nb % 10));
}

int	main(int ac, char **av)
{
	(void)av;
	ft_putnbr(ac - 1);
	ft_putchar('\n');
	return(0);
}
