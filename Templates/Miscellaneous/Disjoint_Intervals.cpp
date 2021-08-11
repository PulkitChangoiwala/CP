/*
- We maintain disjoint intervals.

query [l,r)
    Per operation O(logN)
remove [l,r)
    - Ensure that disjoint nature remains as it is.
    - Find overlapping intervals.
    - Remove all such intervals.
    Amortised O(nlogn), for all queries of Remove Type
    
Add [l,r)
    - Ensure that disjoint nature remains as it is.
    - Find overlapping intervals.
    - Replace them to keep one interval only.
    Amortised O(nlogn), for all queries of Add Type
*/
class RangeModule {
public:
    int INF = 1e9+7;
    set<pair<int,int>> disjoint_Intervals;
    RangeModule() {
        disjoint_Intervals.clear();
        disjoint_Intervals = {{-2,-1}}; //dummy interval
    }
    
    void addRange(int left, int right) {
        auto Start = disjoint_Intervals.upper_bound({left,  INF}); --Start;
        auto End   = disjoint_Intervals.upper_bound({right, INF});
        while(Start!=End){
            if(Start->second < left) {++Start; continue;}
            left = min(left,Start->first);
            right = max(right,Start->second);
            auto it = Start; ++Start;
            disjoint_Intervals.erase(it);
            
        }
        
        disjoint_Intervals.insert({left,right});
         
    }
    
    bool queryRange(int left, int right) {
        auto iter = disjoint_Intervals.upper_bound({left, INF}); --iter;
        if(iter->first<=left && right<=iter->second) return true;
        return false;
    }
    
    void removeRange(int left, int right) {
        auto Start = disjoint_Intervals.upper_bound({left,  INF}); --Start;
        auto End   = disjoint_Intervals.upper_bound({right, INF}); 
        
        while(Start!=End){
            if(Start->second <= left || Start->first >= right ) {++Start; continue;}
            if(Start->first < left) disjoint_Intervals.insert({Start->first,min(left,Start->second)});
            if(Start->second > right) disjoint_Intervals.insert({right, Start->second});
            auto it = Start; ++Start;
            disjoint_Intervals.erase(it);
        }
        
    }
};