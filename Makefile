CC = cc
CFLAGS = -Wall -Wextra -Werror -g -D X_PIXEL=
B_CFLAGS = -D BONUS=

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLXFLAGS = -lX11 -lXext -lm

NAME = cub3D

SRCS = src/main.c src/utils.c src/check.c src/set_data.c src/ft_move.c src/render_img.c src/range_lst_utils.c src/free.c src/minimap.c src/animation.c src/cub3D.c src/raycast.c
HDRS = src/cub3d.h
OBJS = $(SRCS:.c=.o)
X = 1600
BONUS = 0

all: $(NAME)

$(NAME): $(OBJS)
	@make all -C $(LIBFT_DIR)
	@make all -C $(MLX_DIR)
	@$(CC) -fPIE $(OBJS) $(MLX) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	@echo "Let's play !!"

%.o: %.c $(HDRS)
	@$(CC) $(CFLAGS)$(X) $(B_CFLAGS)$(BONUS) -c $< -o $@

bonus:
	@make all -C $(LIBFT_DIR)
	@make all -C $(MLX_DIR)
	@make -e BONUS=1 -e NAME=cub3D_bonus all

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	@rm -f $(NAME)
	@rm	-f cub3D_bonus

re: fclean all

fast: fclean bonus
	rm -f $(OBJS)
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	clear

.PHONY: all bonus clean fclean re fast
