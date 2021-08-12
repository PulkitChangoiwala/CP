/*
- Prim's Algortihm works with undirected graph only.
	** Prim's algorithm assumes that all vertices are connected. But in a directed graph, 
		every node is not reachable from every other node. 
- It can work with negative weight edges.
- It can work with graphs containing cycles.

TC: O(ElogV)
- Prim's algorithm can be improved using Fibonacci Heaps (cf Cormen) to O(E + logV).
- Runs faster in dense graphs.]
- Kruskal’s algorithm runs faster in dense graphs.
*/

int prim(int n, vector<vector<pair<int,int>>> &adj, int s = 1){
	int total_wt = 0;
	const int inf = 1e9;
	vector<bool> vis(n+1);
	set<pair<int,int>> st;
	vector<int> min_wt(n+1, inf);
	//vector<bool> vis(n+1, false);
	min_wt[s] = 0;
	st.insert({min_wt[s],s});

	while(!st.empty()){
		int w = (*st.begin()).first, v = (*st.begin()).second;
		st.erase(st.begin());
		vis[v]= true;
		total_wt += w; //cost with with edge to vertex v is added to MST

		for(auto &edge : adj[v]){
			int u = edge.first, wt = edge.second;
			if(!vis[u] && min_wt[u] >  wt){
				st.erase({min_wt[u], u});
				min_wt[u] = wt;
				st.insert({min_wt[u],u});
			}
		}

	}
	return total_wt;
}
