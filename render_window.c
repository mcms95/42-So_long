#include "so_long.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

void load_characters_image(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx_connection, "images/player.xpm", &game->img_width, &game->img_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx_connection, "images/collectible.xpm", &game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx_connection, "images/wall.xpm", &game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_connection, "images/exit.xpm", &game->img_width, &game->img_height);
}

void	render_game(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	y = 0;
	i = 0;
	while(i < game->row_count)
	{
		x = 0;
		j = 0;
		while(j < game->column_count)
		{
			if(game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx_connection, game->mlx_window, game->img_wall, x, y);
			if(game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx_connection, game->mlx_window, game->img_player, x, y);
			if(game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx_connection, game->mlx_window, game->img_collectible, x, y);
			if(game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx_connection, game->mlx_window, game->img_exit, x, y);
			x += 64;
			j++;
		}
		y += 64;
		i++;
	}
}

void	start_game(t_game *game)
{
	
	game->mlx_connection = mlx_init(); 
	game->mlx_window = mlx_new_window(game->mlx_connection, game->column_count * 64, game->row_count * 64, "so_long"); 
	load_characters_image(game);
	render_game(game);
	mlx_key_hook(game->mlx_window, key_hook, game);
	mlx_hook(game->mlx_window, 17, 1L<<17, cleanup_and_exit, game);
	mlx_loop(game->mlx_connection);
}