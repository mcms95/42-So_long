#include "so_long.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

void	count_rows_and_columns(t_game *game)
{
	int	i;

	i = 0;
	while(game->map[i])
		i++;
	game->row_count = i;
	game->column_count = (int)ft_strlen(game->map[0]);
	ft_putnbr_fd(game->row_count, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(game->column_count, 1);
	ft_putchar_fd('\n', 1);

}