class Solution {
public:
    vector<int> parent; // Use 'parent' to represent the disjoint set union data structure.

    // Define a method to find the absolute parent (representative) of the set.
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Main function to determine if there is a valid path in the grid.
    bool hasValidPath(vector<vector<int>>& grid) {
        int rows = grid.size(); // The number of rows in the grid.
        int cols = grid[0].size(); // The number of columns in the grid.
        parent.resize(rows * cols); // Resize the 'parent' vector to fit the grid.

        // Initialize each cell's parent to itself.
        for (int i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }

        // Lambda function to connect the current cell with the cell to its left.
        auto connectLeft = [&](int row, int col) {
            if (col > 0 && (grid[row][col - 1] == 1 || grid[row][col - 1] == 4 || grid[row][col - 1] == 6)) {
                parent[find(row * cols + col)] = find(row * cols + col - 1);
            }
        };

        // Lambda function to connect the current cell with the cell to its right.
        auto connectRight = [&](int row, int col) {
            if (col < cols - 1 && (grid[row][col + 1] == 1 || grid[row][col + 1] == 3 || grid[row][col + 1] == 5)) {
                parent[find(row * cols + col)] = find(row * cols + col + 1);
            }
        };

        // Lambda function to connect the current cell with the cell above it.
        auto connectUp = [&](int row, int col) {
            if (row > 0 && (grid[row - 1][col] == 2 || grid[row - 1][col] == 3 || grid[row - 1][col] == 4)) {
                parent[find(row * cols + col)] = find((row - 1) * cols + col);
            }
        };

        // Lambda function to connect the current cell with the cell below it.
        auto connectDown = [&](int row, int col) {
            if (row < rows - 1 && (grid[row + 1][col] == 2 || grid[row + 1][col] == 5 || grid[row + 1][col] == 6)) {
                parent[find(row * cols + col)] = find((row + 1) * cols + col);
            }
        };

        // Iterate over each cell in the grid to establish connections.
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int tileType = grid[row][col];
                if (tileType == 1) {
                    connectLeft(row, col);
                    connectRight(row, col);
                } else if (tileType == 2) {
                    connectUp(row, col);
                    connectDown(row, col);
                } else if (tileType == 3) {
                    connectLeft(row, col);
                    connectDown(row, col);
                } else if (tileType == 4) {
                    connectRight(row, col);
                    connectDown(row, col);
                } else if (tileType == 5) {
                    connectLeft(row, col);
                    connectUp(row, col);
                } else { // tileType == 6
                    connectRight(row, col);
                    connectUp(row, col);
                }
            }
        }

        // Check if the start (0,0) cell has the same root as the end (rows-1,cols-1) cell.
        return find(0) == find(rows * cols - 1);
    }
};