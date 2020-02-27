# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/07 18:36:27 by svivienn          #+#    #+#              #
#    Updated: 2020/02/13 00:17:35 by svivienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS =	srcs/graphics.o \
		srcs/init.o \
		srcs/main.o \
		srcs/parser.o \
		srcs/tools.o

W_FLAGS = -Wall -Wextra -Werror

LIB_NAME = srcs/libft/libft.a

NAME = fdf

UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	C_CMD = gcc $(FLAGS) -IMinilibX/X11/ -L/usr/X11/lib $(OBJS) $(LIB_NAME) \
		/usr/X11/lib/libmlx.a -o $@ -lXext -lX11 -lm
endif
ifeq ($(UNAME_S),Darwin)
	C_CMD = gcc $(FLAGS) -lmlx -framework OpenGL -framework AppKit \
		$(OBJS) $(LIB_NAME) -o $@
endif

all: $(NAME)

$(NAME): $(OBJS)
	make -C srcs/libft
	$(C_CMD)

$(OBJS): %.o: %.c
	gcc -c $(FLAGS) $< -o $@ -I./includes -I./srcs/libft

clean:
	make -C srcs/libft clean
	rm -f $(OBJS)

fclean: clean
	make -C srcs/libft fclean
	rm -f $(NAME)

re: fclean all
