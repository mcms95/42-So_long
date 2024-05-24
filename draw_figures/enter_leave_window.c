#include "../minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_vars {
    void *mlx;
    void *win;
	int keycode;
    int key_pressed_count;
} t_vars;

int enter_window(void *vars)
{
	printf("Hello\n");
	return 0;
}

int leave_window(void *vars)
{
	printf("Bye\n");
	return 0;
}


int main(void) {
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 500, 500, "Long Key Press");

    mlx_hook(vars.win, 7, 1L<<4, enter_window, &vars);
    mlx_hook(vars.win, 8, 1L<<5, leave_window, &vars);
	mlx_loop(vars.mlx);
    return 0;
}