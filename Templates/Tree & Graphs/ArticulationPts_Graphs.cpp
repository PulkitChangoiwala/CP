void dfs(int s, int p, int &timer, vector<int>&tin, vector<int>&low, vector<vector<int>> &adj, vector<vector<int>> &articulation_points){
    int children = 0;
    tin[s] = ++timer;
    low[s] = tin[s];
    
    for(auto &v : adj[s]){
        if(v==p) continue;
        //tree edge
        if(tin[v]==-1) {
            dfs(v,s,timer,tin,low,adj,articulation_points);
            low[s] = min(low[s],low[v]);
            ++children;
            //s-v is back-edge to an ancestor of s(not to s) iff low[v]<tin[s] 
            if(low[v]>=tin[s] && p!=-1) {articulation_points.push_back(s);}
        }
        //back-edge
        else { low[s] = min(low[s], tin[v]);}
    }
    //root node case
    if(p==-1 && children > 1) {articulation_points.push_back(s);}

}

void articulation_points_in_graph(vector<vector<int>> &adj, vector<int> &articulation_points){
    int n = adj.size(), timer = 0;
    vector<int> tin(n,-1),low(n,-1);
    dfs(1,-1,timer,tin,low,adj,articulation_points);
    return;
}