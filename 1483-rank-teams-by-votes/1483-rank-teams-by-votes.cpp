class Solution {
public:
    string rankTeams(vector<string>& votes) {
        // Get the number of teams
        int numTeams = votes[0].size();
        
        // Create a map to store the rank counts of each team
        unordered_map<char, vector<int>> rankCount;
        
        // Initialize rank count for each team
        for (char team : votes[0]) {
            rankCount[team] = vector<int>(numTeams, 0);
        }
        
        // Fill the rankCount map with the votes
        for (const string& vote : votes) {
            for (int i = 0; i < vote.size(); ++i) {
                rankCount[vote[i]][i]++;
            }
        }
        
        // Create a list of all teams
        vector<char> teams(votes[0].begin(), votes[0].end());
        
        // Sort the teams based on rank count and alphabetically in case of ties
        sort(teams.begin(), teams.end(), [&](char a, char b) {
            // Compare the ranking counts of team a and team b
            for (int i = 0; i < numTeams; ++i) {
                if (rankCount[a][i] != rankCount[b][i]) {
                    return rankCount[a][i] > rankCount[b][i];
                }
            }
            // If they are tied in all positions, compare alphabetically
            return a < b;
        });
        
        // Return the result as a string
        return string(teams.begin(), teams.end());
    }
};
