class StockSpanner {
public:
    
    stack <pair <int ,int> > st;
    StockSpanner() {   
    }
    
    int next(int price) {
     int  value =1;
    //   for every price it hahs a span value of 1  
      while(!st.empty() && st.top().first <= price) {
        value += st.top().second;
       st.pop();
      }
      st.push({price , value});

      return value;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */