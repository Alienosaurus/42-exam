#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int i;
	int c;

	i = 128;
	while (i > 0)
	{
		if (octet < i)
		{
			c = '0';
			i = i / 2;
			write(1, &c, 1);
		}
		else
		{
			c = '1';
			write(1, &c, 1);
			octet = octet - 1;
			i = i / 2;
		}
	}
}
