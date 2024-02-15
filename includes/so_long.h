/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:21:03 by emehdaou          #+#    #+#             */
/*   Updated: 2024/02/15 10:35:35 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ERR "Map must be valid"

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_map
{
	char	**tab;
	t_pos	player;
	t_pos	exit;
	void	*mlx;
	void	*win;
	int		length;
	int		height;
	int		col;
	int		lock;
	int		finish;
	int		cnt;
	char	*img[81];
}			t_map;

void		backtrack(t_map *map, int x, int y);
void		print_tab(char **tab);
int			check_exit(t_map *map);
int			is_ber(char *str);
void		ft_move(t_map *map, int keycode);
int			parse(t_map *map, int fd);
int			ft_close(t_map *map, int i);
void		copy_tab(t_map *map, t_map *tmp);
void		ft_view(t_map *map, void *mlx, void *mlx_win);

#endif