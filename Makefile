NAME = so_long

SRCS = so_long.c	check.c read_map.c	initialization.c	cleanup_and_exit.c \
		render_window.c	player_movement.c	flood_fill.c

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a

MINILIBX = ./minilibx/libmlx.a

RM = rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -Lminilibx -lmlx -L/usr/lib -Iminilibx -lXext -lX11 -lm -lz 

all: $(LIBFT) $(MINILIBX) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Iminilibx -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

$(MINILIBX):
	$(MAKE) -C minilibx

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(MINILIBX) $(MLX_FLAGS) -o $(NAME)

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re