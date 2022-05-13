/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:42:15 by broy              #+#    #+#             */
/*   Updated: 2022/04/02 18:48:06 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	nbc[10];
	long	nbn;
	int		i;

	if (n == 0)
		ft_putchar('0', fd);
	if (n < 0)
	{
		ft_putchar('-', fd);
		nbn = n;
		nbn = -nbn;
	}
	else
		nbn = n;
	i = 0;
	while (nbn > 0)
	{
		nbc[i] = nbn % 10 + 48;
		nbn = nbn / 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar(nbc[i], fd);
}
