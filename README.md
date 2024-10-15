# C++ "Align 5" game

This guide provides instructions to compile and run the C++ program on **Windows**, **Mac**, and **Linux** platforms.

## Table of Contents

- [Overview](#overview)
- [Execution on Windows](#execution-on-windows)
- [Execution on Mac or Linux](#execution-on-mac-or-linux)
- [Dependencies](#dependencies)

## Overview

This project is a **C++ implementation of an "Align 5" game**, where two players take turns placing markers on a game board. The objective is to align five markers horizontally, vertically, or diagonally before the opponent. 
The game features multiple components such as a game board (`plateau.cpp`), player interactions (`joueur.cpp`), and game logic (`jeu.cpp`). These files are compiled together to form the complete game.

The source files include:
- `main.cpp`
- `plateau.cpp`
- `joueur.cpp`
- `jeu.cpp`

## Execution on Windows

To compile and run the program on Windows, follow these steps:

1. **Open the Command Prompt**:
   - Press `Win + R`, type `cmd`, and press Enter.

2. **Navigate to the Project Directory**:
   - In the Command Prompt, type the following command, replacing `[Path to the folder]` with the path to your project directory:
   ```bash
   cd [Path to the folder]
   ```
   Example:
   ```bash
   cd C:/Users/Username/Desktop/TP_C++
   ```

3. **Compile the Program**:
   - Run the following command to compile the program:
   ```bash
   g++ -o main main.cpp plateau.cpp joueur.cpp jeu.cpp -mconsole
   ```

4. **Run the Program**:
   - After the compilation, an `main.exe` file will be generated in the project folder.
   - Simply double-click on `main.exe` to run the program.

## Execution on Mac or Linux

For Mac or Linux, you will need to use the terminal to compile and run the program.

1. **Open Terminal**:
   - On Mac, use Spotlight (`Cmd + Space`) and search for "Terminal".
   - On Linux, open the terminal from your applications or by using `Ctrl + Alt + T`.

2. **Navigate to the Project Directory**:
   - Use the following command, replacing `[Path to the folder]` with the path to your project directory:
   ```bash
   cd [Path to the folder]
   ```
   Example:
   ```bash
   cd C:/Users/Username/Desktop/TP_C++
   ```

3. **Compile the Program**:
   - Run the following command to compile the C++ source files:
   ```bash
   g++ -o main main.cpp plateau.cpp joueur.cpp jeu.cpp -mconsole
   ```

4. **Run the Program**:
   - Once the program is compiled, run it by typing:
   ```bash
   ./main
   ```

## Dependencies

- **g++ Compiler**: Make sure you have the GNU C++ compiler installed. If not, you can install it:
  - On Windows, use **MinGW** (Minimalist GNU for Windows).
  - On Mac, use **Xcode Command Line Tools** (`xcode-select --install`).
  - On Linux, use the following command:
    ```bash
    sudo apt-get install g++
    ```
