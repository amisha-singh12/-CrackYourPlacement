class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n, 0);
        unordered_set<int> seenA, seenB; // To track elements seen so far

        int commonCount = 0; // Count of common elements

        for (int i = 0; i < n; i++) {
            // Insert current elements into respective sets
            if (seenB.count(A[i])) commonCount++; // If A[i] is already in B's set
            if (seenA.count(B[i])) commonCount++; // If B[i] is already in A's set
            if (A[i] == B[i]) commonCount++; // A[i] and B[i] are the same

            seenA.insert(A[i]);
            seenB.insert(B[i]);

            C[i] = commonCount;
        }

        return C;
    }
};
