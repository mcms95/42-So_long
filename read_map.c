#include "so_long.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

void	read_map(char *map, t_game * game)
{
    char	*tmp;
    char	*str;
    char	*complete_str;
    
    game->fd = open(map, O_RDONLY);
    complete_str = ft_strdup("");
    if (!complete_str)
        perror("Creating complete_str");
    if (game->fd == -1) {
        perror("Error opening map file");
        return;  // Add return statement to exit the function if the file can't be opened
    }
    
    str = get_next_line(game->fd);
    if (!str)
        perror("Empty file");
    while(str)
    {
        tmp = ft_strjoin(complete_str, str);
        if (!tmp)
            perror("Error joining strings");
        free(complete_str);
        free(str);
        complete_str = tmp;
        str = get_next_line(game->fd);
    }
    game->map = ft_split(complete_str, '\n');
    if (!game->map)
        perror("Error splitting string");
    free(complete_str);
}