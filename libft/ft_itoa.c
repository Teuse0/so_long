/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:03:21 by broy              #+#    #+#             */
/*   Updated: 2022/04/02 15:57:17 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intsize(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static long	ft_intneg(char *str, long n2)
{
	str[0] = '-';
	n2 = n2 * -1;
	return (n2);
}

static void	ft_crstr(long n2, int i, char *str)
{
	str[i] = 0;
	if (n2 == 0)
		str[0] = '0';
	while (n2 != 0)
	{
		i--;
		str[i] = n2 % 10 + 48;
		n2 = n2 / 10;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*str;
	int		k;
	long	n2;

	if (n == 0)
	{
		str = malloc(2);
		ft_crstr(0, 1, str);
		return (str);
	}
	k = 0;
	if (n < 0)
		k = 1;
	j = ft_intsize(n);
	str = malloc(j + k + 1);
	if (!str)
		return (NULL);
	i = j + k;
	n2 = n;
	if (k == 1)
		n2 = ft_intneg(str, n2);
	ft_crstr(n2, i, str);
	return (str);
}
