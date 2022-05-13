/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:59:16 by broy              #+#    #+#             */
/*   Updated: 2022/05/09 19:59:18 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_msg(t_data *data, char c)
{
	ft_putstr_fd(YELLOW, 1);
	if (data->game->items != 0 && c == 'k')
	{
		ft_putstr_fd("Door is closed. Collect all chests : ", 1);
		ft_putnbr_fd(data->game->items, 1);
		ft_putstr_fd(" left\n", 1);
	}
	else if (c == 'q')
		ft_putstr_fd("Quit game            \n", 1);
	else if (data->game->items == 0 && c == 'e')
	{
		data->game->moves += 1;
		ft_putstr_fd("Congrats! You opened the door in ", 1);
		ft_putnbr_fd(data->game->moves, 1);
		if (data->game->moves == 1)
			ft_putstr_fd(" move\n", 1);
		else
			ft_putstr_fd(" moves\n", 1);
	}
	ft_putstr_fd(BREAK, 1);
}

void	ft_print_moves(t_data *data)
{
	ft_putstr_fd(YELLOW, 1);
	ft_putstr_fd("You made ", 1);
	ft_putnbr_fd(data->game->moves, 1);
	if (data->game->moves == 1)
		ft_putstr_fd(" move\r", 1);
	else
		ft_putstr_fd(" moves\r", 1);
	ft_putstr_fd(BREAK, 1);
}
