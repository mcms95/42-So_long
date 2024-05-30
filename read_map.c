#include "so_long.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

void	read_map(char *map, t_game *game)
{
	char	*tmp;
	char	*str;
	char	*complete_str;

	game->fd = open(map, O_RDONLY);
	complete_str = ft_strdup("");
	str = get_next_line(game->fd);
	if (!str || game->fd == -1 || !complete_str)
		print_error("Error reading map\n");
	while (str)
	{
		tmp = ft_strjoin(complete_str, str);
		if (!tmp)
			print_error("Error joining strings");
		free(complete_str);
		free(str);
		complete_str = tmp;
		str = get_next_line(game->fd);
	}
	game->map = ft_split(complete_str, '\n');
	game->map_copy = ft_split(complete_str, '\n');
	if (!(game->map || game->map_copy))
		print_error("Error splitting string");
	free(complete_str);
}
