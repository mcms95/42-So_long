#include "../minilibx/mlx.h"
#include <stdio.h>

typedef struct s_vars {
    void *mlx;
    void *win;
    void *img;
    int img_width;
    int img_height;
} t_vars;


int main(void)
{
    t_vars vars;
    char *relative_path = "../images/enemy.xpm";

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 640, 480, "Custom Cursor");
    vars.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &vars.img_width, &vars.img_height);
    if (vars.img == NULL)
    {
        printf("Failed to load image\n");
        return 1;
    }
	int x;
	int y = 0;
	while(y < 480)
	{
		x = 0;
		while (x < 640)
		{
			mlx_put_image_to_window(vars.mlx, vars.win, vars.img, x, y);
			x += vars.img_width;
		}
		y += vars.img_height;
	}
    mlx_loop(vars.mlx);
    return 0;
}