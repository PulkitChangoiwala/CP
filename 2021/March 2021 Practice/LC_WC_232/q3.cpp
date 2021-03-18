class Solution {
public:
    //logic: add students with least pass ration 
    double maxAverageRatio(vector<vector<int>>& classes, int es) {
      
        priority_queue<pair<double,int>> pq;
    	int c = classes.size();
        double ans = 0.0;
    	for(int i=0;i<c;++i){
    		double inc_ratio = 0.0;
            int pass = classes[i][0];
            int t = classes[i][1];
            inc_ratio = (1.0*(t-pass))/(1.0*t*(t+1));
    		pq.push({inc_ratio, i});
            ans += 1.0*pass/(1.0*t);

    	}

        for(int i=0;i<es;++i){
    		int ind = pq.top().second;
            int pass = ++classes[ind][0];
            int total = ++classes[ind][1];
            ans += pq.top().first;
    		double new_inc_ratio = (1.0*(total-pass))/(1.0*(total)*(total+1));
    		pq.pop();
    		pq.push({new_inc_ratio, ind});
    	}
        
        ans = ans/(1.0*(int)classes.size());
        return ans;
        
    }


};