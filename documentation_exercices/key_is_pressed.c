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

int main(void) {
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");

    mlx_hook(vars.win, 2, 1L<<0, key_press, &vars);

    mlx_loop(vars.mlx);
    return 0;
}