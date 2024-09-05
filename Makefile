# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aumoreno <aumoreno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/03 14:33:48 by aumoreno          #+#    #+#              #
#    Updated: 2024/09/05 10:07:18 by aumoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = so_long

CC = gcc
CFLAGS = -Werror -Wextra

SRCS = main.c mlx_general_utils.c map_utils.c

FT_PRINTF_PATH = ft_printf/
LIBFT_PATH = libft/
INCLUDES = -I/usr/include -Imlx

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(FT_PRINTF_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT_PATH)
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
          
OBJS = $(SRCS:.c=.o)


all : $(EXEC)

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
$(EXEC): $(OBJS)

$(EXEC): $(OBJS)
	@make -C $(FT_PRINTF_PATH) --silent
	@make -C $(LIBFT_PATH) --silent
	@$(CC) $(CFLAGS) $(SRCS) $(MLX_FLAGS) -o $(EXEC) -I./libft -L./libft -lft -I./ft_printf -L./ft_printf -l ftprintf


clean:
	rm -f $(OBJS)
	@make -C $(FT_PRINTF_PATH) clean --silent

fclean:  clean
	rm -f $(EXEC)
	rm -f $(OBJS)
	@make -C $(FT_PRINTF_PATH) fclean --silent
	@make -C $(LIBFT_PATH) fclean --silent



re: fclean all

.PHONY: all clean fclean re 