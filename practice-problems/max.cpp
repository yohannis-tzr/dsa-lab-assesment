#include <vector>
#include <functional> // For std::function
#include <algorithm>  // For std::max

class Solution {
public:
    // Function to find the maximum area of an island in a given grid
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        // Obtain the number of rows and columns of the grid
        int rows = grid.size(), cols = grid[0].size();
        // Directions array to explore all 4 neighbors (up, right, down, left)
        int directions[5] = {-1, 0, 1, 0, -1};
        // Variable to store the final maximum area of island found
        int maxArea = 0;
      
        // Depth-first search function using lambda and std::function for ease of recursion
        std::function<int(int, int)> depthFirstSearch = [&](int i, int j) -> int {
            // Base case: if the current cell is water (0), return 0 area
            if (grid[i][j] == 0) {
                return 0;
            }
          
            // Mark the current cell as visited by setting it to 0 and start counting the area from 1
            int area = 1;
            grid[i][j] = 0;
          
            // Explore all 4 neighbor directions
            for (int k = 0; k < 4; ++k) {
                int x = i + directions[k], y = j + directions[k + 1];
                // Check if the neighbor coordinates are within grid bounds
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    // Increment the area based on this recursive depth-first search
                    area += depthFirstSearch(x, y);
                }
            }
            // Return the area found for this island
            return area;
        };
      
        // Iterate over all cells in the grid
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // Update maxArea with the maximum between current maxArea and newly found area
                maxArea = std::max(maxArea, depthFirstSearch(i, j));
            }
        }
      
        // Return the maximum area of island found in the grid
        return maxArea;
    }
};