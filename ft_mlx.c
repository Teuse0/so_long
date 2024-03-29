/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 23:34:20 by broy              #+#    #+#             */
/*   Updated: 2022/05/04 23:34:42 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_move_items(int x, int y, t_data *data)
{
	if (data->game->map[y][x] == 'O' &&
		data->game->map[data->game->p_y][data->game->p_x] != 'O')
	{
		ft_put_image(GRASS, data->game->p_x, data->game->p_y, data);
		return (ft_put_image(data->game->chest, x, y, data));
	}
	if (data->game->map[data->game->p_y][data->game->p_x] == 'O' &&
			data->game->map[y][x] == 'C')
	{
		ft_put_image(O_CHEST, data->game->p_x, data->game->p_y, data);
		data->game->map[y][x] = 'O';
		data->game->items -= 1;
		return (ft_put_image(data->game->chest, x, y, data));
	}
	if (data->game->map[y][x] == 'O' &&
			data->game->map[data->game->p_y][data->game->p_x] == 'O')
	{
		ft_put_image(O_CHEST, data->game->p_x, data->game->p_y, data);
		return (ft_put_image(data->game->chest, x, y, data));
	}
	ft_put_image(GRASS, data->game->p_x, data->game->p_y, data);
	ft_put_image(data->game->chest, x, y, data);
	data->game->map[y][x] = 'O';
	data->game->items -= 1;
}

static void	ft_move(int x, int y, t_data *data)
{	
	if (data->game->map[y][x] == '1')
		return ;
	else if (data->game->map[y][x] == 'E' && data->game->items != 0)
		return (ft_game_msg(data, 'k'));
	else if (data->game->map[y][x] == 'E' && data->game->items == 0)
	{
		ft_game_msg(data, 'e');
		ft_exit(data);
	}
	else if (data->game->map[y][x] == '0' || data->game->map[y][x] == 'P')
	{
		ft_put_image(data->game->player, x, y, data);
		ft_put_image(GRASS, data->game->p_x, data->game->p_y, data);
		if (data->game->map[data->game->p_y][data->game->p_x] == 'O')
			ft_put_image(O_CHEST, data->game->p_x, data->game->p_y, data);
	}
	else if (data->game->map[y][x] == 'C' || data->game->map[y][x] == 'O')
		ft_move_items(x, y, data);
	data->game->p_x = x;
	data->game->p_y = y;
	data->game->moves += 1;
	ft_print_moves(data);
}

void	ft_key_other(int key, t_data *data)
{
	if (key == A || key == LEFT)
	{
		data->game->chest = P_CHEST2;
		data->game->player = PLAYER_2;
	}
	else if (key == D || key == RIGHT)
	{
		data->game->chest = P_CHEST;
		data->game->player = PLAYER;
	}
	if (key == ESC || key == Q)
	{
		ft_game_msg(data, 'q');
		ft_exit(data);
	}
	return ;
}

int	ft_key(int key, t_data *data)
{
	int			x;
	int			y;

	x = data->game->p_x;
	y = data->game->p_y;
	if (data->game->items == 0)
		ft_put_image(EXIT_OPEN, data->game->exit[1], data->game->exit[0], data);
	ft_key_other(key, data);
	if (key == W || key == UP)
		ft_move(x, y - 1, data);
	else if (key == A || key == LEFT)
		ft_move(x - 1, y, data);
	else if (key == S || key == DOWN)
		ft_move(x, y + 1, data);
	else if (key == D || key == RIGHT)
		ft_move(x + 1, y, data);
	return (0);
}

void	ft_mlx(t_data *data)
{
	int	win_h;
	int	win_w;

	data->game->width = ft_strlen_nl(data->game->map[0]);
	win_h = data->game->height;
	win_w = data->game->width;
	data->mlx = mlx_init();
	if (data->mlx == (void *)0)
		ft_puterror_free("Error\n", data);
	data->mlx_win = mlx_new_window(data->mlx,
			win_w * ASSET_SIZE, win_h * ASSET_SIZE, GAME_NAME);
	if (data->mlx_win == (void *)0)
		ft_puterror_free("Error\n", data);
	ft_render(data);
	mlx_key_hook(data->mlx_win, ft_key, data);
	mlx_hook(data->mlx_win, 17, 0, ft_exit, data);
	mlx_loop(data->mlx);
}
