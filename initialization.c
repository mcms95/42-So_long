#include "so_long.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

void	initialization(t_game *game)
{
	game->fd = 0;
	game->row_count = 0;
	game->column_count = 0;
	game->player_count = 0;
	game->collectibles_count = 0;
	game->exit_count = 0;
	game->move_x = 0;
	game->move_y = 0;
	game->moves_count = 0;
	game->mlx_connection = NULL;
	game->mlx_window = NULL;

}