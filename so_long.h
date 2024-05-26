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
	int		exit_count;
	int		move_x;
	int		move_y;
	

} t_game;

// check.c
void	check_characters_count(t_game *game);
void	check_all_rows_have_same_length(t_game *game);
void	check_all_characters_are_valid(t_game *game);
void	check_all_walls_are_1(t_game *game);


// map_parsing.c
void	read_map(char *map, t_game *game);
void	initialization(t_game *game);
void	check_map(t_game *game);

// count.c
void	count_rows_and_columns(t_game *game);



#endif