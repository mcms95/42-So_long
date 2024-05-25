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

void draw_gradient(t_data *data, int width, int height) {
    int x, y;
    y = 0;
    while (y < height) {
        x = 0;
        while (x < width) {
            int red = (y * 255) / height;
            int green = (x * 255) / width;
            int blue = ((height - y) * 255) / height;
            int color = (red << 16) | (green << 8) | blue;
            my_mlx_pixel_put(data, x, y, color);
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
	// Draw gradient
	draw_gradient(&img, 800, 800);



	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
