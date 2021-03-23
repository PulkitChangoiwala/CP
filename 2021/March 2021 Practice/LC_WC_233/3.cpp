//  https://leetcode.com/contest/weekly-contest-233/problems/maximum-value-at-a-given-index-in-a-bounded-array/


class Solution {
public:
    bool is_possible(int target, int n, int index, int maxSum){
        long long min_psbl = 0ll;
        long long subtract = 1ll*(target-1)*(target)/2; 
        min_psbl = 1ll*target*n - min(subtract, 1ll*(index)*(index+1)/2) - min(subtract, (1ll*(n-index-1)*(n-index)/2))  - 1ll*(target-1)*(max(0, index-target+1) + max(0, n-index-target)); 
        return min_psbl<=maxSum;
    }
    int maxValue(int n, int index, int maxSum) {
        int l = 1, r = maxSum;
        int ans;
        int mid;
        while(l<=r){
            mid = l + (r-l)/2;
            bool check = is_possible(mid, n, index, maxSum);
            if(check){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};