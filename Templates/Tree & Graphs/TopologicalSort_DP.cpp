/*
	dfs: 
		check cycles existence first, if graph is DAG, it stores 
		topological sort of the graph

	ts_dp: 
		- Calculates dp based answer on the topo. sort.
		- Note dp vector's dimension and state can be changed on the basis of
			question statement
*/

int n,m,ans;
vector<int> ts, vis, dp;
vector<vector<int>> adj; 
bool dfs(int s){
	vis[s] = 1;
	for(auto v : adj[s]){
		if(vis[v]==1) return true;
		if(vis[v]==0){
			if(dfs(v)) return true;
		}
	}
	vis[s] = 2;
	ts.pb(s);
	return false;
}

void ts_dp(int i){

	if(i==ts.size()) return;
	int v = ts[i];
	dp[v] += 1;
	ans = max(ans, dp[v]);
	for(auto u : adj[v]){
		dp[u] = max(dp[u], dp[v]);
		ans = max(ans, dp[u]);
	}
	ts_dp(i+1);
}

/*********************************
		***************
			****************
	Second Version, with one dfs call						
************/		

int n,m,ans;
vector<int> ts, vis, dp;
vector<vector<int>> adj;
bool dfs(int v){
	vis[v] = 1;
	for(auto u : adj[v]){
		if(vis[u]==1) return true;
		if(vis[u]==0){ if(dfs(u)) return true; }
		dp[v] = max(dp[v], dp[u]); 
	}
	vis[v] = 2;
	ts.push_back(v);
	dp[v]++;
	ans = max(ans, dp[v]);
	return false;
}

bool preProcess(int n){
	ts.clear();
	dp.clear(); dp.resize(n+1);
	vis.clear(); vis.resize(n+1, 0);
	bool cycle = false;
	for(int i=1; i<=n; ++i){
		if(!vis[i]) 
			cycle |= dfs(i);
	}
	return cycle;
}
