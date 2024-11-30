# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 19:29:07 by hali-mah          #+#    #+#              #
#    Updated: 2024/11/30 04:27:31 by hali-mah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories for source files
OPERATIONS_DIR = operations
SORTING_DIR = sorting
UTILS_DIR = utils
PRINTF_DIR = ft_printf

# Source files
OPE_FILES = $(OPERATIONS_DIR)/push_operations.c \
			$(OPERATIONS_DIR)/r_rotate_operations.c \
			$(OPERATIONS_DIR)/rotate_operations.c \
			$(OPERATIONS_DIR)/stack_operations.c \
			$(OPERATIONS_DIR)/swap_operations.c

SOR_FILES = $(SORTING_DIR)/sorting_logic.c

UTI_FILES = $(UTILS_DIR)/stack_utilities.c

# Main source file
SRC = main.c

# All source files
SRCS = $(SRC) $(OPE_FILES) $(SOR_FILES) $(UTI_FILES)

# Object files
OBJ = $(SRCS:.c=.o)

# Library
LIBFTPRINTF = $(PRINTF_DIR)/libftprintf.a

# Output name
$(NAME): $(OBJ) $(LIBFTPRINTF)
	$(CC) $(OBJ) -o $(NAME) -L$(PRINTF_DIR) -lftprintf

# Rule to build ft_printf
$(LIBFTPRINTF):
	make -C $(PRINTF_DIR)

# Rule to compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)
	make -C $(PRINTF_DIR) clean  # Clean ft_printf objects

# Remove compiled executable
fclean: clean
	rm -f $(NAME)
	make -C $(PRINTF_DIR) fclean  # Clean ft_printf executable

# Rebuild everything
re: fclean $(NAME)

.PHONY: clean fclean re