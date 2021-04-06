class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
    
        int n = orders.size();
        priority_queue<pair<int,int>> pqb, pqs; //store max
        long long ans = 0ll;
        for(int i = 0; i < n; ++i){
            if(orders[i][2] == 0) {
                //buy order
                int order_amt = orders[i][1];
                while(!pqs.empty() && order_amt){
                    
                    pair<int, int> p1 = pqs.top();
                    pair<int, int> p = {-1*p1.first, -1*p1.second};
                    if(p.first > orders[i][0]) break;
                    pqs.pop();
                    int t = p.second - order_amt;
                    if(t>0) {pqs.push({p1.first, -1*t});}
                    order_amt = max(0, order_amt - p.second);
                    
                }
                
                if(order_amt > 0){
                    pqb.push({orders[i][0], order_amt});
                }
            }
            
            else
                if(orders[i][2] == 1) {
                //sell order
                int order_amt = orders[i][1];
                while(!pqb.empty() && order_amt){
                    
                    pair<int, int> p = pqb.top();
                    if(p.first < orders[i][0]) break;
                    pqb.pop();
                    int t = p.second - order_amt;
                    if(t>0) {pqb.push({p.first,t});}
                    order_amt = max(0, order_amt - p.second);
                    
                }
                
                if(order_amt > 0){
                    pqs.push({-1*orders[i][0], -1*order_amt});
                }
            }
            
        }
        int mod = 1e9 + 7;
        while(!pqs.empty()) {
            ans = (ans + -1*pqs.top().second)%mod;
            pqs.pop();
        }
        while(!pqb.empty()) {
            ans = (ans + pqb.top().second)%mod;
            pqb.pop();
        }
        return ans;
        
    }
};