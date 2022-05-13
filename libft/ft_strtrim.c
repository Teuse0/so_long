/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:23:42 by broy              #+#    #+#             */
/*   Updated: 2022/04/05 14:26:53 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_testc(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (!s1)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_testc(set, s1[i]))
		i++;
	while (j > i && ft_testc(set, s1[j - 1]))
		j--;
	str = (char *)malloc(sizeof(*s1) * (j - i + 1));
	if (!str)
		return (NULL);
	k = 0;
	while (i < j)
	{
		str[k] = s1[i];
		i++;
		k++;
	}
	str[k] = 0;
	return (str);
}
