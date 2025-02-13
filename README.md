# so_long

![Game Screenshot](game_screenshot.gif)

## Description
**so_long** is a small 2D game developed using the **MiniLibX** library. This project serves as an introduction to game development concepts such as textures, sprites, and tile-based maps.

In the game, the player controls a brave **knight** who must collect all the **mushrooms** before reaching the exit to return home. Various textures are used for different game elements, including the knight, mushrooms, walls, floor, and exit.

This project utilizes the **school graphical library: MiniLibX**, which was developed internally and includes the basic necessary tools to open a window, create images, and handle keyboard and mouse events.

## Theme
The game follows the journey of a courageous **knight** who is lost in an enchanted forest. To find his way back home, he must **gather all the magical mushrooms scattered across the land**. Only after collecting every mushroom will the hidden path to his home be revealed. Beware of the obstacles and navigate carefully to achieve victory!

## Features
- **Textures**: Different textures enhance the game's visual appeal.
- **Sprites**: The player (knight) and interactive elements (mushrooms, exit, etc.) are represented as sprites.
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
    ├── knight.xpm                 # Player texture
    ├── mushroom.xpm               # Collectible texture
    ├── exit.xpm                   # Exit texture
    ├── floor.xpm                  # Floor texture
    ├── wall.xpm                   # Wall texture
maps/                              # Sample maps (valid and invalid for testing)
main.c                             # Main entry point of the game
Makefile                           # Build script
```

## How to Run
### Clone the repository:
```sh
git clone <repository_url>
```
### Navigate to the project directory:
```sh
cd so_long
```
### Build the project:
```sh
make
```
### Run the game with a map file:
```sh
./so_long [map_file]
```
Enjoy playing!

## Map Requirements
- The map must consist of walls, mushrooms, and free spaces.
- The map can contain only the following characters:
  - `0` for an empty space
  - `1` for a wall
  - `C` for a **mushroom** (collectible)
  - `E` for the **exit**
  - `P` for the **knight's starting position**
- The map must contain exactly **one exit (E)**, at least **one collectible (C)**, and exactly **one player starting position (P)**.
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

Enjoy your adventure as the **knight** who must collect all the **mushrooms** before finding the way home!
