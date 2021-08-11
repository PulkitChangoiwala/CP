/*
Note that this implementation malfunctions if the graph has multiple edges, since it ignores them. 
Of course, multiple edges will never be a part of the answer, 
so we can check additionally that the reported bridge is not a multiple edge. 
Alternatively it's possible to pass to DFS the index of the edge used to enter the vertex 
instead of the parent vertex (and store the indices of all vertices).
*/

void dfs(int s, int p, int &timer, vector<int>&tin, vector<int>&low, vector<vector<int>> &adj, vector<vector<int>> &bridges){
    tin[s] = ++timer;
    low[s] = tin[s];
    
    for(auto &v : adj[s]){
        if(v==p) continue;
        //tree edge
        if(tin[v]==-1) {
            dfs(v,s,timer,tin,low,adj,bridges);
            low[s] = min(low[s],low[v]);
            //s-v is back-edge iff low[v]<=tin[s] 
            if(low[v]>tin[s]) {bridges.push_back({v,s});}
        }
        //back-edge
        else { low[s] = min(low[s], tin[v]);}
         
    }

}

void bridges_in_graph(vector<vector<int>> &adj, vector<vector<int>> &bridges){
    int n = adj.size(), timer = 0;
    vector<int> tin(n,-1),low(n,-1);
    dfs(1,-1,timer,tin,low,adj,bridges);
    return;
}