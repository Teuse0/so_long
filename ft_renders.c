/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renders.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:27:55 by broy              #+#    #+#             */
/*   Updated: 2022/05/09 14:28:23 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image(char *img, int x, int y, t_data *data)
{
	int	w;
	int	h;

	x *= ASSET_SIZE;
	y *= ASSET_SIZE;
	data->mlx_img = mlx_xpm_file_to_image(data->mlx, img, &w, &h);
	if (data->mlx_img == (void *)0)
		ft_puterror_free("Error\nMlx image not found\n", data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, x, y);
	mlx_destroy_image(data->mlx, data->mlx_img);
}

void	ft_draw_walls(int x, int y, t_data *data)
{
	if (x == 0 && y == 0)
		ft_put_image(WALL_TLC, x, y, data);
	else if (x == 0 && y == data->game->height - 1)
		ft_put_image(WALL_BLC, x, y, data);
	else if (y == 0 && x == data->game->width - 1)
		ft_put_image(WALL_TRC, x, y, data);
	else if (y == data->game->height - 1 && x == data->game->width - 1)
		ft_put_image(WALL_BRC, x, y, data);
	else if (y == 0 && x > 0 && x < data->game->width - 1)
		ft_put_image(WALL_H, x, y, data);
	else if (y > 0 && y < data->game->height - 1 && x == 0)
		ft_put_image(WALL_V, x, y, data);
	else if (y == data->game->height - 1 && x > 0 && x < data->game->width - 1)
		ft_put_image(WALL_H, x, y, data);
	else if (x == data->game->width - 1 && y > 0 && y < data->game->height - 1)
		ft_put_image(WALL_V, x, y, data);
	else
		ft_put_image(OBST, x, y, data);
}

void	ft_draw_map(int x, int y, char ch, t_data *data)
{
	if (ch == '0')
		ft_put_image(GRASS, x, y, data);
	else if (ch == '1')
		ft_draw_walls(x, y, data);
	else if (ch == 'C')
		ft_put_image(CHEST, x, y, data);
	else if (ch == 'P')
	{
		data->game->p_x = x;
		data->game->p_y = y;
		ft_put_image(PLAYER, x, y, data);
	}
	else if (ch == 'E')
		ft_put_image(EXIT_CLOSE, x, y, data);
}

void	ft_render(t_data *data)
{
	int		x;
	int		y;
	char	ch;

	mlx_clear_window(data->mlx, data->mlx_win);
	y = 0;
	while (y < data->game->height)
	{
		x = 0;
		while (x < data->game->width)
		{
			ch = data->game->map[y][x];
			ft_draw_map(x, y, ch, data);
			x++;
		}
		y++;
	}
}
