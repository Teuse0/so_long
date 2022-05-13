/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:56:44 by broy              #+#    #+#             */
/*   Updated: 2022/04/11 12:26:36 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *s, char c)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	j = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i] != c && j == 0)
		{
			j = 1;
			ret++;
		}
		else if (s[i] == c)
			j = 0;
		i++;
	}
	return (ret);
}

static char	*ft_makeword(const char *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char		**str;
	size_t		i;
	size_t		j;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			str[j] = ft_makeword(s + i, c);
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	str[j] = NULL;
	return (str);
}
