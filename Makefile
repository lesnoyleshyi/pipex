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

LIB_PATH	=	./libft

LIB_NAME	=	ft

LIBFT		=	${LIB_PATH}/$(addsuffix .a,$(addprefix lib, ${LIB_NAME}))

SRCS		=	pipex.c	ft_pipex_utils_parser.c	ft_pipex_utils_errors.c

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

%.o		:	%.c ${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

.PHONY	:	all clean fclean re libft debug_pipex debug_execve_NULL

all		:	${NAME}

${NAME}	:	${OBJS} ${LIBFT}
			${CC} ${CFLAGS} ${OBJS} -L${LIB_PATH} -l${LIB_NAME} -o ${NAME}

${LIBFT}:	libft ;

libft	:
			${MAKE} $(addsuffix .a,$(addprefix lib, ${LIB_NAME})) -C ${LIB_PATH}

clean	:
			rm -rf ${OBJS}
			${MAKE} clean -C ${LIB_PATH}

fclean	:	clean
			rm -rf ${NAME}
			${MAKE} fclean -C ${LIB_PATH}

re		:	fclean all

debug_execve_NULL	:
						${CC} ${CFLAGS} -g test_execv.c -o test_execv_null

debug_pipex			:
						${CC} ${CFLAGS} -g ${SRCS} -L${LIBFT_PATH} -l${LIB_NAME} -o pipex_debug
