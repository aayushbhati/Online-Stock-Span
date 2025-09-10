class StockSpanner {
public:
    stack<pair<int,int>> n1;
    int n2 = -1;

    StockSpanner() {
        n2 = -1;
    }
    
    int next(int price) {
        n2 += 1;
        while (!n1.empty() && n1.top().first <= price) 
            n1.pop();
        int ans = n2 - (n1.empty() ? -1 : n1.top().second);
        n1.push({price, n2});
        return ans;
    }
};
