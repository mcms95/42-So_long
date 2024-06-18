#include "so_long.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"


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


void flood_game_with_p(t_game *game, int i, int j) {

	if (i < 0 || j < 0 || i >= game->row_count || j >= game->column_count)
		return;
	if (game->map_copy[i][j] == '1' || game->map_copy[i][j] == 'X')
		return;
	if (game->map_copy[i][j] == 'C') 
		game->collectibles_count_for_flood_fill--;
	
	if (game->map_copy[i][j] == 'E')
		game->exit_flood_fill_count--;

	game->map_copy[i][j] = 'X'; // Mark the cell as visited

	flood_game_with_p(game, i + 1, j);
	flood_game_with_p(game, i - 1, j);
	flood_game_with_p(game, i, j + 1);
	flood_game_with_p(game, i, j - 1);
}

int check_game_is_playable(t_game *game)
{
	get_player_position(game);
	printf("collectibles_count_for_flood_fill: %d\n", game->collectibles_count_for_flood_fill);
	flood_game_with_p(game, game->player_y, game->player_x);
	printf("collectibles_count_for_flood_fill: %d\n", game->collectibles_count_for_flood_fill);
	printf("exit_flood_fill_count: %d\n", game->exit_flood_fill_count);
	if (game->collectibles_count_for_flood_fill != 0 || game->exit_flood_fill_count != 0)
	{
		if (game->collectibles_count_for_flood_fill != 0)
			print_error("Collectibles are not reachable\n");
		if (game->exit_flood_fill_count != 0)
			print_error("Exit is not reachable\n");
		return (0);
	}
	return (1);
}

