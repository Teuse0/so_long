/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:56:11 by broy              #+#    #+#             */
/*   Updated: 2022/05/02 16:57:53 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx_int.h"
# include "minilibx-linux/mlx.h"

# define CHARS "01CEP"
# define GAME_NAME "><> |SO_LONG| <><"

/*ERRORS*/

# define VALID		0
# define INVALID_RECT	3 
# define INVALID_WALLS	4
# define INVALID_CHARS	5
# define PLAYER_ERROR	6
# define EXIT_ERROR	7
# define COLLECT_ERROR	8
# define NO_PLAYER	9
# define M_EXIT	10

/*KEYS*/

# define Q	113
# define ESC	65307
# define W	119
# define A	97
# define S	115
# define D	100
# define LEFT	65361
# define RIGHT	65363
# define DOWN	65364
# define UP	65362

/*ASSESTS*/

# define ASSET_SIZE 48

# define CHEST		"assets/chest.xpm"
# define O_CHEST	"assets/open_chest.xpm"

# define GRASS		"assets/grass.xpm"

# define P
# define PLAYER	"assets/player.xpm"
# define PLAYER_2	"assets/player2.xpm"

# define OBST		"assets/solofence.xpm"
# define WALL_TLC	"assets/tl_fence.xpm"
# define WALL_TRC	"assets/tr_fence.xpm"
# define WALL_BLC	"assets/bl_fence.xpm"
# define WALL_BRC	"assets/br_fence.xpm"
# define WALL_V	"assets/v_fence.xpm"
# define WALL_H	"assets/fence.xpm"
# define EXIT_CLOSE	"assets/exit_close.xpm"
# define EXIT_OPEN	"assets/exit_open.xpm" 
# define P_CHEST	"assets/chest_player.xpm"
# define P_CHEST2	"assets/chest_player2.xpm"

/*COLORS*/

# define RED	"\033[0;31m"
# define YELLOW	"\033[0;33m"
# define BREAK	"\033[0m"

typedef struct s_game
{
	char		*player;
	int			exit[2];
	char		**map;
	int			width;
	int			height;
	int			p_x;
	int			p_y;
	int			moves;
	int			items;
	char		*chest;
}			t_game;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*mlx_img;
	t_game		*game;
}			t_data;

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_free(char *save, char *buffer);
char	*ft_strjoin(const char *s1, const char *s2);
void	ft_init_game(t_game *game);
void	ft_bzero(void *s, size_t n);
int		ft_read_map(t_data *data, char *file);
char	*ft_strdup(const char *s);
void	ft_mlx(t_data *data);
size_t	ft_strlen_nl(char *s);
void	ft_render(t_data *data);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_put_image(char *img, int x, int y, t_data *data);
int		ft_exit(t_data *data);
void	ft_print_moves(t_data *data);
void	ft_game_msg(t_data *data, char c);
void	ft_free_split(t_data *data);
void	ft_puterror(char *error);
void	ft_puterror_free(char *error, t_data *data);
int		ft_validate_map(t_data *data);
void	ft_display_error(int e, t_data *data);
int		ft_validate_walls(t_data *data, int *h, int *w, int len);
int		ft_validate_file_ext(char *file);

#endif
