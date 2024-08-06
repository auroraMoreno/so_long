# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aumoreno <aumoreno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/03 14:33:48 by aumoreno          #+#    #+#              #
#    Updated: 2024/08/06 10:48:54 by aumoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = main.c

FT_PRINTF_PATH = ft_printf/
LIBFT_PATH = libft/


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(FT_PRINTF_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT_PATH)
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
          
OBJS = $(SRCS:.c=.o)


all : $(EXEC)

$(EXEC): $(OBJS)

$(EXEC): $(OBJS)
	@make -C $(FT_PRINTF_PATH) --silent
	@make -C $(LIBFT_PATH) --silent
	@$(CC) $(CFLAGS) $(SRCS) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(EXEC) -I./libft -L./libft -lft -I./ft_printf -L./ft_printf -l ftprintf


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