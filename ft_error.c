/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:07:05 by broy              #+#    #+#             */
/*   Updated: 2022/05/09 22:07:10 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_puterror_free(char *error, t_data *data)
{
	ft_free_split(data);
	free(data->game);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(BREAK, 2);
	exit(EXIT_FAILURE);
}

void	ft_display_error(int e, t_data *data)
{
	if (e == INVALID_RECT)
		ft_puterror_free("Error\nMap is not rectangular\n", data);
	else if (e == INVALID_WALLS)
		ft_puterror_free("Error\nInvalid walls\n", data);
	else if (e == INVALID_CHARS)
		ft_puterror_free("Error\nMap has invalid characters\n", data);
	else if (e == PLAYER_ERROR)
		ft_puterror_free("Error\nMultiple players\n", data);
	else if (e == EXIT_ERROR)
		ft_puterror_free("Error\nMap has no exit\n", data);
	else if (e == COLLECT_ERROR)
		ft_puterror_free("Error\nMap has no collectibles\n", data);
	else if (e == NO_PLAYER)
		ft_puterror_free("Error\nNo player\n", data);
	else if (e == M_EXIT)
		ft_puterror_free("Error\nMultiple exit\n", data);
}

void	ft_puterror(char *error)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(BREAK, 2);
	exit(EXIT_FAILURE);
}
