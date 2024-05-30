#include "so_long.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

int	key_hook(int keycode, t_game *game)
{
	int	escape_key;
	int	w_key;
	int	s_key;
	int	a_key;
	int	d_key;

	escape_key = 65307;
	w_key = 119;
	s_key = 115;
	a_key = 97;
	d_key = 100;
	if (keycode == escape_key)
		cleanup_and_exit(game);
	else if (keycode == w_key)
		update_player_position(game, game->player_x, game->player_y - 1);
	else if (keycode == s_key)
		update_player_position(game, game->player_x, game->player_y + 1);
	else if (keycode == a_key)
		update_player_position(game, game->player_x - 1, game->player_y);
	else if (keycode == d_key)
		update_player_position(game, game->player_x + 1, game->player_y);
	return (0);
}

void	collectibles_are_positive(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] != '1')
	{
		if (game->map[new_y][new_x] == 'C')
		{
			game->collectibles_count--;
			game->map[new_y][new_x] = '0';
		}
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = new_x;
		game->player_y = new_y;
		game->map[game->player_y][game->player_x] = 'P';
		game->moves_count++;
		ft_putstr_fd("Moves: ", 1);
		ft_putnbr_fd(game->moves_count, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	collectibles_are_0(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] != '1')
	{
		if (game->map[new_y][new_x] == 'E' && game->collectibles_count == 0)
		{
			ft_putstr_fd("You won the game, congratulations!", 1);
			cleanup_and_exit(game);
		}
		if (game->map[new_y][new_x] == 'C')
		{
			game->collectibles_count--;
			game->map[new_y][new_x] = '0';
		}
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = new_x;
		game->player_y = new_y;
		game->map[game->player_y][game->player_x] = 'P';
		game->moves_count++;
		ft_putstr_fd("Moves: ", 1);
		ft_putnbr_fd(game->moves_count, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	update_player_position(t_game *game, int new_x, int new_y)
{
	if (new_x >= 0 && new_x <= game->column_count - 1
		&& new_y >= 0 && new_y <= game->row_count - 1
		&& game->collectibles_count != 0 && game->map[new_y][new_x] != 'E')
	{
		collectibles_are_positive(game, new_x, new_y);
	}
	else if (new_x >= 0 && new_x <= game->column_count - 1 && new_y >= 0
		&& new_y <= game->row_count - 1 && game->collectibles_count == 0)
	{
		collectibles_are_0(game, new_x, new_y);
	}
}
