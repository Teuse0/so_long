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

#include "so_long_bonus.h"

void	ft_enemy_or_grass(t_data *data, int x, int y)
{
	if ((data->game->map[data->game->p_y][data->game->p_x] == 'V') &&
		data->game->end == 0)
		ft_put_image(ENNEMY, data->game->p_x, data->game->p_y, data);
	else
		ft_put_image(GRASS, data->game->p_x, data->game->p_y, data);
	ft_put_image(data->game->player, x, y, data);
}

void	ft_gg(int x, int y, t_data *data)
{
	int	w;
	int	h;

	mlx_clear_window(data->mlx, data->mlx_win);
	data->mlx_img = mlx_xpm_file_to_image(data->mlx,
			"assets/gg.xpm", &w, &h);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, x, y);
	mlx_destroy_image(data->mlx, data->mlx_img);
	mlx_string_put(data->mlx, data->mlx_win,
		 2, 35, 16581375, "Press Esc to quit game");
}

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
	char	*str;

	str = ft_itoa(data->game->moves);
	if (data->game->end == 0)
	{
		ft_put_image(WALL_TLC, 0, 0, data);
		ft_put_image(WALL_H, 1, 0, data);
	}
	mlx_string_put(data->mlx, data->mlx_win, 2, 20, 16777215, "You made ");
	mlx_string_put(data->mlx, data->mlx_win, 52, 20, 16777215, str);
	if (data->game->moves == 1)
		mlx_string_put(data->mlx, data->mlx_win, 56, 20, 0xFFFFFF, "move");
	else if (data->game->moves < 10)
		mlx_string_put(data->mlx, data->mlx_win, 61, 20, 16777215, "moves");
	else if (data->game->moves < 100)
		mlx_string_put(data->mlx, data->mlx_win, 66, 20, 16777215, "moves");
	else if (data->game->moves < 1000)
		mlx_string_put(data->mlx, data->mlx_win, 71, 20, 16777215, "moves");
	else
		mlx_string_put(data->mlx, data->mlx_win, 76, 20, 16777215, "moves");
	free(str);
	str = NULL;
}
