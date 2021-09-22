int dfs(vector<vector<int>> &adj, int s, int p, int &n, int &diameter){
    int dia = 0, max_depth = 0;
    ++n;
    for(auto v : adj[s])
        if(v!=p){
            int depth = 1 + dfs(adj,v,s,n,diameter);
            diameter = max(diameter, depth+max_depth);
            max_depth = max(depth, max_depth);
        }
    
    return max_depth;
}