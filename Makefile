# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 00:59:40 by mlindenm          #+#    #+#              #
#    Updated: 2023/04/18 21:14:28 by mlindenm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
NAME_SERVER = server
NAME_CLIENT = client

OBJS_SERVER = server.o ft_printf_decimal.o ft_printf.o ft_printf_string.o
OBJS_CLIENT = client.o ft_printf_decimal.o ft_printf.o ft_printf_string.o

SRCS_SERVER = server.c ft_printf_string.c ft_printf.c
SRCS_CLIENT = client.c ft_printf_string.c ft_printf.c

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(NAME_SERVER) $(NAME_CLIENT)

server: $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME_SERVER)

client: $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT)

clean:
	@/bin/rm -f $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_PRINTF)

fclean: clean
	@/bin/rm -f $(NAME_SERVER) $(NAME_CLIENT) $(OBJS_PRINTF)

re: fclean all

.PHONY: all clean fclean re
