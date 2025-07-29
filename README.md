# so\_long

![Language](https://img.shields.io/badge/language-C-blue)
![Status](https://img.shields.io/badge/build-passing-brightgreen)

`so_long` is a graphical 2D game built using the MiniLibX graphics library. The objective is to collect all collectables and reach the exit while navigating a map defined in a `.ber` file. The project emphasizes graphics rendering, keyboard input handling, memory management, map parsing, and full gameplay mechanics.

---

## 📌 Table of Contents

* [About](#about)
* [Features](#features)
* [How to Compile](#how-to-compile)
* [Usage](#usage)
* [Map Format](#map-format)
* [Project Structure](#project-structure)
* [Game Flow](#game-flow)
* [Code Snippets](#code-snippets)
* [Learnings](#learnings)
* [License](#license)

---

## 📖 About

This project teaches:

* Basics of graphics programming via MiniLibX.
* Map validation and parsing from file.
* Handling keyboard input and movement updates.
* Managing and displaying `.xpm` textures.
* Game state management and graceful cleanup on exit.
* Recursive algorithms (e.g., flood-fill) to validate map solvability.

---

## ✨ Features

* Full support for `.ber` maps.
* Player can move using `WASD` or arrow keys.
* Movement counter displayed after each step.
* Must collect all `C` items to unlock `E` (the exit).
* Map validated on startup for:

  * Rectangular shape.
  * Fully enclosed by walls.
  * Only valid characters (`01CEP`).
  * At least one of each: Player, Exit, Collectable.
  * Valid path from player to all collectables and to the exit.
* Graceful error handling with informative messages.
* Memory management: all allocations are freed on exit.

---

## ⚙️ How to Compile

Make sure MiniLibX is installed and accessible.

```bash
make
```

This will produce the executable `so_long`.

To clean up:

```bash
make clean     # Removes object files
make fclean    # Removes object files and the binary
make re        # Full rebuild
```

---

## 🕹️ Usage

```bash
./so_long maps/valid_maps/map1.ber
```

Controls:

* `W` or `↑`: Move up
* `A` or `←`: Move left
* `S` or `↓`: Move down
* `D` or `→`: Move right
* `ESC`: Exit the game

After each move, the number of steps taken is displayed in the terminal. When the player reaches the exit after collecting all items, a victory message is printed.

---

## 🗺️ Map Format

* The map must be a file with `.ber` extension.
* Acceptable characters:

  * `1`: Wall (impassable)
  * `0`: Ground (walkable)
  * `P`: Player's starting position
  * `E`: Exit
  * `C`: Collectable

### Example map:

```
111111
1P0C01
100001
1C0E11
111111
```

---

## 📁 Project Structure

```bash
.
├── src/                      # Game logic and rendering
├── inc/so_long.h             # Header file with all declarations
├── textures/                 # .xpm images for rendering
├── maps/valid_maps/          # Valid test maps
├── maps/invalid_maps/        # Maps that trigger validation errors
├── ft_printf/                # Custom printf implementation
├── get_next_line/            # GNL for reading map files
├── mlx/                      # MiniLibX library
├── Makefile
└── so_long                   # Compiled binary
```

---

## 🔁 Game Flow

1. **Startup:**

   * Checks argument count and map extension.
   * Opens and parses the `.ber` map file.
   * Validates map shape, contents, and solvability.

2. **Initialization:**

   * Loads `.xpm` textures for each tile type.
   * Creates a window using MiniLibX.

3. **Gameplay Loop:**

   * Player moves using keyboard.
   * Each valid move updates the map and redraws the screen.
   * Move count is printed.
   * If player reaches the exit with all collectables: game ends.

4. **Cleanup:**

   * Frees all memory and closes the window.

---

## 👀 Code Snippets

### 🧩 Handling Key Presses

```c
int key_handler(int keycode, t_game *game) {
    if (keycode == ESC)
        exit_game(game);
    if (keycode == W || keycode == UP)
        keyboard_up_down(game, keycode);
    if (keycode == S || keycode == DOWN)
        keyboard_up_down(game, keycode);
    if (keycode == A || keycode == LEFT)
        keyboard_left_right(game, keycode);
    if (keycode == D || keycode == RIGHT)
        keyboard_left_right(game, keycode);
    return 0;
}
```

### 🔍 Map Rectangular Validation

```c
static void check_rectangular(t_game *game) {
    int len = get_width(game->map[0]);
    for (int i = 0; game->map[i]; i++) {
        if (get_width(game->map[i]) != len) {
            ft_printf("Error\nThe map should be rectangular.\n");
            exit(1);
        }
    }
}
```

---


## 📚 Learnings

* How to use MiniLibX to load windows, images, and handle input.
* Pathfinding and map validation using recursive DFS.
* Importance of memory safety and error handling in C.
* Structuring medium-sized C projects with clear module separation.
* Testing rigorously with both valid and invalid input files.

---

## 📄 License

This project is part of the 42 School curriculum and is intended for educational use only.

---

## 💬 Questions?

Feel free to reach out for questions, improvements, or suggestions!
