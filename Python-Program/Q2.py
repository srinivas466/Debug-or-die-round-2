def solve_maze(maze, x, y, path):
    if x < 0 or y < 0 or x >= len(maze) or y >= len(maze[0]):
        return False
    if maze[x][y] == 1 or maze[x][y] == "X":
        return False
    if (x, y) == (len(maze)-1, len(maze[0])-1):
        path.append((x, y))
        return True

    maze[x][y] = "X"  # Mark as visited

    if solve_maze(maze, x+1, y, path):
        path.append((x, y))
        return True
    elif solve_maze(maze, x, y+1, path):
        path.append((x, y))
        return True
    elif solve_maze(maze, x-1, y, path):
        path.append((x, y))
        return True
    elif solve_maze(maze, x, y-1, path):
        path.append((x, y))
        return True

    return False

maze = [
    [0, 0, 1, 0],
    [1, 0, 1, 0],
    [0, 0, 0, 0],
    [0, 1, 1, 0]
]

path = []
if solve_maze(maze, 0, 0, path):
    print("Path to exit:", reversed(path))
else:
    print("No path found.")