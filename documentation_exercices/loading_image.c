#include <mlx.h>
#include <stdio.h>

typedef struct s_vars {
    void *mlx;
    void *win;
    void *img;
    int img_width;
    int img_height;
    int x;
    int y;
} t_vars;

int mouse_move(int x, int y, t_vars *vars)
{
    vars->x = x;
    vars->y = y;
    mlx_clear_window(vars->mlx, vars->win);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x, vars->y);
    return 0;
}

int main(void)
{
    t_vars vars;
    char *relative_path = "../images/tree.xpm";

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 640, 480, "Custom Cursor");
    vars.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &vars.img_width, &vars.img_height);
    if (vars.img == NULL)
    {
        printf("Failed to load image\n");
        return 1;
    }

    mlx_hook(vars.win, 6, 1L << 6, mouse_move, &vars);
    mlx_loop(vars.mlx);
    return 0;
}