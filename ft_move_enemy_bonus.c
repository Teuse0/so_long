/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ennemy_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:51:51 by broy              #+#    #+#             */
/*   Updated: 2022/05/12 16:51:57 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_top(int x, int y, t_data *data)
{
	y = y - 1;
	if (data->game->map[y][x] == '1' || data->game->map[y][x] == 'O' ||
			data->game->map[y][x] == 'E' || data->game->map[y][x] == 'C')
		return (1);
	return (0);
}

int	ft_bottom(int x, int y, t_data *data)
{
	y = y + 1;
	if (data->game->map[y][x] == '1' || data->game->map[y][x] == 'O' ||
			data->game->map[y][x] == 'E' || data->game->map[y][x] == 'C')
		return (1);
	return (0);
}

void	ft_move_enemy(t_data *data, int x, int y, int i)
{
	if (!ft_bottom(x, y, data) && data->game->e_pos[i][0] == 0)
	{
		ft_put_image(GRASS, x, y, data);
		ft_put_image(ENNEMY, x, y + 1, data);
		data->game->map[y][x] = '0';
		data->game->map[y + 1][x] = 'V';
		data->game->enemy[i][0] = y + 1;
	}
	else
		data->game->e_pos[i][0] = 1;
	if (!ft_top(x, y, data) && data->game->e_pos[i][0] == 1)
	{
		ft_put_image(GRASS, x, y, data);
		ft_put_image(ENNEMY, x, y - 1, data);
		data->game->map[y][x] = '0';
		data->game->map[y - 1][x] = 'V';
		data->game->enemy[i][0] = y - 1;
	}
	else
		data->game->e_pos[i][0] = 0;
}

void	ft_enemy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->game->nbr_enemy)
	{
		ft_move_enemy(data, data->game->enemy[i][1],
			data->game->enemy[i][0], i);
		i++;
	}
}

void	check_map_ennemy(t_data *data)
{
	int	h;
	int	w;
	int	i;

	i = 0;
	h = -1;
	while (++h < data->game->height)
	{
		w = 0;
		while (data->game->map[h][w] != '\0')
		{
			if (data->game->map[h][w] == 'V')
			{
				data->game->nbr_enemy = data->game->nbr_enemy + 1;
				if (data->game->nbr_enemy > 20)
					ft_display_error('v', data);
				data->game->enemy[i][0] = h;
				data->game->enemy[i][1] = w;
				i++;
			}
			w++;
		}
	}
}
