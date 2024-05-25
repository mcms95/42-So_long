#include "../minilibx/mlx.h"
#include <stdlib.h>

typedef struct s_vars {
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    int frame;
} t_vars;

void my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
    char *dst;
    dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

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

    vars->img = mlx_new_image(vars->mlx, width, height);
    vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length, &vars->endian);

    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            color = (vars->frame + x + y) % 255;
            my_mlx_pixel_put(vars, x, y, (color << 16) | (color << 8) | color);
            x++;
        }
        y++;
    }

    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
    mlx_destroy_image(vars->mlx, vars->img);

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