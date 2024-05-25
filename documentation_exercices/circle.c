#include "../minilibx/mlx.h"
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_circle(t_data *data, int x_center, int y_center, int radius, int color) {
    int x, y;
    int x_start = x_center - radius;
    int y_start = y_center - radius;
    int x_end = x_center + radius;
    int y_end = y_center + radius;

    y = y_start;
    while (y <= y_end) {
        x = x_start;
        while (x <= x_end) {
            int dx = x - x_center;
            int dy = y - y_center;
            if (dx * dx + dy * dy <= radius * radius) {
                my_mlx_pixel_put(data, x, y, color);
            }
            x++;
        }
        y++;
    }
}
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 800, "Hello world!");
	img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// Draw circle
	draw_circle(&img, 400, 400, 100,  0x00FF0000);



	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

