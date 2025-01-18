#include <vector>
#include <deque>
#include <climits>

class Solution {
public:
    int minCost(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Directions: [right, left, down, up]
        std::vector<std::pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        // Distance array to track minimum cost to reach each cell
        std::vector<std::vector<int>> dist(m, std::vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        
        // Deque for 0-1 BFS
        std::deque<std::pair<int, int>> dq;
        dq.push_front({0, 0});
        
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            
            // Current direction of the arrow
            int current_dir = grid[x][y] - 1;
            
            for (int d = 0; d < 4; ++d) {
                int nx = x + directions[d].first;
                int ny = y + directions[d].second;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int cost = (d == current_dir) ? 0 : 1; // Cost to change direction
                    if (dist[x][y] + cost < dist[nx][ny]) {
                        dist[nx][ny] = dist[x][y] + cost;
                        if (cost == 0) {
                            dq.push_front({nx, ny}); // No cost, push to front
                        } else {
                            dq.push_back({nx, ny}); // Cost 1, push to back
                        }
                    }
                }
            }
        }
        
        // Minimum cost to reach bottom-right cell
        return dist[m - 1][n - 1];
    }
};
