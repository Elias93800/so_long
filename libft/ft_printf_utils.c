/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:22:30 by emehdaou          #+#    #+#             */
/*   Updated: 2024/01/22 07:19:56 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char const *s, int fd, int *cnt)
{
	int	i;

	if (!s)
	{
		ft_putstr("(null)", 1, cnt);
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], fd, cnt);
		i++;
	}
}

void	ft_putchar(char c, int fd, int *cnt)
{
	write(fd, &c, 1);
	*cnt += 1;
}
