# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 19:29:07 by hali-mah          #+#    #+#              #
#    Updated: 2024/12/16 11:59:26 by hali-mah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories for source files
OPERATIONS_DIR = operations
SORTING_DIR = sorting
UTILS_DIR = utils
LIBFT_DIR = libft
PRINTF_DIR = ft_printf

# Source files
OPE_FILES = $(OPERATIONS_DIR)/push_operations.c \
			$(OPERATIONS_DIR)/r_rotate_operations.c \
			$(OPERATIONS_DIR)/rotate_operations.c \
			$(OPERATIONS_DIR)/stack_operations.c \
			$(OPERATIONS_DIR)/swap_operations.c

SOR_FILES = $(SORTING_DIR)/sorting_logic.c \
			$(SORTING_DIR)/sorting_large.c

UTI_FILES = $(UTILS_DIR)/stack_utilities.c \
			$(UTILS_DIR)/utilities.c \
			$(UTILS_DIR)/rotate_utils.c \
			$(UTILS_DIR)/args_utils.c \
			$(UTILS_DIR)/sort_large_utils.c \
			$(UTILS_DIR)/sorting_utils.c

# Main source file
SRC = main.c

# All source files
SRCS = $(SRC) $(OPE_FILES) $(SOR_FILES) $(UTI_FILES)

# Object files
OBJ = $(SRCS:.c=.o)

# Library
LIBFT = $(LIBFT_DIR)/libft.a
LIBFTPRINTF = $(PRINTF_DIR)/libftprintf.a

# Output name
$(NAME): $(OBJ) $(LIBFT) $(LIBFTPRINTF)
	$(CC) $(OBJ) -o $(NAME) -L$(PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft

# Rule to build ft_printf
$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBFTPRINTF):
	make -C $(PRINTF_DIR)

# Rule to compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

# Remove compiled executable
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

# Rebuild everything
re: fclean $(NAME)

.PHONY: clean fclean re