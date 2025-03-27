# Tetris Game in C++

## 📜 Overview
This is a simple command-line Tetris game written in C++ that runs in the Windows console. The game includes basic Tetris mechanics such as piece movement, rotation, line clearing, scoring, and levels.

## 🎮 Features
- Classic Tetris gameplay with seven tetrominoes (I, O, T, S, Z, L, J)
- Random tetromino generation
- Collision detection and line clearing
- Increasing difficulty with levels
- Score tracking
- Simple keyboard controls
- Console color support for different tetrominoes

## 🛠️ Installation & Compilation
### Prerequisites
- Windows OS (required for `conio.h` and `windows.h` dependencies)
- A C++ compiler such as MinGW (for `g++`)

### Compilation
To compile the game, use the following command:
```sh
 g++ tetris_decoders.cpp -o tetris.exe -std=c++11
```

### Running the Game
Once compiled, run the executable:
```sh
 ./tetris.exe
```

## ⌨️ Controls
- `A` → Move Left
- `D` → Move Right
- `W` → Rotate Piece
- `S` → Soft Drop
- `ESC` → Exit the game

## 📜 Game Rules
1. The game starts with an empty board.
2. Random tetrominoes fall from the top.
3. Players move and rotate the tetrominoes to fit them efficiently.
4. Completing a horizontal line clears that line and increases the score.
5. The game gets faster as the level increases.
6. The game ends when the tetrominoes stack to the top of the board.

## 🖥️ Code Structure
- `struct Tetromino` → Defines tetromino shape, color, and rotation
- `InitializeBoard()` → Initializes the game board
- `DrawBoard()` → Renders the game board in the console
- `CreateTetromino()` → Generates a random tetromino
- `CheckCollision()` → Checks if a move is valid
- `PlacePiece()` → Locks the current piece in place
- `ClearLines()` → Removes full lines and updates the score
- `Input()` → Reads player input
- `Update()` → Updates the game state per frame

## 🔧 Possible Improvements
- Implementing a graphical UI using SDL or SFML
- Adding a hold piece feature
- Implementing ghost pieces for better positioning
- Multiplayer mode
- Sound effects and music

Enjoy the game! 🎮

