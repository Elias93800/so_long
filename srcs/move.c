/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 00:46:39 by emehdaou          #+#    #+#             */
/*   Updated: 2024/02/03 15:50:45 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"

void	ft_move(t_map *map, int keycode)
{
	if (keycode == 65363 && map->tab[map->player.y][map->player.x + 1] != '1'
		&& !(map->tab[map->player.y][map->player.x + 1] == 'E'
			&& map->lock == 1))
		map->tab[map->player.y][map->player.x++] = '0';
	if (keycode == 65361 && map->tab[map->player.y][map->player.x - 1] != '1'
		&& !(map->tab[map->player.y][map->player.x - 1] == 'E'
			&& map->lock == 1))
		map->tab[map->player.y][map->player.x--] = '0';
	if (keycode == 65364 && map->tab[map->player.y + 1][map->player.x] != '1'
		&& !(map->tab[map->player.y + 1][map->player.x] == 'E'
			&& map->lock == 1))
		map->tab[map->player.y++][map->player.x] = '0';
	if (keycode == 65362 && map->tab[map->player.y - 1][map->player.x] != '1'
		&& !(map->tab[map->player.y - 1][map->player.x] == 'E'
			&& map->lock == 1))
		map->tab[map->player.y--][map->player.x] = '0';
	if (map->tab[map->player.y][map->player.x] == 'C')
		map->col--;
	if (map->col == 0)
		map->lock = 0;
	if (map->tab[map->player.y][map->player.x] == 'E' && map->lock == 0)
		map->finish = 1;
	map->tab[map->player.y][map->player.x] = 'P';
}

int	ft_close(t_map *map, int i)
{
	char	*str;
	
	free_tab(map->tab);
	str = "10ECP";
	while (i > 0)
	{
		mlx_destroy_image(map->mlx, map->img[(int)str[i - 1]]);
		i--;
	}
	mlx_clear_window(map->mlx, map->win);
	mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	exit(0);
}
