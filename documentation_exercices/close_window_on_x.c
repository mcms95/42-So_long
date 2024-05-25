#include "../minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_vars {
    void *mlx;
    void *win;
} t_vars;

int key_press(int keycode, void *vars) {
    printf("Key pressed: %d\n", keycode);
    return 0;
}

int close_window(void *vars) {
    t_vars *v = (t_vars *)vars;
    mlx_destroy_window(v->mlx, v->win);
    printf("Window closed\n");
    exit(0);
    return 0;
}

int main(void) {
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 500, 500, "Close Window");

    mlx_hook(vars.win, 2, 1L<<0, key_press, &vars);
	// 1L<<17 --> mask to StructureNotifyMask
	// 17 event -> DestroyNotify
    mlx_hook(vars.win, 17, 1L<<17, close_window, &vars);

    mlx_loop(vars.mlx);
    return 0;
}