# InSem2_Tetris_Decoders

# Tetris Game in C++

A simple console-based Tetris game written in C++ using Windows API for colored output and keyboard input.

## Features
- Classic Tetris gameplay
- Different Tetromino shapes
- Scoring and leveling system
- Basic game over detection
- Simple rotation mechanics

## Requirements
- Windows OS
- C++ Compiler (GCC, MSVC, or Clang)

## How to Compile and Run
1. Open a terminal or command prompt.
2. Compile the program using a C++ compiler:
   ```sh
   g++ s1+s2.cpp -o tetris.exe -static-libstdc++ -static-libgcc
   ```
3. Run the executable:
   ```sh
   ./tetris.exe
   ```

## Controls
- `A` - Move Left
- `D` - Move Right
- `W` - Rotate
- `S` - Move Down (not implemented yet)

## Preview
![Tetris Screenshot](https://via.placeholder.com/500)

## Future Improvements
- Implement `S` key for soft drop
- Add a better randomization system for Tetrominoes
- Improve collision detection
- Implement hold and preview system

## Contributing
Feel free to submit pull requests or report issues!

## License
This project is open-source under the MIT License.

