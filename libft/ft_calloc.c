/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:25:59 by broy              #+#    #+#             */
/*   Updated: 2022/04/12 12:40:57 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*calloc;

	if (nmemb > 4294967295 || size > 4294967295)
		return (NULL);
	calloc = malloc(size * nmemb);
	if (!calloc)
		return (NULL);
	ft_bzero(calloc, size * nmemb);
	return (calloc);
}
