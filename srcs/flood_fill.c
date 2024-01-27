/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:54:01 by emehdaou          #+#    #+#             */
/*   Updated: 2024/01/27 01:04:57 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_tab(char **tab, int index[4])
{
	int	i;

	i = 0;
	if (tab[index[2] - 1][index[3]] != '2' && tab[index[2]][index[3] - 1] != '2'
		&& tab[index[2] + 1][index[3]] != '2' && tab[index[2]][index[3]
		+ 1] != '2')
		return (1);
	while (tab[i])
		if (ft_strchr(tab[i++], 'C'))
			return (2);
	return (0);
}
void	backtrack(char **tab, int index[4], int x, int y)
{
	if (!tab[y][x] || tab[y][x] == '1' || tab[y][x] == '2')
		return ;
	if (tab[y][x] != '1' && tab[y][x] != 'E')
		tab[y][x] = '2';
	print_tab(tab);
	if (!check_tab(tab, index))
		return ;
	backtrack(tab, index, x + 1, y);
	backtrack(tab, index, x, y + 1);
	backtrack(tab, index, x - 1, y);
	backtrack(tab, index, x, y - 1);
	return ;
}

