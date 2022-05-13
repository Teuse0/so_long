/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 23:09:17 by broy              #+#    #+#             */
/*   Updated: 2022/05/04 23:09:38 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_game(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 15)
		game->e_pos[i][0] = 1;
	game->nbr_enemy = 0;
	game->end = 0;
	game->chest = P_CHEST;
	game->player = PLAYER;
	game->width = 0;
	game->height = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->items = 0;
	game->moves = 0;
}

size_t	ft_strlen_nl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i++;
	}
	if (s[i] == c)
		return ((char *)(&s[i]));
	return (NULL);
}

void	ft_free_split(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->game->height)
	{
		free(data->game->map[i]);
		i++;
	}
	free(data->game->map);
	data->game->map = NULL;
}

int	ft_exit(t_data *data)
{
	ft_free_split(data);
	free(data->game);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}
