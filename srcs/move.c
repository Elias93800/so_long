/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 00:46:39 by emehdaou          #+#    #+#             */
/*   Updated: 2024/01/31 01:57:09 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    ft_move(t_map *map, int keycode)
{
    //droite 65363
    if (keycode == 65363 && map->player.x + 1 != 1)
    {
        map->tab[map->player.y][map->player.x] = '0';
        map->player.x++;
        map->tab[map->player.y][map->player.x] = 'P';
    }
    //gauche 65361
    if (keycode == 65361 && map->player.x - 1 != 1)
    {
        map->tab[map->player.y][map->player.x] = '0';
        map->player.x--;
        map->tab[map->player.y][map->player.x] = 'P';
    }
    //bas 65364
    if (keycode == 65364 && map->player.y + 1 != 1)
    {
        map->tab[map->player.y][map->player.x] = '0';
        map->player.y++;
        map->tab[map->player.y][map->player.x] = 'P';
    }
    //haur 65362
    if (keycode == 65362 && map->player.y - 1 != 1)
    {
        map->tab[map->player.y][map->player.x] = '0';
        map->player.y++;
        map->tab[map->player.y][map->player.x] = 'P';
    }
}
