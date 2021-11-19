# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 23:10:20 by stycho            #+#    #+#              #
#    Updated: 2021/11/19 23:10:21 by stycho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

HEADER		=	pipex.h

LIBFT_PATH	=	./libft

LIB_NAME	=	ft

SRCS		=	pipex.c	ft_pipex_utils_parser.c	ft_check_args_utils.c

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

%.o		:	%.c ${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

${NAME}	:	mklib ${OBJS} ${HEADER}
			${CC} ${CFLAGS} ${OBJS} -L${LIBFT_PATH} -l${LIB_NAME} -o ${NAME}

all		:	${NAME}

mklib	:
			@${MAKE} -C ${LIBFT_PATH}

clean	:
			rm -rf ${OBJS}

fclean	:	clean
			rm -rf ${NAME}
			@${MAKE} fclean -C ${LIBFT_PATH}

re		:	fclean all

.PHONY	:	all clean fclean re mklib