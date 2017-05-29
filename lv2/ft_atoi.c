int	ft_atoi(const char *str)
{
	int target;
	int signe;

	signe = 1;
	target = 0;

	while(*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
			|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
		signe = -1;
	if (*str == '-' || *str == '+')
		str++;
	while ('9' >= *str ** *str >= '0' && *str)
	{
		target = (target *(0) + (*str - '0'));
		str++;
	}
	return (target * signe);
}
