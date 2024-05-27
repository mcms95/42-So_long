#include "so_long.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

int cleanup_and_exit(void *game_ptr)
{
	t_game *game = (t_game *)game_ptr;
	mlx_destroy_window(game->mlx_connection, game->mlx_window);
	free(game->mlx_connection);

	// Free game->map array
	int i = -1;
	while (game->map[++i])
	{
		free(game->map[i]);
	}
	free(game->map);
	free(game);

	// Exit the program
	exit(0);

	return 0;
}

int close_window_with_esc(int keycode, t_game *game)
{
	if (keycode == 65307) {  // 65307 is the keycode for ESC
		cleanup_and_exit(game);
		exit(0);
	}
	return 0;
}