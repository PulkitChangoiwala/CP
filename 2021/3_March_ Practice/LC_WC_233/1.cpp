class Solution {
public:
    int maxAscendingSum(vector<int>& b) {
        vector<int> a = b;
        a.push_back(-100);
        int ans = *max_element(a.begin(), a.end());
        int temp =0;
        int n = a.size();
        for(int i = 0; i < n-1; ++i){
            
            while(a[i] < a[i+1]){
                temp += a[i];
                i++;
                
            }
            
            if(a[i] >= a[i+1]){
                temp += a[i];
                ans = max(ans, temp);
                temp = 0;
            }
        }
        ans = max(ans, temp);
        return ans;
    }
};