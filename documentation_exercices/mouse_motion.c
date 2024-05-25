#include "../minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;


// We then use mlx_hook with the event code 6 (which corresponds to the mouse move event)
// to register the mouse_move_hook function as the event handler. Whenever the mouse is moved within the window, 
//the mouse_move_hook function will be called, and it will print the current mouse position in the terminal.
int	mouse_moving(int x, int y, t_vars *vars)
{
	printf("You are pon position: x %d y %d", x, y);
	return (0);
}


int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	
	// Mouse hook
    mlx_hook(vars.win, 6, 1L << 6, mouse_moving, &vars);
	
	mlx_loop(vars.mlx);
}