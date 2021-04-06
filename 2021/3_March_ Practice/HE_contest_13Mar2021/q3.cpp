 #include <bits/stdc++.h>
 using namespace std;
void bfs(vector<vector<int>> &adj, vector<int> &dis, int s)
{
	
	queue<int> q;
	vector<bool> vis(adj.size()+1);
	q.push(s);
	dis[s] = 0;
	vis[s] = true;

	while(!q.empty()){
		int v = q.front();
		q.pop();

		for(auto u : adj[v]){
			if(vis[u]) continue;
			q.push(u);
			dis[u] = dis[v]+1;
			vis[u] = true;
		}
	}

return;
}
vector<int> st;

void dfs(vector<vector<int>> &adj, int v, int dis, pair<int, int> &p, vector<bool> &vis){
	vis[v] = true;
	for(auto u : adj[v]){
		if(!vis[u]){
			if(st[u]>0 && p.second<dis+1) {
				p.first = u;
				p.second = dis+1;
			}
			dfs(adj,u,dis+1, p, vis);
		}
	}
	return;
}

int max_dis(vector<vector<int>> &adj, vector<int> &a){
	//use two dfs method to find diameter
	st.clear(); st.resize(adj.size()+1, 0);
	for(auto el : a) st[el]++;

	pair<int,int> p = {a[0],0}; //vertex, distance
	vector<bool> visited(adj.size()+1, false);
	//cout<<p.first<<" "<<p.second<<endl;
	dfs(adj, a[0], 0, p, visited);
	visited.clear(); visited.resize(adj.size()+1, false);
	p = {p.first,0};
	dfs(adj, p.first, 0, p, visited);
	return p.second;
}

void solve(){
	int n,k;
	cin>>n>>k;
	vector<vector<int>> adj(n+1);
	int x,y;
	for(int i=0;i<n-1;++i){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	vector<int> a(k);
	for(int i=0;i<k;++i) cin>>a[i];

	//find distance between ai & aj for all i & j
	vector<int> level(n+1, -1);

	bfs(adj, level, a[0]);
	//for(int i=1;i<=n;++i) cout<<level[i]<<" ";
	

	int f = level[a[0]]%2;
	bool flag = true;
	for (int i = 1; i < k; ++i)
	{ if(level[a[i]]%2 != f) {flag = false; break;}}

	if(!flag){
		cout<<-1<<"\n";
		return;
	}

	int ans = max_dis(adj,a);											
	cout<<ans/2<<"\n";

}


signed main(){
	int t;
	cin>>t;
	while(t--) solve();
}