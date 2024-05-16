# Oficial documentation
https://harm-smits.github.io/42docs/libs/minilibx/colors.html

# Get started
MiniLibX for Linux requires xorg, x11 and zlib, therefore you will need to install the following dependencies: xorg, libxext-dev and zlib1g-dev. Installing these dependencies on Ubuntu can be done as follows:
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

## How to compile 

```
gcc FILE libmlx.a -lXext -lX11 -lm -lz -lbsd
```


## Start map
- To start the connection with the graphical server:
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

