class RadixSort{
    int n;
    int digits;
    vector<int> v;
    vector<int> sorted;
    vector<int> indices; //index of ith element in sorted order is indices[i]
public:
    RadixSort(vector<int> &arr){
        this->n = arr.size();
        this->digits = 10;
        this->v = arr;
        indices.resize(n);
        sorted.resize(n);
        iota(indices.begin(), indices.end(),0);
        radixSort();
    }
    
    vector<int> countingSort(vector<int>&arr){
        vector<int> cnt(10), indexes;
        for(auto el : arr) cnt[el]++;
        for(int i=1;i<10;++i) cnt[i] += cnt[i-1];
        for(int i= arr.size()-1;i>=0;--i) {
            cnt[arr[i]]--;
            indexes.push_back(cnt[arr[i]]);
        }
        reverse(indexes.begin(), indexes.end());
        return indexes;
    }
    void radixSort(){
        
        vector<pair<int,int>> vt, vtemp;
        for(int i=0; i<n; ++i) vt.push_back({v[i],i});
        
        for(int d=digits; d>=1; --d){
            vector<int> a;
            for(auto &el : vt){
                // cout<<el.first<<"--"<<el.second<<" ";
                a.push_back(el.first%10); el.first/=10;
            }
            vector<int> indexes = countingSort(a);            
            
            vtemp = vt;
            for(int i=0; i<indexes.size(); ++i){
                //new index of v[i] is indexes[i]
                vt[indexes[i]] = vtemp[i]; 
            }
            vtemp.clear();
        }
        
        for(int i=0; i<vt.size(); ++i){ indices[vt[i].second] = i;}

        for(int i=0; i<vt.size(); ++i){ sorted[indices[i]] = v[i];}

        
    }
    
    vector<int> getSortedArray(){
        return sorted;
    }
    

};