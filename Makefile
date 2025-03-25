# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/03 14:33:48 by aumoreno          #+#    #+#              #
#    Updated: 2025/03/25 16:58:14 by aumoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = so_long

CC = gcc
CFLAGS = -Werror -Wextra -Wall -fsanitize=address,leak -g3

SRCS = main.c valid_path_check.c checks.c init_game.c init_map.c map_utils.c errors.c movements_utils.c movements.c gnl/get_next_line_utils.c gnl/get_next_line.c

LIBFT_PATH = libft/
INCLUDES = -I/usr/include -Imlx

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT_PATH)
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
          
OBJS = $(SRCS:.c=.o)


all : $(EXEC)

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
$(EXEC): $(OBJS)

$(EXEC): $(OBJS)
	@make -C $(LIBFT_PATH) --silent
	@$(CC) $(CFLAGS) $(SRCS) $(MLX_FLAGS) -o $(EXEC) -I./libft -L./libft -lft 


clean:
	rm -f $(OBJS)


fclean:  clean
	rm -f $(EXEC)
	rm -f $(OBJS)
	@make -C $(LIBFT_PATH) fclean --silent

re: fclean all

.PHONY: all clean fclean re 