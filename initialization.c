/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucardos <nucardos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:10:49 by nucardos          #+#    #+#             */
/*   Updated: 2024/06/19 15:33:34 by nucardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

void	initialization(t_game *game)
{
	game->fd = 0;
	game->row_count = 0;
	game->column_count = 0;
	game->player_count = 0;
	game->collectibles_count = 0;
	game->collectibles_count_for_flood_fill = 0;
	game->exit_count = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->exit_flood_fill_count = 0;
	game->moves_count = 0;
	game->mlx_connection = NULL;
	game->mlx_window = NULL;
	game->img_wall = NULL;
	game->img_background = NULL;
	game->img_player = NULL;
	game->img_exit = NULL;
	game->img_collectible = NULL;
}

void	count_rows_and_columns(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	game->row_count = i;
	game->column_count = (int)ft_strlen(game->map[0]);
}

void	increment_exit(t_game *game)
{
	game->exit_count++;
	game->exit_flood_fill_count++;
}
