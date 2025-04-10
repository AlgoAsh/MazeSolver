
# MazeSolver - Pathfinding Algorithm Visualizer & Benchmark Tool

MazeSolver is a C++ project that tests and compares various pathfinding algorithms on 2D mazes. It visualizes the working of algorithms and provides benchmark results to compare their efficiency.

> Perfect for learning how different pathfinding algorithms behave in a grid-based maze!

---

## Features
- Generate random mazes or use pre-saved mazes
- Visualize the solving process
- Compare algorithms based on execution time and steps taken
- Supports multiple pathfinding algorithms:
  - BFS (Breadth First Search)
  - DFS (Depth First Search)
  - A* Algorithm
  - Dijkstra's Algorithm
- CLI Interface for interaction
- Windows-based console application

---

## Tech Stack
- C++
- OOP Concepts
- Windows Terminal (Command Line)

---

## Project Structure

```
MazeSolver/
├── Generator.cpp     # Maze generation logic
├── Solver.cpp        # Algorithm implementations
├── main.cpp          # Entry point & CLI interface
├── maze/             # Folder containing pre-saved maze files
│   ├── maze1.txt
│   ├── maze2.txt
│   └── ...
├── README.md
```

---

## Setup & Run

### 1. Clone the repository
```bash
git clone https://github.com/AshutoshThings/MazeSolver.git
cd MazeSolver
```

---

## 2. Compile

Use any C++ compiler:

```bash
g++ main.cpp Generator.cpp Solver.cpp -o MazeSolver
```

---

## 3. Run the Program

```bash
./main
```

---

## 4. Usage

- Select from:
  - Generate Random Maze
  - Load Maze from File
- Choose Pathfinding Algorithm
- Watch the visualization
- View Results: Steps taken, Time taken

---

## Example Maze File Format
Each maze file should follow this pattern:

- 'S' -> Start Point
- 'E' -> End Point
- '#' -> Wall
- ' ' (space) -> Open Path

Example:
```
#########
#S#   #E#
# # # # #
#       #
#########
```

---
## In Progress 🚧

This project is still under development. Contributions and suggestions are welcome!

---

Made with ❤️ by [AshutoshThings](https://github.com/AshutoshThings)
