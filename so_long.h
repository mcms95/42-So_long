/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucardos <nucardos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:23:37 by nucardos          #+#    #+#             */
/*   Updated: 2024/06/19 15:29:21 by nucardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_game
{
	int		fd;
	char	**map;
	char	**map_copy;
	int		row_count;
	int		column_count;
	int		player_count;
	int		collectibles_count;
	int		collectibles_count_for_flood_fill;
	int		exit_count;
	int		player_x;
	int		player_y;
	int		exit_flood_fill_count;
	int		moves_count;
	void	*mlx_connection;
	void	*mlx_window;
	void	*img_player;
	void	*img_collectible;
	void	*img_wall;
	void	*img_exit;
	void	*img_background;
	int		img_height;
	int		img_width;
	int		viewport_x;
	int		viewport_y;
	int		max_window_width;
	int		max_window_height;
}	t_game;

//------------------------CHECKS------------------------//
// check.c
void	check_characters_count(t_game *game);
void	check_all_rows_have_same_length(t_game *game);
void	check_all_characters_are_valid(t_game *game);
void	check_all_walls_are_1(t_game *game);
int		check_file_termination(char *map);

// initialization.c
void	initialization(t_game *game);
void	count_rows_and_columns(t_game *game);
void	increment_exit(t_game *game);

// read_map.c
void	read_map(char *map, t_game *game);
void	map_copy(t_game *game);
void	get_player_position(t_game *game);
void	flood_game_with_p(t_game *game, int i, int j);

// flood_fill.c
void	flood_fill(t_game *game, int i, int j);
void	flood_game_with_p(t_game *game, int i, int j);
int		check_game_is_playable(t_game *game);
void	map_copy(t_game *game);

//------------------------GAME------------------------//
// cleanup_and_exit.c
int		cleanup_and_exit(void *game_ptr);
int		close_window_with_esc(int keycode, t_game *game);
void	print_error(char *error, t_game *game);
void	clean_up_map(t_game	*game);

// render_window.c
void	start_game(t_game *game);
void	render_game(t_game *game);
int		render_game_loop(t_game *game);
void	load_characters_image(t_game *game);
void	render_character(t_game *game, int x, int y, char character);

// player_movement.c
void	update_player_position(t_game *game, int new_x, int new_y);
int		key_hook(int keycode, t_game *game);

//------------------------MAIN------------------------//
//so_long.c
void	check_map_and_characters(t_game *game);

#endif