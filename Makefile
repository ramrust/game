# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rulrike <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/24 23:19:05 by rulrike           #+#    #+#              #
#    Updated: 2021/04/24 23:19:09 by rulrike          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror

GNL =	$(addprefix gnl/, \
		get_next_line.c \
		get_next_line_utils.c \
		gnl3.c)

FUNC =	mlx_func.c \
		pars.c pars0.c \
		pars1.c pars2.c \
		errors.c \
		parsmap.c \
		parsview.c \
		pars3.c screensh.c\
		mlx_func2.c mlx_func1.c\
		lod0.c lod1.c lod2.c \
		mlx_func3moves.c

MLX = -lmlx -framework OpenGL -framework AppKit libmlx.dylib

FILE_HEAD = parsin.h

HEAD =	./libft

HEADERS = $(addprefix -I , $(HEAD))

FLAG_LIBFT = libft.a

all: $(NAME)

$(NAME): $(SRCS) $(FILE_HEAD)
		@$(MAKE) -C libft/
		@$(MAKE) -C mlx/
		mv mlx/libmlx.dylib ./
		mv libft/libft.a ./libft.a
		gcc $(CFLAGS) $(GNL) $(FUNC) $(HEADERS) $(FLAG_LIBFT) $(MLX) -o $(NAME)

clean:
	rm -rf libft/*.o
	rm -rf mlx/*.o
	rm -rf libmlx.dylib
	rm -rf libft.a

fclean: clean
	rm -rf $(NAME)

re: fclean clean all

.PHONY: all clean fclean re
