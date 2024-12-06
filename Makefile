NAME = fractol.a
SRC = fractol.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra

all = $(NAME)

$(NAME) = $(OBJ)
	@ar rcs $(NAME) $(OBJ)

(%.o: %.c)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all