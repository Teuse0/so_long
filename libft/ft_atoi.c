/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:10:19 by broy              #+#    #+#             */
/*   Updated: 2022/04/06 17:26:28 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c)
{
	if (!((c >= 9 && c <= 13) || (c >= '0' && c <= '9')
			|| c == '+' || c == '-' || c == 32))
		return (0);
	return (1);
}

static int	ft_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

static long	ft_calcul(char c, long result)
{	
	result *= 10;
	result += c - 48;
	return (result);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	result;
	int		i;

	i = 0;
	result = 0;
	while (nptr[i] && !((nptr[i] >= '0' && nptr[i] <= '9')
			|| nptr[i] == '+' || nptr[i] == '-'))
	{
		if (!ft_check(nptr[i]))
			return (0);
		i++;
	}
	sign = ft_sign(nptr[i]);
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result = ft_calcul(nptr[i], result);
		i++;
	}
	result = result * sign;
	return (result);
}
