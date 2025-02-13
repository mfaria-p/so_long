# so_long

![Game Screenshot](game_screenshot.gif)

## Description
so_long is a small 2D game developed using the MiniLibX library. This project serves as an introduction to game development concepts such as textures, sprites, and tile-based maps.

In the game, the player navigates through a map, collecting items and reaching the exit to win. Various textures are used for different game elements, including the player, collectibles, walls, floor, and exit.

This project utilizes the school graphical library: **MiniLibX**! This library was developed internally and includes the basic necessary tools to open a window, create images, and handle keyboard and mouse events.

## Features
- **Textures**: Different textures enhance the game's visual appeal.
- **Sprites**: The player and interactive elements are represented as sprites.
- **Tiles**: The game map is built using a grid of tiles, each representing a different element.

## Learning Outcomes
Through this project, I gained hands-on experience with:
- Loading and displaying textures using MiniLibX.
- Managing sprites and their interactions within the game.
- Constructing and navigating a tile-based game map.

## Project Structure
```
inc/
    ├── so_long.h                 # Header file
libraries/
    ├── libft/                     # Custom utility functions library
    ├── minilibx-linux/            # MiniLibX library for graphical functions
srcs/
    ├── error_handling/            # Error handling functions
    │   ├── errors.c
    ├── init/                      # Initialization functions
    │   ├── data_init.c
    │   ├── game_init.c
    ├── map_check/                 # Map validation functions
    │   ├── map_verifier.c
    │   ├── path_verifier.c
    │   ├── read_map.c
textures/
    ├── collectible.xpm
    ├── exit.xpm
    ├── floor.xpm
    ├── player.xpm
    ├── wall.xpm
maps/                              # Sample maps (valid and invalid for testing)
main.c                             # Main entry point of the game
Makefile                           # Build script
```

## How to Run
1. Clone the repository:
   ```sh
   git clone <repository_url>
   ```
2. Navigate to the project directory:
   ```sh
   cd so_long
   ```
3. Build the project:
   ```sh
   make
   ```
4. Run the game with a map file:
   ```sh
   ./so_long [map_file]
   ```
5. Enjoy playing!

## Map Requirements
- The map must consist of **walls, collectibles, and free spaces**.
- The map can contain only the following characters:
  - `0` for an empty space
  - `1` for a wall
  - `C` for a collectible
  - `E` for the map exit
  - `P` for the player's starting position
- The map must contain **exactly one exit (`E`)**, at least **one collectible (`C`)**, and exactly **one player starting position (`P`)**.
- The map must be **rectangular**.
- The map must be **completely surrounded by walls**. If it is not, the program will return an error.

### Example of a Valid Map:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

Enjoy your adventure in so_long!

