class MedianFinder {
public:
 priority_queue<int> left_max_heap; // max heap
 priority_queue<int , vector<int> , greater<int>> right_min_heap;  //min heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_max_heap.empty() || num < left_max_heap .top()) {
            left_max_heap.push(num);
        }
        else{
            right_min_heap.push(num);
        }

        // always maintain left heap size one > than right heap 
        // or both of eqaul size

        if( abs((int)left_max_heap.size() - (int)right_min_heap.size() ) > 1) {
           right_min_heap.push(left_max_heap.top()); 
           left_max_heap.pop();
        }
        else if(left_max_heap.size() < right_min_heap.size()){
           left_max_heap.push(right_min_heap.top());
           right_min_heap.pop(); 
        }

    }
    
    double findMedian() {
        if(right_min_heap.size() == left_max_heap.size()){
            // even no of elements
            double mean = (left_max_heap.top() + right_min_heap.top())/2.0;
            return mean;
        }

        // else odd no of elements
        return left_max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */