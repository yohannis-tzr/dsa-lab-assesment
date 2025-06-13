#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); // Size of the square grid

        // If the starting or ending cell is blocked, there's no valid path.
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
            return -1;
        }

        // Directions to move in all 8 ways: up/down/left/right + diagonals
        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0, -1},          { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1}
        };

        // Queue to keep track of cells we can visit, starting from (0, 0)
        queue<pair<int, int>> toVisit;
        toVisit.push({0, 0});

        // Mark the starting cell as visited by changing its value to 1
        // This also serves as the path length to reach that cell
        grid[0][0] = 1;

        // Start BFS traversal
        while (!toVisit.empty()) {
            auto [row, col] = toVisit.front();
            toVisit.pop();
            int steps = grid[row][col]; // Steps taken to reach current cell

            // If we've reached the bottom-right cell, return the path length
            if (row == n - 1 && col == n - 1) {
                return steps;
            }

            // Explore all 8 directions from the current cell
            for (auto [dr, dc] : directions) {
                int newRow = row + dr;
                int newCol = col + dc;

                // Check if the new position is within bounds and not visited
                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == 0) {
                    
                    // Mark the cell as visited with updated step count
                    grid[newRow][newCol] = steps + 1;

                    // Add it to the queue to visit later
                    toVisit.push({newRow, newCol});
                }
            }
        }

        // If we finish BFS without reaching the bottom-right, there's no path
        return -1;
    }
};
