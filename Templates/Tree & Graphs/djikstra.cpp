void djikstra(int n, int start, vector<vector<int>>&adj, vector<vector<int>> &wght, vector<int>&dis, vector<int> &parent){
    
    vector<bool> vis(n+1);
    set<pair<int,int>> st;
    st.insert({start,0});
    dis[0] = 0;
    parent[0] = -1;
    vis[0]=true;
    
    while(!st.empty()){
        auto [d,v] = *(st.begin()); st.erase(st.begin());
        vis[v] = true;
        for(auto u : adj[v]){
            if(!vis[u]){
                auto it = st.find({dis[u],u});
                if(it!=st.end()) st.erase(it);
                if(dis[u]>dis[v]+wght[u][v] && dis[v]!=1e9){
                    parent[u] = v;
                    dis[u] = dis[v]+wght[u][v]+1;
                }
                st.insert({dis[u],u});
            }
        }
    }
}

//Another variant
vector<long long> ways;
void dijkstra(int n, int start, vector<vector<pair<int,long long>>>&adj){
    
    vector<long long> dis(n+1,1e16);
    set<pair<long long,int>> st;
    st.insert({start,0});
    ways[start] = 1;
    dis[start] = 0;
    // parent[start] = -1;
    
    while(!st.empty()){
        auto [d,v] = *(st.begin()); st.erase(st.begin());
        if(d > dis[v]) continue;
        
        for(auto [u, wt] : adj[v]){
            if(dis[u]>dis[v]+wt && dis[v]!=1e16){
                // parent[u] = v;
                ways[u] = ways[v];
                dis[u] = dis[v]+wt;
                st.insert({dis[u],u});
            }
            else if(dis[u] == dis[v]+wt){
                ways[u] = (ways[u]+ways[v])%(1000000007);
            }
                
        }
    }
}