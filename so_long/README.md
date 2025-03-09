# So Long

## Overview

The `so_long` project is a simple 2D game using the MinilibX library. The objective of the game is to collect all the collectibles and reach the exit. I had to learn about textures, sprites and tiles and was the first time I had to parse a file with specific rules. I used textures and sprites from [The Binding of Isaac](https://store.steampowered.com/app/113200/The_Binding_of_Isaac/).

## Features

- 2D graphics using the MinilibX library
- Player movement
- Collectibles
- Exit to complete the level

## Controls

- `W`: Move up
- `A`: Move left
- `S`: Move down
- `D`: Move right
- `ESC`: Exit the game

## Usage

To compile the project, run:

```sh
make
```

To run the game, use:

```sh
./so_long [map_file]
```

Example:

```sh
./so_long map.ber
```

##Map File

The map file should be a '.ber' file containing the layout of the game level. The map should be rectangular and composed of the following characters:

- `1`: Wall
- `0`: Empty space
- `P`: Player start position (has to be unique)
- `C`: Collectible
- `E`: Exit (has to be unique)

Example map file (map.ber):
```
111111111111111
100000000000001
100010000010001
101010010010001
1P1C0CCECC00101
100010010010101
100010000010001
100000000000001
111111111111111
```

## Ressources

- [MinilibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
