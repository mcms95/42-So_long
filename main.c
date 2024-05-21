#include "minilibx/mlx.h"
#include <stdlib.h>

#define WIDTH 500
#define HEIGHT 500

int main()
{
    void *mlx_connection;
    void *mlx_window;

    mlx_connection = mlx_init(); // Start the connection, this return a structure t_xvar type
    // WE are also malloc this big stucture where display is

    mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "First window");      // Open the window, it returns a struct with memory allocated
    
    int x = WIDTH * 0.1;
    int y;
    while (x  < WIDTH * 0.9)
    {
        y = HEIGHT * 0.1;
        while (y < HEIGHT * 0.9)
        {
            mlx_pixel_put(
                mlx_connection, 
                mlx_window, 
                x, 
                y, 
                rand() % 0x1000000);
            y++;
        }
        x++;
    }
    mlx_string_put(
                mlx_connection, 
                mlx_window, 
                420, 
                480, 
                rand()% 0x1000000,
                "My Painting");


    mlx_loop(mlx_connection);                                                   // Loop to keep window alive

    return 0;

}
