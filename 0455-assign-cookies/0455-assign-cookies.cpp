class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort the greed factor of children and the sizes of cookies
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int childIndex = 0; // Index for the children (greed factors)
        int cookieIndex = 0; // Index for the cookies (sizes)
        int count = 0; // Count of content children

        // Loop until we either run out of children or cookies
        while (childIndex < g.size() && cookieIndex < s.size()) {
            // If the current cookie can satisfy the current child
            if (s[cookieIndex] >= g[childIndex]) {
                count++; // The child is content
                childIndex++; // Move to the next child
            }
            // Move to the next cookie
            cookieIndex++;
        }

        return count; // Return the number of content children
    }
};
