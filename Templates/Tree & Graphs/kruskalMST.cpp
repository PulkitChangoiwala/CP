

/*
- Works with undirected graph only.
- It can work with negative weight edges.
- It can work with graphs containing cycles.

TC: O(ElogV)
- Kruskal’s algorithm can generate forest(disconnected components) 
	at any instant as well as it can work on disconnected components
- Kruskal’s algorithm runs faster in sparse graphs.

Algorithm:
	- Sort all edges by weight
	- Traverse the sorted edges list
	- Add edges to MST iff it does not make a cycle

Why Kruskal’s Algorithm fails for directed graph ?
 - In Kruskal’s algorithm, In each step, it is checked that if the edges form a 
 	cycle with the spanning-tree formed so far. But Kruskal’s algorithm fails to 
 	detect the cycles in a directed graph as there are cases when there is no cycle 
 	between the vertices but Kruskal’s Algorithm assumes it to cycle and 
 	don’t take consider some edges due to which Kruskal’s Algorithm fails for directed graph.
 */

int find(vector<int> &ds, int i) {
    return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
}

bool Union(vector<int> &ds, int i, int j){
	 i = find(ds, i), j = find(ds, j);
	 if(i==j) return false;
	 if(abs(ds[i]) < abs(ds[j])) swap(i,j); 
	 ds[i]+=ds[j]; 
	 ds[j]=i;
	 return true;
}

int KruskalMST(int n, vector<vector<pair<int,int>>> adj, int s = 1) {
	int mstWt = 0;
	vector<int> ds(n+1, -1);
	vector<vector<int>> edges;

	for(int i=1; i<=n; ++i){
		for(auto edge : adj[i])
			edges.push_back({i,edge.first, edge.second});
	}

	sort(edges.begin(), edges.end(), [](const vector<int> &e1 , const vector<int> &e2){
		return e1[2] < e2[2];
	});

	for(auto &edge : edges){
		if(Union(ds, edge[0], edge[1])){
			mstWt += edge[2];
		}
	}

	return mstWt;
}
