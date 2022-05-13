/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:11:55 by broy              #+#    #+#             */
/*   Updated: 2022/03/31 17:27:36 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *chr, size_t len)
{
	size_t	i;
	size_t	j;

	if (chr[0] == 0)
		return ((char *)s);
	i = 0;
	while (s[i] && i < len)
	{
		j = 0;
		while (s[i + j] == chr[j] && (i + j) < len)
		{
			if (s[i + j] == 0 && chr[j] == 0)
				return ((char *)&s[i]);
			j++;
		}
		if (chr[j] == 0)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
