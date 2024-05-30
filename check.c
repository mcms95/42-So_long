#include "so_long.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

void	check_characters_count(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
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
	if (game->player_count != 1)
		print_error("There should be only one player\n");
	if (game->exit_count != 1)
		print_error("There should be only one exit\n");
	if (game->collectibles_count == 0)
		print_error("There should be at least one collectible\n");
}

void	check_all_rows_have_same_length(t_game *game)
{
	int		row;
	size_t	row_length;

	row = 0;
	row_length = ft_strlen(game->map[row]);
	while (game->map[row + 1])
	{
		if (ft_strlen(game->map[row + 1]) != row_length)
		{
			print_error("Rows sizes are different\n");
		}
		row++;
	}
}

void	check_all_characters_are_valid(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!(game->map[i][j] == 'C' || game->map[i][j] == 'E' ||
			game->map[i][j] == 'P' || game->map[i][j] == '1' ||
			game->map[i][j] == '0'))
			{
				print_error("There are invalid characters in map\n");
			}
			j++;
		}
		i++;
	}
}

void	check_all_walls_are_1(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->row_count)
	{
		j = 0;
		if (i == 0 || i == game->row_count - 1)
		{
			while (j < game->column_count)
			{
				if (game->map[i][j] != '1')
					print_error("First or last row are not just 1's\n");
				j++;
			}
		}
		else
		{
			if ((game->map[i][0] != '1') ||
				(game->map[i][game->column_count - 1] != '1'))
				print_error("Rows are not just 1's\n");
		}
		i++;
	}
}

int	check_file_termination(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (map[i - 1] != 'r' || map[i - 2] != 'e'
		|| map[i - 3] != 'b' || map[i - 4] != '.')
	{
		print_error("File should have .ber termination\n");
	}
	return (0);
}
