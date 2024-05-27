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