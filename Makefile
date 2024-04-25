# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 16:28:20 by nandreev          #+#    #+#              #
#    Updated: 2024/04/25 14:19:12 by nandreev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = src/main.c src/free.c src/libft.c src/read_map.c \
		src/check_path.c \
		src/get_next_line/get_next_line.c src/get_next_line/get_next_line_utils.c

OBJS := $(SOURCES:.c=.o)
MLX_LIB = mlx/
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS)
	@if [ ! -d "mlx" ]; then \
	git clone https://github.com/42Paris/minilibx-linux.git mlx; \
	fi
	@make -C $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re