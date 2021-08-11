/*

- Works for both directed or undirected graphs
- Negative weights are allowed.
- Negative weight cycles are not allowed
	This algorithm can also be used to detect the presence of negative cycles. 
	The graph has a negative cycle if at the end of the algorithm, 
	the distance from a vertex v to itself is negative.

- n is number of nodes
- m is number of edges
- dis adjacency Matrix
- Intially, for (i,j) if there is no edge then dis[i][j] will be infinity

*/
void floyad_warshall(int n, int m, vector<vector<int>> &dis){

	//After algorithm completes its running, dis[i][j] will store shortest distance between i & j nodes
	int infinity = 1e9;
	for(int k=1; k<=n; ++k){
		for(int i=1; i<=n; ++i){
			for(int j=1;j<=n;++j){
				if (dis[i][k] < infinity && dis[k][j] < infinity)
					dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
			}
		}
	}

}
