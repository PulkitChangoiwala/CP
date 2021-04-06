class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
     	int n = nums.size();
     	
        
        stack<pair<int,int>> st;
     	st.push({INT_MIN, -1});
     	vector<int> a(n);
     	
        for(int i=0;i<n;++i){
     		int el = nums[i];
     		while(st.top().first>=el){ st.pop();}
     		a[i] = st.top().second+1;
     		st.push({el,i});
     	}

        
     	stack<pair<int,int>> st1;
     	st1.push({INT_MIN, n});
     	vector<int> b(n);
     	
        
        for(int i=n-1;i>=0;--i){
     		int el = nums[i];
     		while(st1.top().first>=el){
     			st1.pop();

     		}
     		b[i] = st1.top().second-1;
     		st1.push({el,i});
     	}
     	int ans = -1;
        for(int i=0; i<n; ++i) {if(a[i]<=k && b[i]>=k) ans = max(ans, (nums[i])*(b[i]-a[i]+1));}
        
        return ans;


    }
};