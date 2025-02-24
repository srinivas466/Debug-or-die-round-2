public class MazeSolver {
    static int[][] maze = {
        {0, 0, 1, 0},
        {1, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 1, 1, 0}
    };

    public static boolean solveMaze(int x, int y) {
        if (x < 0 || y < 0 || x >= maze.length || y >= maze[0].length)
            return false;
        if (maze[x][y] == 1 || maze[x][y] == 2) // Marked visited with 2
            return false;
        if (x == maze.length && y == maze[0].length) // Off-by-one error: should be maze.length-1
            return true;

        maze[x][y] = 2; // Mark cell as visited

        if (solveMaze(x + 1, y) || solveMaze(x, y + 1) || solveMaze(x - 1, y) || solveMaze(x, y - 1)) {
            System.out.println("Path: (" + x + "," + y + ")");
            return true;
        }

        return false; // No backtracking to unmark visited cells
    }

    public static void main(String[] args) {
        if (solveMaze(0, 0))
            System.out.println("Path found!");
        else
            System.out.println("No path found.");
    }
}