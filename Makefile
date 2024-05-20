NAME = so_long

CC = cc
HEADERS = ./Libft/Headers
CFLAGS = -Wall -Wextra -Werror -g -I$(HEADERS) -Imlx
RM = rm -f

MINILIBX = ./mlx
MLX_A = -L$(MINILIBX) -lmlx
MLXFLAGS = -lX11 -lXext -lm

LIBFT_MAKE = ./Libft

SRC = main.c					\
		map_parse.c				\
		map_check.c 			\
		map_valid.c				\
		find_position.c			\
		struct_assignation.c	\
		put_images.c			\
		finish_game.c			\
		movements.c				\
		move_check.c

all: $(NAME)

mlx: 
	wget https://cdn.intra.42.fr/document/document/21656/minilibx-linux.tgz
	tar -xf minilibx-linux.tgz
	mv minilibx-linux mlx
	rm minilibx-linux.tgz

$(NAME): $(SRC)
	@make all -s -C $(LIBFT_MAKE)
	@make all -s -C $(MINILIBX) 1>/dev/null 2>/dev/null
	$(CC) $(CFLAGS) -I. -I$(HEADERS) $(SRC) $(MLX_A) $(MLXFLAGS) -L$(LIBFT_MAKE) -lft -o $(NAME)

clean:
	@make clean -s -C $(LIBFT_MAKE)
	@make clean -s -i -C $(MINILIBX) 1>/dev/null 2>/dev/null

fclean: clean
	@make fclean -s -C $(LIBFT_MAKE)
	@$(RM) $(NAME)

re: fclean all

# .SILENT:
.PHONY: all clean fclean re