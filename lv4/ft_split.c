/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 14:59:11 by vafanass          #+#    #+#             */
/*   Updated: 2017/02/27 17:14:20 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		count_words(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
		}
	}
	return (count);
}

char			**ft_split(char *str)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(split = (char **)malloc(sizeof(char *) * (count_words(str) + 1))))
		return (split);
	while (str && str[i])
	{
		while (*str && (*str == ' ' || *str == '\t'))
			str++;
		if (*str)
		{
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
			split[j] = ft_strndup(str, i);
			j++;
			str = str + i;
			i = 0;
		}
	}
	split[j] = NULL;
	return (split);
}
