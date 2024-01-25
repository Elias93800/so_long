/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:07:18 by emehdaou          #+#    #+#             */
/*   Updated: 2024/01/25 20:45:28 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int check_newline(char *str)
{
	 int i;
	 
	 i = 0;
	 while (str[i])
	 {
		if (str[i + 1] && str[i] == '\n' && str[i + 1] == '\n')
			return (1);
		i++;
	 }
	 return (0);
}

int check_rectangle(char **tab)
{
	int i;
	int cnt;
	size_t size;

	i = 0;
	cnt = 0;
	size = ft_strlen(tab[0]);
	while(tab[i])
	{
		if (size != ft_strlen(tab[i]))
			return (1);
		if (tab[i][0] != 1 || tab[i++][size - 1] != 1)
			return (3);
		cnt++;
	}
	if (cnt == i)
		return (2);
	i = 0;
	while(tab[1][i])
		if (tab[1][i++] != 1)
			return (3);
	i = 0;
	while(tab[cnt][i])
		if (tab[cnt][i++] != 1)
			return (4);
	return (0);
}

int check_col(char **tab)
{
	int i;
	int j;
	int tmp[15];

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!ft_strchr("01CEP", tab[i][j]))
				return (1);
			tmp[ft_strchr("01CEP", tab[i][j])[0] - 67]++;
			j++;
		}
		i++;
	}
	if (tmp['E' - 67] != 1 || tmp['P' - 67] != 1 || tmp['C' - 67] < 1)
		return (2);
	return (0);
}

int	parse(int fd)
{
	char **tab;
	char *str;
	
	str = get_next_line(fd, 0);
	printf("str = %s", str);
	if (!str)
		return (1);
	get_next_line(123123, 1);
	if (!check_newline(str))
		return (2);
	tab = ft_split(str, '\n');
	if (check_rectangle(tab))
		return (3);
	if (check_col(tab))
		return (4);
	return (0);	
}

int main()
{
	int fd = open("../maps/map.ber", O_RDWR);
	printf("%d\n", parse(fd));
	close(fd);
}
