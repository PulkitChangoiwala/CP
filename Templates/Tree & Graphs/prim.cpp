/*
- Prim's Algortihm works with undirected graph only.
- It can work with negative weight edges.
- It can work with graphs containing cycles.
*/

void prim(int &total_wt, vector<bool> &vis){
	int s = 1;
	total_wt = 0;
	const int inf = 1e16;
	set<pair<int,int>> st;
	vector<int> min_wt(n+1, inf);
	//vector<bool> vis(n+1, false);
	min_wt[s] = 0;
	st.insert({min_wt[s],s});

	while(!st.empty()){
		auto it = st.begin();
		int w = (*it).first; //cost with with edge to vertex v is added to MST
		int v = (*it).second;
		st.erase(it);
		vis[v]= true;
		total_wt += w;

		for(auto edge : adj[v]){
			int u = edge.first;
			int wt = edge.second;
			if(!vis[u] && min_wt[u] >  wt){
				st.erase({min_wt[u], u});
				min_wt[u] = wt;
				st.insert({min_wt[u],u});
			}
		}

	}
	return;
}
