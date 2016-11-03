# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/30 01:29:56 by yaitalla          #+#    #+#              #
#    Updated: 2015/10/30 17:23:56 by yaitalla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_ls
CFLAGS=-Werror -Wextra -Wall -Ilibft/includes
LFLAGS=-Llibft -lft
SRC= main.c setup.c display.c free.c list.c l_option.c misc.c sort.c save.c
OBJ=$(SRC:.c=.o)

all: lib $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $^ $(LFLAGS)

%.o: %.c
	gcc -o $@ -c $< $(CFLAGS)

lib:
	make -C libft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
