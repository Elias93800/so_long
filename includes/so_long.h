/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:21:03 by emehdaou          #+#    #+#             */
/*   Updated: 2024/01/26 23:00:39 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BERERROR "Extension must be .ber"
# define RECERROR "Map must be rectangle"
# define CLOERROR "Map must be closed"

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"

typedef struct s_pos
{
    int x;
    int y;
}   t_pos;

typedef struct s_map
{
    t_pos C;
    t_pos E;
    t_pos P;
}   t_map;

void	backtrack(char **tab, int index[4], int x, int y);
void	print_tab(char **tab);
int		check_tab(char **tab, int index[4]);

#endif