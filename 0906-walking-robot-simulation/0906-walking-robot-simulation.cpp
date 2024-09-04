class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Define directions: north, east, south, west
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0; // Start facing north
        int x = 0, y = 0;
        int maxDist = 0;
        
        // Convert obstacles to a set for quick lookup
        unordered_set<string> obstacleSet;
        for (auto& obs : obstacles) {
            obstacleSet.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }
        
        for (int cmd : commands) {
            if (cmd == -2) { // Turn left
                dir = (dir + 3) % 4;
            } else if (cmd == -1) { // Turn right
                dir = (dir + 1) % 4;
            } else { // Move forward cmd steps
                for (int i = 0; i < cmd; ++i) {
                    int nx = x + directions[dir].first;
                    int ny = y + directions[dir].second;
                    // Check if next position is an obstacle
                    if (obstacleSet.find(to_string(nx) + "," + to_string(ny)) == obstacleSet.end()) {
                        x = nx;
                        y = ny;
                        maxDist = max(maxDist, x*x + y*y);
                    } else {
                        break;
                    }
                }
            }
        }
        
        return maxDist;
    }
};
