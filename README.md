# Lab 11 - Mappy Side Scroller

## Description

This project is a side-scrolling game made with Allegro 5 and Mappy. The player starts at the beginning of a custom Mappy map and moves through the level to reach an endpoint. When the player reaches the endpoint tile, the game displays a message showing how long it took to complete the level.

## Features

- Custom Mappy level loaded from `lab11.fmp`
- Side-scrolling camera that follows the player
- Solid collision tiles for floors, walls, ceilings, and platforms
- Ceiling collision to stop the player from jumping above the map
- Jump-through style platforms using different collision settings
- Background/decorative tiles with no collision
- Animated tiles created in Mappy
- Endpoint tile using `user1 = 8`
- Completion message with final time
- Player movement and jumping animation

## Controls

- Left Arrow: Move left
- Right Arrow: Move right
- Spacebar: Jump
- Escape: Quit the game

## Files Used

- `Source.cpp` - Main game loop, Allegro setup, map loading, timer, and endpoint handling
- `SpriteSheet.cpp` - Player movement, drawing, jumping, and collision behavior
- `SpriteSheet.h` - Sprite class definition
- `mappy_A5.c` / `mappy_A5.h` - Mappy support files
- `lab11.fmp` - Custom Mappy level
- `guy.bmp` - Player sprite
- Tile image files - Used for the map, background tiles, collision tiles, and animated blocks

## How the Level Works

The level uses collision tiles to control where the player can walk, jump, and stop. Solid tiles have collision boxes checked in Mappy. Background tiles do not have collision, so they are only decorative.

The game also uses a separate head collision check so the player cannot jump through true ceiling blocks. This prevents the player from jumping above the top of the level.

Animated tiles were created in Mappy and placed several times in the level. The game updates the map animations during the timer event.

The endpoint tile has its `user1` value set to `8`. When the player touches this tile, the game records the final time, stops the level, and displays a completion message.

## Completion Message

When the player reaches the end of the map, the screen displays:

`Level completed in X seconds`

where `X` is the amount of time it took to finish the level.

## Author

Christian Toliver
