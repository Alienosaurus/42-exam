#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_dec(char i)
{
	if (i < 32 || i > 126)
		ft_putchar('.');
	else
		ft_putchar(i);
}

void	print_hex(unsigned char n)
{
	ft_putchar("0123456789abcdef"[n / 16]);
	ft_putchar("0123456789abcdef"[n % 16]);
}

void	print_memory(const void *addr, size_t size)
{
	size_t			i;
	int				tmp;
	unsigned char	*s;

	s = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		tmp = i;
		while ((i - tmp) < 16 && i < size)
		{
			print_hex(s[i]);
			i++;
			if (i % 2 == 0)
				ft_putchar(' ');
		}
		while ((i - tmp) < 16)
		{
			write(1, "  ", 2);
			i++;
			if (i % 2 == 0)
				ft_putchar(' ');
		}
		i = tmp;
		while ((i - tmp) < 16 && i < size)
		{
			print_dec(s[i]);
			i++;
		}
		ft_putchar('\n');
	}
}
