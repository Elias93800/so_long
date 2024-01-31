/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/01/31 02:00:09 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/so_long.h"
#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"

void	ft_view(t_map *map, void *mlx, void *mlx_win)
{
	int			i;
	int			j;
	void		*img;
	int			r;
	static char	*text['P' + 1] = {
	['1'] = "s/brick.xpm",
	['0'] = "s/stone.xpm",
	['E'] = "s/door3.xpm",
	['C'] = "s/jmleft.xpm",
	['P'] = "s/mgamil.xpm",
	};

	i = 0;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			img = mlx_xpm_file_to_image(mlx, text[(int)map->tab[i][j]], &r, &r);
			mlx_put_image_to_window(mlx, mlx_win, img, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

int key_hook(int keycode, t_map *map)
{
	ft_move(map, keycode);
	printf("%i\n", keycode);
	return (0);
}



void	ft_game(t_map *map)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map->length * 64, map->height * 64, "binks");
	mlx_hook(mlx_win, 0, 1L << 0, key_hook, map);
	mlx_key_hook(mlx_win, key_hook, map);
	// printf("%i %i\n", map->player.x, map->player.y);
	ft_view(map, mlx, mlx_win);
	mlx_loop(mlx);
}

int	main(int ac, char **av)
{
	int		fd;
	t_map map;

	if (ac != 2 || is_ber(av[1]))
		return (1);
	fd = open(av[1], O_RDWR);
	if (!parse(&map, fd))
		return (0);
	ft_game(&map);
}
