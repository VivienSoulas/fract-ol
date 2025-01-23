NAME 	= fractol
SRC 	= 	fractol.c \
			mandelbrot.c \
			julia.c \
			utils.c \
			set_window.c \
			set_hooks.c \
			handle_hooks.c

OBJ 	= $(SRC:%.c=%.o)
CC 		= cc
CFLAGS 	= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX 	= ./MLX42
PRINTF 	= ./ft_printf
PRINTF_LIB = $(PRINTF)/libftprintf.a
LIBS 	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
HEADERS = -I $(LIBMLX)/include -I $(PRINTF)

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	@make -C $(PRINTF)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBS) $(PRINTF_LIB) $(HEADERS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

PHONY: all clean fclean re

clean:
	@rm -f $(OBJ)
	@rm -rf $(LIBMLX)/build
	@make -C $(PRINTF) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(PRINTF) fclean

re: fclean all