/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dead_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:12:28 by broy              #+#    #+#             */
/*   Updated: 2022/05/10 20:12:29 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_dead_player(int x, int y, t_data *data)
{
	int	w;
	int	h;

	data->game->end = 1;
	ft_put_image(DEAD, data->game->p_x, data->game->p_y, data);
	ft_put_image(ENNEMY2, x, y, data);
	mlx_clear_window(data->mlx, data->mlx_win);
	data->mlx_img = mlx_xpm_file_to_image(data->mlx,
			"assets/gameover.xpm", &w, &h);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, x, y);
	mlx_destroy_image(data->mlx, data->mlx_img);
	mlx_string_put(data->mlx, data->mlx_win,
		 2, 35, 16581375, "Press Esc to quit game");
}
