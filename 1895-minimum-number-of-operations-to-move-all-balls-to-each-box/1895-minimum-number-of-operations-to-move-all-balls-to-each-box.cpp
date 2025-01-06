class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);

        // Left-to-right pass
        int left_balls = 0, left_cost = 0;
        for (int i = 0; i < n; ++i) {
            answer[i] += left_cost;
            if (boxes[i] == '1') ++left_balls;
            left_cost += left_balls;
        }

        // Right-to-left pass
        int right_balls = 0, right_cost = 0;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] += right_cost;
            if (boxes[i] == '1') ++right_balls;
            right_cost += right_balls;
        }

        return answer;
    }
};
