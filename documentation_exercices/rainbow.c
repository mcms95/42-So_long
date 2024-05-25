#include "../minilibx/mlx.h"
#include <stdlib.h>
#include <math.h>

typedef struct s_vars {
    void *mlx;
    void *win;
    int frame;
} t_vars;

int render_next_frame(t_vars *vars)
{
    int width;
    int height;
    int x;
    int y;
    int color;

    width = 640;
    height = 480;
    vars->frame++;

    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            color = (vars->frame + x + y) % 255;
            mlx_pixel_put(vars->mlx, vars->win, x, y, (color << 16) | (color << 8) | color);
            x++;
        }
        y++;
    }
    return (0);
}

int main(void)
{
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 640, 480, "Rainbow");
    vars.frame = 0;
    mlx_loop_hook(vars.mlx, render_next_frame, &vars);
    mlx_loop(vars.mlx);
}