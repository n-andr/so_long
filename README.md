# so_long

## Overview

This project is part of the 42 school curriculum, where the objective is to create a simple 2D game using the MiniLibX library. The game features a player navigating through a map to collect items and reach an exit.

## Key Features

- **2D Graphics**: Utilizes the MiniLibX library for rendering graphics.
- **Interactive Gameplay**: Allows the player to move through the map, collect items, and reach the exit.
- **File Reading**: Uses the `get_next_line` function to read map files, demonstrating practical application of previous projects.

## Getting Started

Clone the repository and follow the instructions in the `Makefile` to compile and run the project.

```bash
git clone https://github.com/n-andr/so_long.git
cd so_long
make
```

If neeeded include "mlx.h"

```bash
sudo cp libmlx.a /usr/local/lib/
sudo cp mlx.h /usr/local/include/
```bash

## Usage

To play the game, run the compiled executable with a map file as an argument.

```bash
./so_long maps/valid_map.ber
```

## What I Learned

During this project, I gained experience with:

**MiniLibX Library**: Understanding and using the MiniLibX library for basic graphics rendering.

**Event Handling**: Implementing user input handling to move the player character.

**File I/O**: Reading and parsing map files using the get_next_line function.

**Game Logic**: Designing and implementing game mechanics, including item collection and win/lose conditions.

**Memory Management**: Ensuring efficient memory usage and handling dynamic memory allocation.
