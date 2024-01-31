/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:54:01 by emehdaou          #+#    #+#             */
/*   Updated: 2024/01/30 22:57:40 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_tab(t_map *map)
{
	int	i;

	i = 0;
	if (map->tab[map->exit.y - 1][map->exit.x] != '2'
		&& map->tab[map->exit.y][map->exit.x - 1] != '2' && map->tab[map->exit.y
		+ 1][map->exit.x] != '2' && map->tab[map->exit.y][map->exit.x
		+ 1] != '2')
		return (1);
	while (map->tab[i])
		if (ft_strchr(map->tab[i++], 'C'))
			return (2);
	return (0);
}
void	backtrack(t_map *map, int x, int y)
{
	print_tab(map->tab);
	printf("x = %i, y = %i\n", x, y);
	if (map->tab[y][x] == '1' || map->tab[y][x] == '2')
		return ;
	if (map->tab[y][x] != '1' && map->tab[y][x] != 'E')
		map->tab[y][x] = '2';
	if (!check_tab(map))
		return ;
	backtrack(map, x + 1, y);
	backtrack(map, x, y + 1);
	backtrack(map, x - 1, y);
	backtrack(map, x, y - 1);
	return ;
}

int	is_ber(char *str)
{
	char *var = ft_strchr(str, '.');
	if (var)
		return (ft_strcmp(var, ".ber"));
	return (92100);
}