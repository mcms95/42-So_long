/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nucardos <nucardos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:11:01 by nucardos          #+#    #+#             */
/*   Updated: 2024/06/19 11:23:04 by nucardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

void	check_map_and_characters(t_game *game)
{
	count_rows_and_columns(game);
	if (game->row_count < 3 || game->row_count >= game->column_count)
	{
		print_error("Map is not a rectangle", game);
	}
	check_all_rows_have_same_length(game);
	check_all_characters_are_valid(game);
	check_characters_count(game);
	check_all_walls_are_1(game);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac == 2 && check_file_termination(av[1]) == 0)
	{
		game = malloc(sizeof(t_game));
		if (!game)
		{
			ft_putstr_fd("Error allocating memory", 1);
			exit(1);
		}
		initialization(game);
		read_map(av[1], game);
		check_map_and_characters(game);
		if (check_game_is_playable(game) == 0)
		{
			print_error("The game is not playable", game);
		}
		start_game(game);
	}
	else
	{
		ft_putstr_fd("The input should be: ./so_long map_file_name.ber\n", 1);
	}
	return (0);
}
