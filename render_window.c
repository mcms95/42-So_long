/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucardos <nucardos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:10:58 by nucardos          #+#    #+#             */
/*   Updated: 2024/06/19 15:37:24 by nucardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

void	load_characters_image(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image(
			game->mlx_connection, "images/player.xpm",
			&game->img_width, &game->img_height);
	if (game->img_player == NULL)
		print_error("Invalid player image", game);
	game->img_collectible = mlx_xpm_file_to_image(
			game->mlx_connection, "images/collectible.xpm",
			&game->img_width, &game->img_height);
	if (game->img_collectible == NULL)
		print_error("Invalid collectible image", game);
	game->img_wall = mlx_xpm_file_to_image(
			game->mlx_connection, "images/wall.xpm",
			&game->img_width, &game->img_height);
	if (game->img_wall == NULL)
		print_error("Invalid wall image", game);
	game->img_exit = mlx_xpm_file_to_image(
			game->mlx_connection, "images/exit.xpm",
			&game->img_width, &game->img_height);
	if (game->img_exit == NULL)
		print_error("Invalid exit image", game);
	game->img_background = mlx_xpm_file_to_image(
			game->mlx_connection, "images/background.xpm",
			&game->img_width, &game->img_height);
	if (game->img_background == NULL)
		print_error("Invalid background image", game);
}

int	render_game_loop(t_game *game)
{
	render_game(game);
	return (0);
}

void	render_character(t_game *game, int x, int y, char character)
{
	if (character == '1')
	{
		mlx_put_image_to_window(game->mlx_connection,
			game->mlx_window, game->img_wall, x, y);
	}
	else if (character == 'P')
	{
		mlx_put_image_to_window(game->mlx_connection,
			game->mlx_window, game->img_player, x, y);
	}
	else if (character == 'C')
	{
		mlx_put_image_to_window(game->mlx_connection,
			game->mlx_window, game->img_collectible, x, y);
	}
	else if (character == 'E')
	{
		mlx_put_image_to_window(game->mlx_connection,
			game->mlx_window, game->img_exit, x, y);
	}
	else if (character == '0')
	{
		mlx_put_image_to_window(game->mlx_connection,
			game->mlx_window, game->img_background, x, y);
	}
}

void	render_game(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	y = 0;
	i = -1;
	while (++i < game->row_count)
	{
		x = 0;
		j = -1;
		while (++j < game->column_count)
		{
			render_character(game, x, y, game->map[i][j]);
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			x += 32;
		}
		y += 32;
	}
}

void	start_game(t_game *game)
{
	game->mlx_connection = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx_connection,
			game->column_count * 32, game->row_count * 32, "so_long");
	load_characters_image(game);
	mlx_loop_hook(game->mlx_connection, render_game_loop, game);
	mlx_key_hook(game->mlx_window, key_hook, game);
	mlx_hook(game->mlx_window, 17, 1L << 17, cleanup_and_exit, game);
	mlx_loop(game->mlx_connection);
}
