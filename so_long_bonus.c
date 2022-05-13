/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:30:33 by broy              #+#    #+#             */
/*   Updated: 2022/05/02 14:30:44 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		ft_puterror("Too few arguments\n");
	if (argc > 2)
		ft_puterror("Too many arguments\n");
	ft_bzero(&data, sizeof(t_data));
	data.game = malloc(sizeof(t_game));
	if (!data.game)
		ft_puterror("Error\nMemory malloc");
	ft_init_game(data.game);
	ft_read_map(&data, argv[1]);
	ft_mlx(&data);
	ft_exit(&data);
	return (0);
}
