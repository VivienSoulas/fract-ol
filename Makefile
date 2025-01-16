NAME 	= fractol
SRC 	= 	fractol.c \
			mandelbrot.c \
			julia.c \
			utils.c \
			set_window.c

OBJ 	= $(SRC:%.c=%.o)
CC 		= cc
CFLAGS 	= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX 	= ./MLX42
LIBS 	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
HEADERS = -I $(LIBMLX)/include

all: libmlx $(NAME)

libmlx:
# echo $(OBJ)
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBS) $(HEADERS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

PHONY: all clean fclean re

clean:
	@rm -f $(OBJ)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -f $(NAME)

re: fclean all