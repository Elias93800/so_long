/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:54:01 by emehdaou          #+#    #+#             */
/*   Updated: 2024/02/02 04:13:34 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_exit(t_map *map)
{
	int	i;

	i = 0;
	if (map->tab[map->exit.y - 1][map->exit.x] != '2'
		&& map->tab[map->exit.y][map->exit.x - 1] != '2' && map->tab[map->exit.y
		+ 1][map->exit.x] != '2' && map->tab[map->exit.y][map->exit.x
		+ 1] != '2')
		return (1);
	return (0);
}

void	backtrack(t_map *map, int x, int y)
{
	if (map->tab[y][x] == 'C')
		map->col--;
	if (map->tab[y][x] == '1' || map->tab[y][x] == '2' || map->tab[y][x] == 'E')
		return ;
	if (map->tab[y][x] != '1' && map->tab[y][x] != 'E')
		map->tab[y][x] = '2';
	if (!check_exit(map) && map->col == 0)
		return ;
	backtrack(map, x + 1, y);
	backtrack(map, x, y + 1);
	backtrack(map, x - 1, y);
	backtrack(map, x, y - 1);
	return ;
}

int	is_ber(char *str)
{
	char	*var;

	var = ft_strchr(str, '.');
	if (var)
		return (ft_strcmp(var, ".ber"));
	return (92100);
}

void	copy_tab(t_map *map, t_map *tmp)
{
	tmp->player.x = map->player.x;
	tmp->player.y = map->player.y;
	tmp->exit.x = map->exit.x;
	tmp->exit.y = map->exit.y;
	tmp->col = map->col;
}
