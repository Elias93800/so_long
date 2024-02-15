/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 04:04:11 by emehdaou          #+#    #+#             */
/*   Updated: 2024/02/15 10:55:08 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"

void	ft_init_img(t_map *map)
{
	int	r;

	map->img['1'] = (char *){mlx_xpm_file_to_image(map->mlx, "s/brick.xpm", &r,
			&r)};
	if (!map->img['1'])
		ft_close(map, 0);
	map->img['0'] = (char *){mlx_xpm_file_to_image(map->mlx, "s/stone.xpm", &r,
			&r)};
	if (!map->img['0'])
		ft_close(map, 1);
	map->img['E'] = (char *){mlx_xpm_file_to_image(map->mlx, "s/door3.xpm", &r,
			&r)};
	if (!map->img['E'])
		ft_close(map, 2);
	map->img['C'] = (char *){mlx_xpm_file_to_image(map->mlx, "s/jmleft.xpm", &r,
			&r)};
	if (!map->img['C'])
		ft_close(map, 3);
	map->img['P'] = (char *){mlx_xpm_file_to_image(map->mlx, "s/mgamil.xpm", &r,
			&r)};
	if (!map->img['P'])
		ft_close(map, 4);
}

void	ft_view(t_map *map, void *mlx, void *mlx_win)
{
	int	i;
	int	j;

	i = 0;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			mlx_put_image_to_window(mlx, mlx_win, map->img[(int)map->tab[i][j]],
				j * 64, i * 64);
			j++;
		}
		i++;
	}
}

int	key_hook(int keycode, t_map *map)
{
	t_pos tmp;

	tmp = map->player;	
	if (keycode == 65307)
		return (mlx_loop_end(map->mlx));
	if (keycode >= 65361 && keycode <= 65364)
	{
		ft_move(map, keycode);
		ft_view(map, map->mlx, map->win);
		if (map->player.x != tmp.x || map->player.y != tmp.y)
		{	
			map->cnt++;
			ft_printf("Score: %d\n", map->cnt);	
		}
	}
	if (map->finish)
		ft_close(map, 5);
	return (0);
}

void	ft_game(t_map *map)
{
	ft_view(map, map->mlx, map->win);
	mlx_hook(map->win, 0, 1L << 0, key_hook, map);
	mlx_key_hook(map->win, key_hook, map);
	mlx_hook(map->win, 17, 0, mlx_loop_end, map->mlx);
	mlx_loop(map->mlx);
}

int	main(int ac, char **av)
{
	int		fd;
	t_map	map;

	if (ac != 2 )
		return (1);
	fd = open(av[1], O_RDWR);
	if (fd == -1 || is_ber(av[1]))
		return (ft_printf("Error\nFile error\n"), 0);
	if (!parse(&map, fd))
		return (0);
	map.cnt = 0;
	map.lock = 1;
	map.finish = 0;
	map.mlx = mlx_init();
	if (!map.mlx)
		return (free_tab(map.tab), 0);
	map.win = mlx_new_window(map.mlx, map.length * 64, map.height * 64,
			"binks");
	ft_init_img(&map);
	ft_game(&map);
	ft_close(&map, 5);
}
