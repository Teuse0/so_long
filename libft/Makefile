# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: broy <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 20:21:36 by broy              #+#    #+#              #
#    Updated: 2022/05/09 20:42:43 by broy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   libft.a
SRCS    =   ft_atoi.c       ft_bzero.c      ft_isalnum.c    ft_isalpha.c\
			ft_isascii.c    ft_isdigit.c    ft_isprint.c    ft_memset.c\
            ft_strchr.c     ft_strdup.c     ft_strjoin.c    ft_strlen.c\
            ft_strncmp.c    ft_strrchr.c    ft_substr.c     ft_tolower.c\
            ft_toupper.c	ft_memcpy.c		ft_strlcpy.c	ft_strlcat.c\
			ft_strnstr.c	ft_memchr.c		ft_memcmp.c		ft_memmove.c\
			ft_calloc.c		ft_itoa.c		ft_putchar_fd.c	ft_putstr_fd.c\
			ft_putnbr_fd.c	ft_putendl_fd.c	ft_strtrim.c	ft_strmapi.c\
			ft_split.c		ft_striteri.c   		

SRCSB	=	ft_lstnew.c		ft_lstsize.c	ft_lstadd_front.c	ft_lstlast.c\
			ft_lstadd_back.c	ft_lstdelone.c	ft_lstclear.c	ft_lstiter.c\
			ft_lstmap.c
OBJS    =   ${SRCS:.c=.o}
OBJSB	=	${SRCSB:.c=.o}
RM      =   rm -f
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
			
.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS} 
			ranlib ${NAME}
all:		${NAME}
clean:
			${RM} ${OBJS} ${OBJSB}
fclean:		clean
			${RM} ${NAME} 
bonus:		${NAME} ${OBJSB}
			ar rc ${NAME} ${OBJSB}
			ranlib ${NAME}
re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus

