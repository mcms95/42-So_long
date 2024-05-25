#include "../minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("You are pressing key %d!\n", keycode);
	return (0);
}

int	mouse_hook(int keycode, t_vars *vars)
{
	printf("You are pressing mouse key %d!\n", keycode);
	return (0);
}


int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	
	// Key hook
	mlx_key_hook(vars.win, key_hook, &vars);
	
	// Mouse hook
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}