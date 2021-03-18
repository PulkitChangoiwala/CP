int findCenter(vector<vector<int>>& edges) {
    int m = edges.size();
    int n = m+1;
    vector<int> cnt(n+1);
    int ans =0;
    for(int i=0;i<n-1;++i){
    	cnt[edges[i][0]]++;	
    	cnt[edges[i][1]]++;
    	if(cnt[edges[i][0]]==n-1){ans = edges[i][0] break;}
    	if(cnt[edges[i][1]]==n-1){ans = edges[i][1] break;}
    }

}