/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:51:00 by broy              #+#    #+#             */
/*   Updated: 2022/04/05 17:17:03 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	len2;

	len = 0;
	len2 = 0;
	i = 0;
	j = 0;
	len = ft_strlen(dst);
	j = len;
	len2 = ft_strlen(src);
	if (size < len)
		return (len2 + size);
	if (size == 0)
		return (len + len2);
	while (src[i] && i + j < size - 1)
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = 0;
	return (len + len2);
}
