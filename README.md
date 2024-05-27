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

```bash
gcc FILE libmlx.a -lXext -lX11 -lm -lz -lbsd
```

## Start map

- To start the connection with the graphical server and create a window:

```c
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

```c
mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color)
```

## Design a 50x50 square in the center

```c
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

```c
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

## Colors

Colors are presented in an int format
In minilibx, colors are represented as integers using the TRGB format. TRGB stands for Transparency (T), Red (R), Green (G), and Blue (B). Each component is represented by 8 bits, allowing a range of values from 0 to 255.
To define a color in TRGB format, you can use the following notation: 0xTTRRGGBB. Here's what each letter represents:

**INT is 4 bytes so each one of this ocupies one byte:**

- T: Transparency (0 = fully opaque, 255 = fully transparent)
- R: Red component (0 = no red, 255 = full red)
- G: Green component (0 = no green, 255 = full green)
- B: Blue component (0 = no blue, 255 = full blue)

For example, to represent the color red, you would use 0x00FF0000. Similarly, green would be 0x0000FF00, and blue would be 0x000000FF.
Encoding and Decoding Colors
To work with colors effectively, you need to understand how to encode and decode them. There are two common methods for this: bitshifting and char/int conversion.

Bitshifting:
Bitshifting is a technique used to manipulate the individual components of a color. Since each component occupies 8 bits (1 byte) and an integer is 4 bytes, we can use bitshifting to set and extract the values.
Here's an example function that creates a TRGB color using bitshifting:

```c
int create_trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}
```


## Events

mlx_hook allows us to register ecents with the call od a simple hook registration fucntion 

```c
// Prototype
void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)

// Real one
mlx_hook(vars.win, 2, 1L<<0, close_window, &vars);
```

Minilibx api has some alias hooking function:

- mlx_expose_hook function is an alias of mlx_hook on expose event (12).
- mlx_key_hook function is an alias of mlx_hook on key up event (3).
- mlx_mouse_hook function is an alias of mlx_hook on mouse down event (4).

Full example of a function that closes the window when ESC is pressdown

```c
typedef struct s_vars {
    void *mlx;
    void *win;
} t_vars;

int close_window(int keycode, t_vars *vars) {
    if (keycode == 65307) {  // 65307 is the keycode for ESC
        mlx_destroy_window(vars->mlx, vars->win);
    }
    return 0;
}

int main(void) {
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
    mlx_hook(vars.win, 2, 1L<<0, close_window, &vars);
    mlx_loop(vars.mlx);
    return 0;
}
```

## Loop

To render images we use 2 functions mlx_loop and mlx_loop_hook.

```c
    int render_next_frame(void *YourStruct);

    int main(void)
    {
        void    *mlx;

        mlx = mlx_init();
        mlx_loop_hook(mlx, render_next_frame, YourStruct);
        mlx_loop(mlx);
    }
```

## Images

To read from a file:
- XMP use **mlx_xpm_file_to_image**
- PNG use **mlx_png_file_to_image**, but this functions leaks memory, so its better use XMP files.

## Test

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long "maps/map1.ber"
```