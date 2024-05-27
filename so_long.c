#include "so_long.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

void check_map_and_characters(t_game *game)
{
	count_rows_and_columns(game);
	if (game->row_count >= game->column_count)
	{
		ft_putstr_fd("Map is not a rectangle\n", 1);
	}
	check_all_rows_have_same_length(game);
	check_all_characters_are_valid(game);
	check_characters_count(game);
	check_all_walls_are_1(game);
}

int key_hook(int keycode, t_game *game)
{
	if (keycode == 65307) // ESC key
	{
		cleanup_and_exit(game);
	}
	else if(keycode == 119) // W key
		ft_putstr_fd("Move: W", 1);
	else if(keycode == 115) // S key
		ft_putstr_fd("Move: S", 1);
	else if(keycode == 97) // A key	
		ft_putstr_fd("Move: A", 1);
	else if(keycode == 100) // D key
		ft_putstr_fd("Move: D", 1);
	game->moves_count++;
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(ft_itoa(game->moves_count), 1);
	ft_putchar_fd('\n', 1);
	return 0;
}


void	start_game(t_game *game)
{
	
	game->mlx_connection = mlx_init(); 
	game->mlx_window = mlx_new_window(game->mlx_connection, game->column_count * 64, game->row_count * 64, "so_long"); 
	mlx_key_hook(game->mlx_window, key_hook, game);
	mlx_hook(game->mlx_window, 17, 1L<<17, cleanup_and_exit, game);
	mlx_loop(game->mlx_connection);
}

int main(int ac, char **av)
{
	// Arguments will be 1 - executable, 2 - map_name
	if (ac == 2 && check_file_termination(av[1]) == 0)
	{
		t_game *game;
		game = malloc(sizeof(t_game));
		if (!game)
		{
			perror("Error allocating memory");
			exit(1);
		}

		// Initialize variables, read map, and check map
		initialization(game);
		read_map(av[1], game);
		check_map_and_characters(game);

		// Start game
		start_game(game);

		// Free memory
		// Free memory
		int i = 0;
		while (game->map[i]) {
			free(game->map[i]);
			i++;
		}
		free(game->map);
		free(game);
	} else 
	{
		ft_putstr_fd("Usage: ./so_long <map_file>\n", 1);
		return 1;
	}

	return 0;
}