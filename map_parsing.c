#include "so_long.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

void	read_map(char *map, t_game * game)
{
    int		fd;
	char	*tmp;
	char	*str;
	char	*complete_str;
	
	fd = open(map, O_RDONLY);
	complete_str = ft_strdup("");
    if (fd < 0) {
        perror("Error opening map file");
        exit(1);
    }
	str = get_next_line(fd);
	if (!str)
	{
		perror("Empty file");
	}
	while(str)
	{
		tmp = ft_strjoin(complete_str, str);
		free(complete_str);
		free(str);
		complete_str = tmp;
		str = get_next_line(fd);
	}
	game->map = ft_split(complete_str, '\n');
	free(complete_str);

}

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
}



int main(int ac, char **av)
{
    // Arguments will be 1 - executable, 2 - map_name
    if (ac == 2) 
	{
		t_game *game;
		game = malloc(sizeof(t_game));

		// Read map and keep it in game.map
        read_map(av[1], game);

		// Initialize game variables
		initialization(game);
		

		// Check items
		//check_characters_count(game);

		// Check if all rows are same size
		//check_all_rows_have_same_length(game);

		// Count rows and collumns size
		count_rows_and_columns(game);

		// Check all walls are 1
		check_all_walls_are_1(game);
		
		// Check all char are valid
		//check_all_characters_are_valid(game);

		// Print Map
        int i = 0;
		while (game->map[i] != NULL)
		{
			ft_putstr_fd(game->map[i], 1);
			ft_putchar_fd('\n', 1);
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