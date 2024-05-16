#include "minilibx/mlx.h"


int main()
{
    void *mlx_connection;
    void *mlx_window;

    mlx_connection = mlx_init();
    mlx_window = mlx_new_window(mlx_connection, 500, 500, "First window");
    
    mlx_loop(mlx_connection);
}