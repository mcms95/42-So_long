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

unsigned char	get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int add_shade(double distance, int color)
{
    unsigned char t = get_t(color);
	unsigned char r = (unsigned char)(get_r(color)) * ( 1 - distance);
	unsigned char g = (unsigned char)(get_g(color)) * ( 1 - distance);
	unsigned char b = (unsigned char)(get_b(color)) * ( 1 - distance);
	return create_trgb(t, r, g, b);

}

void draw_square(t_data *data, int x, int y, int size, int color)
{
	int i, j;
	i = y;

	while (i < y + size)
	{
		j = x;
		while( j < x + size)
		{
			my_mlx_pixel_put(data, j, i, color);
			j++;
		}
		i++;
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
								
	// Add shade
	int color = 0x00FF8000; // Orange
	double distance = 0.5;

	int new_color = add_shade( distance,  color);
	draw_square( &img,  100, 100, 600, new_color);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
