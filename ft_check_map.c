/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:19:01 by broy              #+#    #+#             */
/*   Updated: 2022/05/10 16:19:06 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_validate_file_ext(char *file)
{
	char	*dot;

	dot = NULL;
	dot = ft_strchr(file, '.');
	if (dot == NULL)
		return (0);
	if ((ft_strncmp(".ber", dot, 5)) == 0)
		return (1);
	return (0);
}

static int	ft_check_chars(t_data *data)
{
	int	h;
	int	w;

	h = 0;
	while (h < data->game->height)
	{
		w = 0;
		while (data->game->map[h][w] != '\n' &&
				data->game->map[h][w] != '\0')
		{
			if (ft_strchr(CHARS, data->game->map[h][w]) == NULL)
				return (0);
			w++;
		}
		h++;
	}
	return (1);
}

static int	ft_check_char(t_data *data, char ch, int *count)
{
	int	h;
	int	w;

	h = -1;
	*count = 0;
	while (++h < data->game->height)
	{
		w = 0;
		while (data->game->map[h][w] != '\0')
		{
			if (data->game->map[h][w] == ch)
				*count += 1;
			if (data->game->map[h][w] == 'E')
			{
				data->game->exit[0] = h;
				data->game->exit[1] = w;
			}
			w += 1;
		}
	}
	if ((ch == 'P' || ch == 'E') && *count > 1)
		return (2);
	else if (*count == 0)
		return (0);
	return (1);
}

static int	ft_check_every_char(t_data *data)
{
	int	count;

	if (!(ft_check_chars(data)))
		return (INVALID_CHARS);
	if (ft_check_char(data, 'P', &count) == 0)
		return (NO_PLAYER);
	if (ft_check_char(data, 'P', &count) > 1)
		return (PLAYER_ERROR);
	if (!(ft_check_char(data, 'E', &count)))
		return (EXIT_ERROR);
	if (ft_check_char(data, 'E', &count) > 1)
		return (M_EXIT);
	if (!(ft_check_char(data, 'C', &count)))
		return (COLLECT_ERROR);
	else
		data->game->items = count;
	return (VALID);
}

int	ft_validate_map(t_data *data)
{
	int		h;
	int		w;
	size_t	len;
	int		out;

	len = ft_strlen_nl(data->game->map[0]);
	h = 0;
	while (h < data->game->height)
	{
		if (len != (ft_strlen_nl(data->game->map[h])))
			return (INVALID_RECT);
		h++;
	}
	data->game->width = (int)len;
	if (!(ft_validate_walls(data, &h, &w, len)))
		return (INVALID_WALLS);
	out = ft_check_every_char(data);
	if (out > 0)
		return (out);
	return (VALID);
}
