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
	int		row_count;
	int		column_count;
	int		player_count;
	int		collectibles_count;
	int		exit_count;
	int		move_x;
	int		move_y;
	int		moves_count;
	void	*mlx_connection;
	void	*mlx_window;
	void	*img_player;
	void	*img_collectible;
	void	*img_wall;
	void	*img_exit;
	int		img_height;
	int		img_width;

} t_game;

//------------------------CHECKS------------------------//
// check.c
void	check_characters_count(t_game *game);
void	check_all_rows_have_same_length(t_game *game);
void	check_all_characters_are_valid(t_game *game);
void	check_all_walls_are_1(t_game *game);
int		check_file_termination(char *map);

// initialization.c
void	initialization(t_game *game);

// read_map.c
void	read_map(char *map, t_game *game);

// count.c
void	count_rows_and_columns(t_game *game);

//------------------------GAME------------------------//
// cleanup_and_exit.c
int cleanup_and_exit(void *game_ptr);
int close_window_with_esc(int keycode, t_game *game);

// render_window.c
void	start_game(t_game *game);
void	render_game(t_game *game);
void	load_characters_image(t_game *game);

//------------------------MAIN------------------------//
//so_long.c
void check_map_and_characters(t_game *game);
int key_hook(int keycode, t_game *game);



#endif