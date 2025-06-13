#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        int totalRoutes = routes.size();
        vector<unordered_set<int>> stopsForRoute(totalRoutes);
        vector<vector<int>> graph(totalRoutes);
        unordered_map<int, vector<int>> stopToRoutesMap;

        for (int i = 0; i < totalRoutes; ++i) {
            for (int stop : routes[i]) {
                stopsForRoute[i].insert(stop);
                stopToRoutesMap[stop].push_back(i);
            }
        }

        for (auto& kv : stopToRoutesMap) {
            auto& routesUsingStop = kv.second;
            for (size_t i = 0; i < routesUsingStop.size(); ++i) {
                for (size_t j = i + 1; j < routesUsingStop.size(); ++j) {
                    int routeA = routesUsingStop[i];
                    int routeB = routesUsingStop[j];
                    graph[routeA].push_back(routeB);
                    graph[routeB].push_back(routeA);
                }
            }
        }

        queue<int> toVisit;
        unordered_set<int> visitedRoutes;
        int busesTaken = 1;

        for (int route : stopToRoutesMap[source]) {
            toVisit.push(route);
            visitedRoutes.insert(route);
        }

        while (!toVisit.empty()) {
            int currentLevelSize = toVisit.size();
            for (int i = 0; i < currentLevelSize; ++i) {
                int currentRoute = toVisit.front();
                toVisit.pop();

                if (stopsForRoute[currentRoute].count(target)) {
                    return busesTaken;
                }

                for (int neighbourRoute : graph[currentRoute]) {
                    if (!visitedRoutes.count(neighbourRoute)) {
                        visitedRoutes.insert(neighbourRoute);
                        toVisit.push(neighbourRoute);
                    }
                }
            }
            busesTaken++;
        }

        return -1;
    }
};
