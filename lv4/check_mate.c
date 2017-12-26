#include <unistd.h>
#include <stdlib.h>
#include "check_mate.h"

int		check_case(t_chess c, int x, int y)
{
	//printf("x = %d y = %d\n", x , y);
	if (x < 0 || x > c.base_len - 1)
		return(0);
	if (y < 0 || y > c.base_len - 1)
		return (0);
	if(c.board[y][x] == 'P' || c.board[y][x] == 'Q' || c.board[y][x] == 'R' || c.board[y][x] == 'B')
		return(1);
	return(0);
}

int		check_pawn(t_chess c)
{
	if(c.curpx - 1 == c.kingx && c.curpy - 1 == c.kingy)
		return(1);
	if(c.curpx + 1 == c.kingx && c.curpy - 1 == c.kingy)
		return (1);
	if(c.curpx + 1 == c.kingx && c.curpy + 1 == c.kingy)
		return (1);
	if(c.curpx - 1 == c.kingx && c.curpy + 1 == c.kingy)
		return (1);
	return (0);
}

int		check_rook(t_chess c)
{
	int i;

	i = c.curpy;
	while (i >= 0)
	{
		if (check_case(c, c.curpx, i))
								break ;
		if (c.curpx  == c.kingx && i == c.kingy)
			return (1);
		i--;
	}
	i = c.curpx;
	while (i >= 0)
	{
		if(check_case(c, i, c.curpy))
			break;
		if (i == c.kingx && c.curpy == c.kingy)
			return (1);
		i--;
	}
	i = c.curpy;
	while (i <= c.base_len)
	{
		if (check_case(c, c.curpx, i))
			break ;
		if (c.curpx  == c.kingx && i == c.kingy)
			return (1);
		i++;
	}
	i = c.curpx;
	while (i <= c.base_len)
	{
		if (check_case(c, i, c.curpy))
			break ;
		if (i == c.kingx && c.curpy == c.kingy)
			return (1);
		i++;
	}
	return (0);
}

int		check_bishop(t_chess c)
{
	int i;
	int	j;

	i = c.curpy;
	j = c.curpx;
	while (i - 1 >= 0 && j - 1 >= 0)
	{
		 //printf("i = %d, j = %d\n", i - 1, j - 1);
		if (check_case(c, j - 1, i - 1))
			break ;
		if(j - 1 == c.kingx && i - 1 == c.kingy)
			return (1);
		j--;
		i--;
	}
	i = c.curpy;
	j = c.curpx;
	while (i - 1>= 0 && j + 1 <= c.base_len)
	{
		 //printf("i = %d, j = %d\n", i - 1, j + 1);
		if (check_case(c, j - 1, i - 1))
			break ;
		if(j + 1 == c.kingx && i - 1 == c.kingy)
			return (1);
		j++;
		i--;
	}
	i = c.curpy;
	j = c.curpx;
	while (i + 1<= c.base_len && j + 1<= c.base_len)
	{
		 //printf("i = %d, j = %d\n", i + 1, j + 1);
		if (check_case(c, j + 1, i + 1))
			break ;
		if(j + 1 == c.kingx && i + 1 == c.kingy)
			return (1);
		i++;
		j++;
	}
	i = c.curpy;
	j = c.curpx;
	while (j - 1 >= 0 && i + 1 <= c.base_len)
	{
		 //printf("i = %d, j = %d\n", i + 1, j - 1);
		if (check_case(c, j - 1, i + 1))
			break ;
		if(j - 1 == c.kingx && i + 1 == c.kingy)
			return (1);
		j--;
		i++;
	}
	return (0);
}

int		check_queen(t_chess c)
{
	int	ok;
	if ((ok = check_pawn(c)))
		return (1);
	if ((ok = check_rook(c)))
		return (1);
	if ((ok = check_bishop(c)))
		return (1);
	return (0);
}
int		check_patern(t_chess c)
{
	int ok;
	int	i;
	int	j;

	king_coord(&c);
	i = 0;
	while ( i < c.base_len)
	{
		j = 0;
		while (j < c.base_len)
		{
			c.curpx = j;
			c.curpy = i;
			if (c.board[i][j] == 'P')
				if ((ok = check_pawn(c)))
					return(1);
			if (c.board[i][j] == 'R')
				if((ok = check_rook(c)))
					return(1);
			if (c.board[i][j] == 'B')
				if ((ok = check_bishop(c)))
					return (1);
			if (c.board[i][j] == 'Q')
				if ((ok = check_queen(c)))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}
int		main(int argc, char **argv)
{
	int		i;
	int		len;
	int		j;
	t_chess	c;

	if (argc < 2)
	{
		ft_putchar('\n');
		return (0);
	}

	i = 2;
	c.base_len = ft_strlen(argv[1]);

	if ((argc - 1) != c.base_len)
	{
		ft_putstr("Fail\n");
		return (0);
	}

	while (i <= argc - 1)
	{
		len = ft_strlen(argv[i]);
		if (len == c.base_len)
		{
			i++;
		}
		else
		{
			ft_putstr("Fail\n");
			return (0);
		}
	}

	c.board = malloc(sizeof(char**) * c.base_len);
	i = 0;
	while (i < c.base_len)
	{
		c.board[i] = malloc(sizeof(char*) * c.base_len);
		i++;
	}
	i = 0;
	while(i < c.base_len)
	{
		j = 0;
		while (j < c.base_len)
		{
			c.board[i][j] = argv[i + 1][j];
			j++;
		}
		i++;
	}
	if (!(check_king(c)))
	{
		ft_putstr("Fail\n");
		return (0);
	}
	if(!(find_piece(c)))
	{
		ft_putstr("Fail\n");
		return (0);
	}
	/*i = 0;
	while (i < c.base_len)
	{
		j = 0;
		while (j <c.base_len)
		{
			ft_putchar(c.board[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}*/
	if(check_patern(c))
	{
		ft_putstr("Success\n");
		return (0);
	}
	ft_putstr("Fail\n");

	i = 0;
	while (i < c.base_len)
	{
		free(c.board[i]);
		i++;
	}
	free(c.board);
	return (0);
}
