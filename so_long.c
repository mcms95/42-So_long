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
		if(check_game_is_playable(game) == 0)
		{
			print_error("The game is not playable");
			cleanup_and_exit(game);
		}
		start_game(game);
	}
	else
	{
		print_error("The input should be: ./so_long map_file_name.ber\n");
	}
	return (0);
}
