typedef struct	s_chess
{
	char	**board;
	int		kingx;
	int		kingy;
	int		base_len;
	int		curpx;
	int		curpy;
}				t_chess;

int     ft_strlen(char *str);
void ft_putchar(char c);
void    ft_putstr(char *str);
void    print_array(char **array, int nb);
int     check_king(t_chess c);
int     find_piece(t_chess c);
void    king_coord(t_chess *c);
