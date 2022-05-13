/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:35:03 by broy              #+#    #+#             */
/*   Updated: 2022/03/31 14:45:31 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (!s2 && !s1)
		return (NULL);
	i = -1;
	j = ft_strlen(s1);
	k = ft_strlen(s2);
	str = malloc(j + k + 1);
	if (!str)
		return (NULL);
	while (++i < j)
		str[i] = s1[i];
	i = 0;
	while (i < k)
	{
		str[i + j] = s2[i];
		i++;
	}
	str[i + j] = 0;
	return (str);
}
