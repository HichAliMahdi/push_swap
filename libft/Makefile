# library name
NAME = libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files && bonus and object files with object bonus
SRC = ft_split.c ft_strchr.c ft_strlcpy.c ft_substr.c ft_strdup.c
OBJ = $(SRC:.c=.o)

# All Rule
all: $(NAME)

# BUILD
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# CLEAN 
clean:
	$(RM) $(OBJ)

# FCLEAN
fclean: clean
	$(RM) $(NAME)

# Rebuild Rule
re: fclean $(NAME)

# Avoid fname as target
.PHONY: all clean fclean re