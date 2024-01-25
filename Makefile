# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 13:29:07 by emehdaou          #+#    #+#              #
#    Updated: 2024/01/25 18:19:47 by emehdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

LIBFT			=	libft.a

SRCS			=	srcs/main.c \
					srcs/parse.c \

OBJS			=	${SRCS:.c=.o}

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

HEAD			=	-I includes

CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra

all				:	${NAME}

$(NAME): $(OBJS)
	@make -C libft
	@mv libft/libft.a .
	cc $(OBJS) mlx/libmlx.a mlx/libmlx_Linux.a -L. -lXext -L. -lX11 ${LIBFT} -o $(NAME)

clean			:
					make clean -C libft
					rm -rf ${OBJS}

fclean			:	clean
					make fclean -C libft
					rm -rf ${LIBFT}
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re bonus