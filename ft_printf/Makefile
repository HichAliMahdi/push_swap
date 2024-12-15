# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hali-mah <hali-mah@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 12:49:48 by hali-mah            #+#    #+#              #
#    Updated: 2024/10/22 12:49:48 by hali-mah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Libreay name
NAME = libftprintf.a

# Sources files
SRC = ft_printf.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c ft_unsnbr.c ft_lhex.c ft_uhex.c ft_putptr.c ft_format.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# All rule
all: $(NAME)

# Build
$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

# Clean
clean:
		$(RM) $(OBJ)

# Fclean
fclean: clean
		$(RM) $(NAME)

# Rebuild
re:		fclean $(NAME)

.PHONY: all clean fclean re