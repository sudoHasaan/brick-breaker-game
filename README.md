# 🧱 Brick Breaker Game

A classic arcade-style brick breaker game built with **C++** and **OpenGL/GLUT**, featuring multiple levels, dynamic power-ups, and smooth gameplay mechanics.

---

## ✨ Features

- 🎮 **3 Challenging Levels** - Each with unique brick layouts and increasing difficulty
- 🎁 **Power-Up System** - Collect falling power-ups to gain advantages:
  - 🟢 **Green Triangle** - Increase paddle size
  - 🔴 **Red Triangle** - Decrease paddle size
  - 🟡 **Yellow Triangle** - Slow down ball speed
  - 🔵 **Blue Triangle** - Increase ball speed
  - 🩷 **Pink Triangle** - Add extra ball
- 🏆 **Score Tracking** - Real-time scoring with persistent high score storage
- 🎯 **Multiple Balls** - Manage multiple balls simultaneously
- 🎨 **Colorful Graphics** - Vibrant brick colors indicating different hit points
- 🕹️ **Dual Paddle Mode** - Control two paddles in Level 3 for extra challenge

---

## 🎯 How to Play

1. **Objective**: Destroy all bricks by bouncing the ball off your paddle
2. **Lives**: Each brick has 1-3 lives (indicated by color)
3. **Power-ups**: Catch falling triangular power-ups for special abilities
4. **Win Condition**: Clear all bricks to advance to the next level
5. **Lose Condition**: Don't let the ball fall below your paddle!

---

## 🛠️ Requirements

- **C++ Compiler** (g++ recommended)
- **OpenGL** libraries
- **GLUT/FreeGLUT** library
- **X11** development libraries (Linux)

---

## 📦 Installation

### Linux (Ubuntu/Debian)

Install required dependencies:

```bash
sudo apt-get update
sudo apt-get install build-essential libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev libx11-dev
```

### Build the Game

Compile using the provided Makefile:

```bash
make
```

### Run the Game

Execute the compiled binary:

```bash
./game
```

---

## 🎮 Controls

| Key | Action |
|-----|--------|
| **← →** or **A D** | Move paddle left/right |
| **Space** | Launch ball / Pause game |
| **Mouse** | Navigate menus and select levels |

---

## 📁 Project Structure

```
brick-breaker/
├── game.cpp          # Main entry point, GLUT initialization, game loop
├── header.h          # Core game classes and logic
│   ├── Food          # Power-up objects
│   ├── Brick         # Brick entities with lives and colors
│   ├── Paddle        # Paddle controller
│   ├── Ball          # Ball physics and movement
│   ├── Stages        # Level generation (Stage1, Stage2, Stage3)
│   └── Game          # Main game manager
├── util.cpp          # OpenGL drawing utilities
├── util.h            # Utility function declarations
├── CImg.h            # Image library header (third-party)
├── Makefile          # Build configuration
├── Score.txt         # High score persistence
└── README.md         # This file
```

---

## 🎨 Level Design

### Level 1
- **50 bricks** arranged in a symmetric pattern
- **1 paddle** at the bottom
- **Difficulty**: Beginner-friendly

### Level 2
- **51 bricks** with varied hit points
- **1 paddle** at the bottom
- **Difficulty**: Intermediate

### Level 3
- **80 bricks** in a diamond/hourglass formation
- **2 paddles** (top and bottom)
- **Difficulty**: Advanced challenge

---

## 🔧 Technical Details

### Architecture
- **Object-Oriented Design**: Modular classes for game entities
- **OpenGL Rendering**: Hardware-accelerated graphics
- **Collision Detection**: Precise ball-brick and ball-paddle collision algorithms
- **State Management**: Menu system, level progression, game over handling

### Key Classes
- **`Game`**: Central game controller managing state, rendering, and updates
- **`Brick`**: Individual brick with position, lives, color, and embedded power-up
- **`Paddle`**: Player-controlled paddle with dynamic sizing
- **`Ball`**: Physics-based ball with velocity and collision response
- **`Stages`**: Abstract level generator with concrete implementations

### Collision System
- **Brick Collision**: Detects ball contact from all sides (top, bottom, left, right)
- **Paddle Collision**: Reflects ball based on impact position
- **Power-up Collision**: Catches falling items with paddle

---

## 🚀 Future Enhancements

- [ ] Add sound effects and background music
- [ ] Implement more power-up types
- [ ] Add difficulty settings
- [ ] Create level editor
- [ ] Add particle effects for brick destruction
- [ ] Implement leaderboard with player names

---

## 🐛 Known Issues

- None currently reported! If you find any, please create an issue.
