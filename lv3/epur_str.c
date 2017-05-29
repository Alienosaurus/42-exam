#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;
	char *arg;

	if (argc == 2)
	{
		i = -1;
		arg = argv[1];
		while (*arg)
		{
			while (*arg == ' ' || *arg == '\t')
				arg++;
			if (i != -1 && *arg != '\0')
				write(1, " ", 1);
			i = 0;
			while (arg[i] && arg[i] != " " && arg[i] != '\t')
				i++;
			write(1, arg, i);
			arg += i;
		}
	}
	write(1, "\n", 1);
	return (0);
}
