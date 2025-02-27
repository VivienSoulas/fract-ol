NAME 	= fractol
SRC 	= 	fractol.c \
			mandelbrot.c \
			julia.c \
			newton.c \
			utils.c \
			set_window.c \
			set_hooks.c \
			handle_hooks.c \
			print_utils.c

OBJ 	= $(SRC:%.c=%.o)
CC 		= cc
CFLAGS 	= -Wextra -Wall -Werror -g

# MLX Linker Flags
FLAGSMLX = -ldl -lglfw -pthread -lm

# libraries paths
MLX			= ./MLX42
MLX_LIB		= $(MLX)/build/libmlx42.a 
PRINTF		= ./ft_printf
PRINTF_LIB	= $(PRINTF)/libftprintf.a
HEADERS = -I $(MLX)/include -I $(PRINTF)

all: $(MLX_LIB) $(PRINTF_LIB) $(NAME)

# build ML42 Library
$(MLX_LIB):
	@cmake $(MLX) -B $(MLX)/build
	@make -C $(MLX)/build -j4
	@echo "MLX42 compiled"

# build ft_printf library
$(PRINTF_LIB):
	@make -C $(PRINTF)
	@echo "ft_printf compiled"

# compile the project
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) $(PRINTF_LIB) -o $(NAME) $(FLAGSMLX)
	@echo "Program compiled"

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

PHONY: all clean fclean re

clean:
	@rm -f $(OBJ)
	@rm -rf $(MLX)/build
	@make -C $(PRINTF) clean
	@echo "Objects removed"

fclean: clean
	@rm -f $(NAME)
	@make -C $(PRINTF) fclean
	@echo "Executable removed"

re: fclean all
