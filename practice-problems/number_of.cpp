#include <vector>
#include <cstring>
#include <functional>

class Solution {
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected) {
        // Get the number of cities (nodes).
        int cities = isConnected.size();
      
        // Initialize the count of provinces (initially no connection is found).
        int provinceCount = 0;
      
        // Visited array to keep track of the visited cities.
        bool visited[cities];
      
        // Initialize all cities as unvisited.
        std::memset(visited, false, sizeof(visited));
      
        // Define depth-first search (DFS) as a lambda function.
        std::function<void(int)> dfs = [&](int cityIndex) {
            // Mark the current city as visited.
            visited[cityIndex] = true;
          
            // Visit all the cities connected to the current city.
            for (int j = 0; j < cities; ++j) {
                // If the city is not visited and is connected, perform DFS on it.
                if (!visited[j] && isConnected[cityIndex][j]) {
                    dfs(j);
                }
            }
        };
      
        // Iterate over each city to count the number of provinces.
        for (int i = 0; i < cities; ++i) {
            // If the city is not yet visited, it is part of a new province.
            if (!visited[i]) {
                dfs(i); // Perform DFS to visit all cities in the current province.
                ++provinceCount; // Increment the count of provinces.
            }
        }
      
        // Return the total number of provinces found.
        return provinceCount;
    }
};