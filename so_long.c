#include "so_long.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

void	check_map_and_characters(t_game *game)
{
	count_rows_and_columns(game);
	if (game->row_count < 3 && game->row_count >= game->column_count)
	{
		print_error("Map is not a rectangle");
	}
	check_all_rows_have_same_length(game);
	check_all_characters_are_valid(game);
	check_characters_count(game);
	check_all_walls_are_1(game);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac == 2 && check_file_termination(av[1]) == 0)
	{
		game = malloc(sizeof(t_game));
		if (!game)
		{
			print_error("Error allocating memory");
		}
		initialization(game);
		read_map(av[1], game);
		check_map_and_characters(game);
		/*if(check_game_is_playable(game) == 0)
		{
			print_error("The game is not playable");
			cleanup_and_exit(game);
		}*/
		start_game(game);
	}
	else
	{
		print_error("The input should be: ./so_long map_file_name.ber\n");
	}
	return (0);
}


/*void	map_copy(t_game *game)
{
	int	i;
	int	j;

	game->map_copy = malloc((game->row_count + 1) * sizeof(char *));
	if (!game->map_copy )
		return ;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		game->map_copy[i] = malloc((game->column_count + 1) * sizeof(char *));
		while (game->map[i][j])
		{
			game->map_copy[i][j] = game->map[i][j];
			j++;
		}
		game->map_copy[i][j] = '\0';
		i++;
	}
	game->map_copy[i] = '\0';
}

void	get_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_copy[i])
	{
		j = 0;
		while (game->map_copy[i][j])
		{
			if (game->map_copy[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_game_with_p(t_game *game, int i, int j)
{
	if (i < 0 || j < 0 || i >= game->row_count || j >= game->column_count)
		return ;
	if (game->map_copy[i][j] == '1' || game->map_copy[i][j] == 'E')
		return ;
	if (game->map_copy[i][j] == 'C')
	{
		game->collectibles_count_for_flood_fill--;
		game->map_copy[i][j] = 'P';
	}
	else
		game->map_copy[i][j] = 'P';
	flood_game_with_p(game, i + 1, j);
	flood_game_with_p(game, i - 1, j);
	flood_game_with_p(game, i, j + 1);
	flood_game_with_p(game, i, j - 1);
}

int check_game_is_playable(t_game *game)
{
	get_player_position(game);
	map_copy(game);
	flood_game_with_p(game, game->player_y, game->player_x);
	if(game->collectibles_count_for_flood_fill != 0)
		print_error("Collectibles are not reachable\n");
	if(game->map_copy[game->exit_y][game->exit_x + 1] == 'P' 
		|| game->map_copy[game->exit_y][game->exit_x - 1] == 'P'
		|| game->map_copy[game->exit_y + 1][game->exit_x] == 'P'
		|| game->map_copy[game->exit_y - 1][game->exit_x] == 'P')
	{
		return (1);
	}
	else
		print_error("Exit is not reachable\n");
	return (0);
}*/