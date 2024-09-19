class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> p; // Min-heap to store the k largest elements

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        // Insert the first k elements into the heap
        for (int i = 0; i < nums.size(); ++i) {
            p.push(nums[i]);
            if (p.size() > k) {
                p.pop();  // Maintain the heap size to be exactly k
            }
        }
    }
    
    int add(int val) {
        // Add the new element to the heap
        p.push(val);
        
        // If the heap exceeds k elements, remove the smallest one
        if (p.size() > k) {
            p.pop();
        }

        // The top element of the min-heap is the Kth largest
        return p.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
