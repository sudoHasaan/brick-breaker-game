# Brick Breaker Game

A classic brick breaker game implemented in C++ using OpenGL.

## Features

- 3 exciting levels with different brick patterns
- Power-ups system (paddle size, ball speed, extra balls)
- Score tracking with high score persistence
- Multiple balls support
- Smooth graphics and gameplay

## Requirements

- C++ compiler (g++)
- OpenGL libraries
- GLUT library
- X11 development libraries

## Installation

### Linux (Ubuntu/Debian)

Install required dependencies:
```bash
sudo apt-get update
sudo apt-get install build-essential libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev libx11-dev
```

## Build

Compile the game using the provided Makefile:
```bash
make
```

## Run

Execute the game:
```bash
./game
```

## Controls

- **Arrow Keys / A,D**: Move paddle left/right
- **Space**: Launch ball / Pause game
- **Mouse**: Navigate menus

## Gameplay

- Break all the bricks to complete each level
- Catch power-ups that fall from destroyed bricks:
  - **Green Triangle**: Increase paddle size
  - **Red Triangle**: Decrease paddle size  
  - **Yellow Triangle**: Slow down ball
  - **Blue Triangle**: Speed up ball
  - **Pink Triangle**: Add extra ball
- Don't let the ball fall below the paddle!
- In Level 3, control two paddles simultaneously

## Project Structure

- `game.cpp` - Main game loop and GLUT setup
- `header.h` - Game classes (Food, Brick, Paddle, Ball, Stages, Game)
- `util.cpp` - Utility functions for drawing shapes
- `util.h` - Utility function declarations
- `Makefile` - Build configuration
- `Score.txt` - High score storage

## Author

Muhammad Hasaan (23i-0094)

## License

Educational project - Free to use and modify
