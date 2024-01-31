/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:07:18 by emehdaou          #+#    #+#             */
/*   Updated: 2024/01/30 22:27:49 by emehdaou         ###   ########.fr       */
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

int	check_rectangle(t_map *map)
{
	size_t	size;

	map->length = 0;
	map->height = 0;
	size = ft_strlen(map->tab[0]);
	while (map->tab[map->length])
	{
		if (size != ft_strlen(map->tab[map->length]))
			return (0);
		if ((map->tab[map->length][0] != '1') || (map->tab[map->length++][size
				- 1] != '1'))
			return (0);
		map->height++;
	}
	map->length = 0;
	while (map->tab[0][map->length])
		if (map->tab[0][map->length++] != '1')
			return (0);
	map->length = 0;
	while (map->tab[map->height - 1][map->length])
		if (map->tab[map->height - 1][map->length++] != '1')
			return (0);
	return (1);
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

void	get_index(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (map->tab[i][j] == 'P')
			{
				map->player.y = i;
				map->player.x = j;
			}
			if (map->tab[i][j] == 'E')
			{
				map->exit.y = i;
				map->exit.x = j;
			}
			j++;
		}
		i++;
	}
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		printf("%s\n", tab[i++]);
}

int	parse(t_map *map, int fd)
{
	char	*str;
	t_map	tmp;

	str = recup_gnl(fd);
	if (!close(fd) && !str)
		return (free(str), 0);
	if (check_newline(str))
		return (free(str), 0);
	map->tab = ft_split(str, '\n');
	if (!check_rectangle(map))
		return (free_tab(map->tab), free(str), 0);
	if (!check_col(map->tab))
		return (free_tab(map->tab), free(str), 0);
	tmp.tab = ft_split(str, '\n');
	free(str);
	get_index(map);
	tmp.player.x = map->player.x;
	tmp.player.y = map->player.y;
	tmp.exit.x = map->exit.x;
	tmp.exit.y = map->exit.y;
	backtrack(&tmp, tmp.player.x, tmp.player.y);
	if (check_tab(&tmp))
		return (free_tab(tmp.tab), free_tab(map->tab), 0);
	return (free_tab(tmp.tab), 1);
}
