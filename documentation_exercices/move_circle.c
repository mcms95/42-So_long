#include "../minilibx/mlx.h"
#include <stdlib.h>

typedef struct s_vars {
    void *mlx;
    void *win;
    int x;
    int y;
} t_vars;

int render_next_frame(t_vars *vars)
{
    int width;
    int height;
    int radius;
    int x;
    int y;
    int color;

    width = 640;
    height = 480;
    radius = 50;
    color = 0xFFFFFF;  // White color

    // Clear the window
    mlx_clear_window(vars->mlx, vars->win);

    // Draw the circle
    y = -radius;
    while (y <= radius)
    {
        x = -radius;
        while (x <= radius)
        {
            if (x * x + y * y <= radius * radius)
                mlx_pixel_put(vars->mlx, vars->win, vars->x + x, vars->y + y, color);
            x++;
        }
        y++;
    }
    return (0);
}

int key_hook(int keycode, t_vars *vars)
{
    if (keycode == 119)  // W key
        vars->y -= 10;
    else if (keycode == 115)  // S key
        vars->y += 10;
    else if (keycode == 97)  // A key
        vars->x -= 10;
    else if (keycode == 100)  // D key
        vars->x += 10;
    return (0);
}

int main(void)
{
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 640, 480, "Circle");
    vars.x = 320;
    vars.y = 240;
    mlx_loop_hook(vars.mlx, render_next_frame, &vars);
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_loop(vars.mlx);
}