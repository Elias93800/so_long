/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:33:10 by emehdaou          #+#    #+#             */
/*   Updated: 2024/01/27 01:23:10 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	if (!s2)
		return (NULL);
	if (!s1)
		res = ft_calloc(1, ft_strlen(s2) + 1);
	else
		res = ft_calloc(1, ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
			res[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		res[j++] = s2[i++];
	}
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	res[j] = '\0';
	return (res);
}
// int main()
// {
//     ft_strjoin("asd", "dsa");
// }