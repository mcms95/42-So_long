NAME = so_long

SRCS = map_parsing.c	check.c	count.c

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a

MINILIBX = ./minilibx/libmlx.a

RM = rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

MLX_FLAGS = -Lminilibx -lmlx -L/usr/lib -Iminilibx -lXext -lX11 -lm -lz -lbsd

all: $(LIBFT) $(MINILIBX) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Iminilibx -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

$(MINILIBX):
	$(MAKE) -C minilibx

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(MINILIBX) $(MLX_FLAGS) -fsanitize=address -o $(NAME)

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re