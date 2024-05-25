#include "../minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_vars {
    void *mlx;
    void *win;
	int keycode;
    int key_pressed_count;
} t_vars;

// When you press and hold a key, the operating system generates a series of KeyPress events at a certain rate, typically around 50 times per second 
int key_press(int keycode, void *vars) {
    t_vars *v = (t_vars *)vars;

    if (v->keycode != keycode) {
        v->keycode = keycode;
        v->key_pressed_count = 0;
    }
	v->key_pressed_count++;
	if( v->key_pressed_count == 50) {
		printf("You have been pressing %d, for 1 second\n", keycode);
	}
    return 0;
}



int main(void) {
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 500, 500, "Long Key Press");
	vars.keycode = 0;
    vars.key_pressed_count = 0;

    mlx_hook(vars.win, 2, 1L<<0, key_press, &vars);
    mlx_loop(vars.mlx);
    return 0;
}