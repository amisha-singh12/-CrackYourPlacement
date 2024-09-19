class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

    //min heap
    priority_queue<int , vector<int> , greater <int> > p; 

    // to store k elements
    for( int i =0 ; i < k ; i++) {
        p.push( nums[i] );
    }
    // k se aage ke elements ko check akro
    for( int i =k ; i < nums.size() ; i++) {
        // if next element is greater than heap top toh include it 
        // and remove this element.
        if( p.top() < nums[i]) {
            p.pop();
            p.push( nums[i] );
        }
    }
    return p.top();
    }
};