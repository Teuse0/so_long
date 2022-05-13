# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 20:07:15 by broy              #+#    #+#              #
#    Updated: 2022/05/13 15:11:19 by broy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

REMOVE		= rm -rf

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror
MINILIBX_FLAGS	= -lXext -lX11 

MINILIBX 	= minilibx-linux/libmlx.a
MINILIBX_2	= minilibx-linux/libmlx_Linux.a
MINILIBX_PATH = minilibx-linux
LIBFT 		= libft/libft.a
LIBFT_PATH	= libft

SOURCES		= 	so_long.c		\
				ft_get_map.c	\
				ft_mlx.c		\
				ft_renders.c	\
				ft_utils.c		\
				ft_utils_2.c	\
				ft_error.c		\
				ft_check_map.c	\
				ft_check_walls.c\
				get_next_line.c

SOURCES_B	=	so_long_bonus.c			\
				ft_get_map_bonus.c		\
				ft_mlx_bonus.c			\
				ft_renders_bonus.c		\
				ft_utils_bonus.c		\
				ft_utils_2_bonus.c		\
				ft_error_bonus.c		\
				ft_check_map_bonus.c	\
				ft_check_walls_bonus.c	\
				ft_dead_player_bonus.c	\
				get_next_line_bonus.c	\
				ft_move_enemy_bonus.c

OBJECTS		= $(SOURCES:.c=.o)

OBJECTS_B	= $(SOURCES_B:.c=.o)

all:	$(NAME)

${LIBFT}:
		make bonus -C ${LIBFT_PATH}
	
${MINILIBX}:
		make -C ${MINILIBX_PATH}

${NAME}:	${OBJECTS} ${LIBFT} ${MINILIBX}
		${CC} -o ${NAME} ${SOURCES} ${LIBFT} ${CFLAGS} ${MINILIBX} ${MINILIBX2} ${MINILIBX_FLAGS}

clean:
		make clean -C ${MINILIBX_PATH}
		make clean -C ${LIBFT_PATH}
		${REMOVE} ${OBJECTS} ${OBJECTS_B}

fclean:	
		make clean -C ${MINILIBX_PATH}
		make fclean -C ${LIBFT_PATH}
		${REMOVE} ${NAME} ${OBJECTS} ${OBJECTS_B}

bonus:	${OBJECTS_B} ${LIBFT} ${MINILIBX}
		${CC} ${OBJECTS_B} ${LIBFT} ${MINILIBX} ${MINILIBX_FLAGS} -o ${NAME}

re:		fclean all

.PHONY:		all clean fclean re bonus
