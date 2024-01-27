/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:07:18 by emehdaou          #+#    #+#             */
/*   Updated: 2024/01/27 01:22:40 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i + 1] && str[i] == '\n' && str[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	check_rectangle(char **tab)
{
	int		i;
	int		cnt;
	size_t	size;

	i = 0;
	cnt = 0;
	size = ft_strlen(tab[0]);
	while (tab[i])
	{
		if (size != ft_strlen(tab[i]))
			return (1);
		if ((tab[i][0] != '1') || (tab[i++][size - 1] != '1'))
			return (2);
		cnt++;
	}
	i = 0;
	while (tab[0][i])
		if (tab[0][i++] != '1')
			return (4);
	i = 0;
	while (tab[cnt - 1][i])
		if (tab[cnt - 1][i++] != '1')
			return (5);
	return (0);
}

int	check_col(char **tab)
{
	int			i;
	int			j;
	static int	tmp[33] = {0};

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!ft_strchr("01CEP", tab[i][j]))
				return (0);
			tmp[ft_strchr("01CEP", tab[i][j])[0] - 48]++;
			j++;
		}
		i++;
	}
	if ((tmp['E' - 48] != 1) || (tmp['P' - 48] != 1) || (tmp['C' - 48] < 1))
		return (0);
	return (1);
}

int	*get_index(char **tab)
{
	int			i;
	int			j;
	static int	index[4] = {0};

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'P')
			{
				index[0] = i;
				index[1] = j;
			}
			if (tab[i][j] == 'E')
			{
				index[2] = i;
				index[3] = j;
			}
			j++;
		}
		i++;
	}
	return (index);
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		printf("%s\n", tab[i++]);
}

int	parse(int fd)
{
	char	**tab;
	char	*str;
	int		*index;
	char	**tmp;

	str = recup_gnl(fd);
	if (!str)
		return (free(str), 1);
	printf("[%p]\n", str);
	if (check_newline(str))
		return (free(str), 2);
	tab = ft_split(str, '\n');
	if (check_rectangle(tab))
		return (free_tab(tab), free(str), 3);
	if (!check_col(tab))
		return (free_tab(tab), free(str), 4);
	tmp = ft_split(str, '\n');
	free(str);
	index = get_index(tab);
	backtrack(tmp, index, index[1], index[0]);
	if (check_tab(tmp, index))
		return (free_tab(tmp), free_tab(tab), 5);
	return (free_tab(tmp), free_tab(tab), 0);
}

int	main(void)
{
	int	fd;

	fd = open("maps/map.ber", O_RDWR);
	printf("%d\n", parse(fd));
	close(fd);
}
