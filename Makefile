# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 19:29:07 by hali-mah          #+#    #+#              #
#    Updated: 2024/11/25 19:33:28 by hali-mah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
SRC_FILES = $(SRC_DIR)/main.c \
            $(SRC_DIR)/stack.c \
			$(SRC_DIR)/free_stack.c

OBJ_FILES = $(SRC_FILES:.c=.o)

PRINTF_DIR = ft_printf

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) -L$(PRINTF_DIR) -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
