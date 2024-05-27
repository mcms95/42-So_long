#include "so_long.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"


// Check if characters count is correct
void	check_characters_count(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while(game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->collectibles_count++;
			if (game->map[i][j] == 'E')
				game->exit_count++;
			if (game->map[i][j] == 'P')
				game->player_count++;
			j++;
		}
		i++;
	}
	if (game->player_count != 1 )
		ft_putstr_fd("There should be only one player\n", 1);
	if (game->exit_count != 1)
		ft_putstr_fd("There should be only one exit\n", 1);
	if (game->collectibles_count == 0)
		ft_putstr_fd("There should be at least one collectible\n", 1);

}

// Check is rows have same length
void check_all_rows_have_same_length(t_game *game)
{
	int	row;
	size_t	row_length;

	row = 0;
	row_length = ft_strlen(game->map[row]);

	while (game->map[row + 1])
	{
		if (ft_strlen(game->map[row + 1]) != row_length)
		{
			ft_putstr_fd("Rows sizes are different\n", 1);
			return;
		}
		row++;
	}
	ft_putstr_fd("Rows are all equal\n", 1);
}

// Check all characters are valid
void check_all_characters_are_valid(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while(game->map[i][j])
		{
			if (!(game->map[i][j] == 'C' || game->map[i][j] == 'E' || game->map[i][j] == 'P' 
				|| game->map[i][j] == '1' || game->map[i][j] == '0'))
				{
					ft_putstr_fd("There are invalid characters in map\n", 1);
					exit(1);
				}
				
			j++;
		}
		i++;
	}
	ft_putstr_fd("All characters in map are valid\n", 1);
}

// check all walls are 1's
void check_all_walls_are_1(t_game *game)
{
    int i;
    int j;
    
	i = 0;
    while (i < game->row_count) {
        j = 0;
        if (i == 0 || i == game->row_count - 1) 
		{
            while (j < game->column_count) {
                if (game->map[i][j] != '1') {
                    printf("First or last row are not just 1's\n");
                    exit(1);
                }
                j++;
            }
        } 
		else 
		{
            if ((game->map[i][0] != '1') || (game->map[i][game->column_count - 1] != '1')) {
                printf("First or last element of row %d are not just 1's\n", i);
                exit(1);
            }
        }
        i++;
    }
}



// check if last 4 leters of the file are .ber
int	check_file_termination(char *map)
{
	int i;
	
	i = 0;
	while (map[i])
		i++;
	if (map[i - 1] != 'r' || map[i - 2] != 'e' || map[i - 3] != 'b' || map[i - 4] != '.')
	{
		ft_putstr_fd("File should have .ber termination\n", 1);
		return (1);
	}
	return (0);
}