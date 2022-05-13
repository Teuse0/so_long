/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:03:55 by broy              #+#    #+#             */
/*   Updated: 2022/04/05 20:24:48 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*dest2;
	char	*src2;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dest2 = (char *)dest;
	src2 = (char *)src;
	if (dest2 > src2)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			dest2[i] = src2[i];
			i--;
		}
		return (dest2);
	}
	while (i < (int)n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest2);
}
