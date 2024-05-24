#include "../minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_vars {
    void *mlx;
    void *win;
    int width;
    int height;
} t_vars;



int window_resized(int keycode, void *vars) {
    t_vars *v = (t_vars *)vars;

    if (keycode == 43) {  // +
        v->width += 50;
        v->height += 50;
        mlx_destroy_window(v->mlx, v->win);
        v->win = mlx_new_window(v->mlx, v->width, v->height, "Resizable Window");
        mlx_hook(v->win, 2, 1L<<0, window_resized, v);
        printf("Window resized: %d x %d\n", v->width, v->height);
    }
	else if (keycode == 45) // -
	{
		v->width -= 50;
		v->height -= 50;
		mlx_destroy_window(v->mlx, v->win);
		v->win = mlx_new_window(v->mlx, v->width, v->height, "Resizible window");
		mlx_hook(v->win, 2, 1L<<0, window_resized, v);
		printf("Window resized: %d x %d\n", v->width, v->height);
	}
	else if(keycode == 65307) // ESC
	{
		printf("ESC pressed, closing window..");
		mlx_destroy_window(v->mlx, v->win);
	}
	else
		printf("Key pressed: %d\n", keycode);

    return 0;
}

int main(void) {
    t_vars vars;

    vars.width = 500;
    vars.height = 500;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "Resizable Window");

    mlx_hook(vars.win, 2, 1L<<0, window_resized, &vars);

    mlx_loop(vars.mlx);
    return 0;
}