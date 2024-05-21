# MiniLibX Documentation
Official documentation: https://harm-smits.github.io/42docs/libs/minilibx/colors.html

# Get started
MiniLibX for Linux requires xorg, x11, and zlib. Therefore, you will need to install the following dependencies: xorg, libxext-dev, and zlib1g-dev. Installing these dependencies on Ubuntu can be done as follows:
```
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```

# Map
The map must be composed of only 5 possible characters: 
- 0 for an empty space
- 1 for a wall
- C for a collectible
- E for map exit 
- P for the player’s starting position

# Functions

## Compiling

```
gcc FILE libmlx.a -lXext -lX11 -lm -lz -lbsd
```

## Start map

- To start the connection with the graphical server and create a window:

```
int main()
{
    void *mlx_connection;
    void *mlx_window;

    mlx_connection = mlx_init(); // Starts the connectoon with the graphical server, returns a pointer to the connection
    mlx_window = mlx_new_window(mlx_connection, 500, 500, "First window"); // Creates the window (connection, width, height, window_name) 
    
    mlx_loop(mlx_connection); // Creates a loop so the program doesn't exit immediatly
} 
```

# Starting filling the map

- The function mlx_pixel_put() allows you to fill a pixel. It takes the following parameters:

1. The connection created in mlx_init()
2. The window created in mlx_new_window()
3. An x-coordinate
4. A y-coordinate
5. Color (look at the RGB chart to try different colors - https://www.rapidtables.com/web/color/RGB_Color.html)

```
mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color)
```

## Design a 50x50 square in the center

```
int x = 225;
    int y;
    while (x < 275)
    {
        y = 225;
        while (y < 275)
        {
            mlx_pixel_put(
                mlx_connection, 
                mlx_window, 
                x, 
                y, 
                (255,255,255)
            );
            y++;
        }
        x++;
    }
```

## Dynamic assignment:

```
int x = WIDTH * 0.4;
    int y;
    while (x  < WIDTH * 0.6)
    {
        y = HEIGHT * 0.4;
        while (y < HEIGHT * 0.6)
        {
            mlx_pixel_put(
                mlx_connection, 
                mlx_window, 
                x, 
                y, 
                (255,255,255)
            );
            y++;
        }
        x++;
    }
```

## All functions

1. mlx_init(); // Starts the connectoon with the graphical 
2. mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title) // Creates the window (connection, width, height, window_name) 
3. int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color) // fill pixel
4. mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string); // Insert string
5. mlx_loop(void *mlx_ptr) // Creates a loop so the program doesn't exit immediatly

