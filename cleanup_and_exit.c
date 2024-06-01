#include "so_long.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

int	cleanup_and_exit(void *game_ptr)
{
	t_game	*game;
	int		i;

	game = (t_game *)game_ptr;
	i = -1;
	while (game->map[++i])
	{
		free(game->map[i]);
	}
	free(game->map);
	i = -1;
	while (game->map_copy[++i])
	{
		free(game->map_copy[i]);
	}
	free(game->map_copy);
	mlx_destroy_image(game->mlx_connection, game->img_collectible);
	mlx_destroy_image(game->mlx_connection, game->img_exit);
	mlx_destroy_image(game->mlx_connection, game->img_player);
	mlx_destroy_image(game->mlx_connection, game->img_wall);
	mlx_destroy_image(game->mlx_connection, game->img_background);
	mlx_clear_window(game->mlx_connection, game->mlx_window);
	mlx_destroy_window(game->mlx_connection, game->mlx_window);
	mlx_destroy_display(game->mlx_connection);
	free(game->mlx_connection);
	free(game);
	exit(0);
	return (0);
}

int	close_window_with_esc(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		cleanup_and_exit(game);
		exit(0);
	}
	return (0);
}

void	print_error(char *error)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(error, 1);
}
