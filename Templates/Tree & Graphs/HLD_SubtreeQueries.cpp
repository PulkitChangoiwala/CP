//https://codeforces.com/blog/entry/53170?f0a28=1
void dfs_sz(int s = 1, int p = 0){
	size[s]++;
	for(auto &v : adj[s]){
		if(v==p){ swap(v,adj[s][adj[s].size()-1]);}
		if(v!=p) {
			dfs_sz(v,s);
			size[s] += size[v];
			if(size[v] > size[adj[s][0]]) swap(adj[s][0],v);
		}
	}
}

void dfs_hld(int s = 1, int p = 0){
	in[s] = timer++;
	dfs.push_back(s);
	parent[s] = p;
	for(auto &v : adj[s]){
		if(v!=p){
			path_start[v] = (v == adj[s][0]) ? path_start[s] : v; 
			dfs_hld(v,s);
		}
	}
	out[s] = timer; 
}


void preprocess(){
	timer = 0;
	size.resize(n+1);
	path_start.resize(n+1);
	path_start[1] = 1; //Heavy path of root starting at root
	parent.resize(n+1);
	in.resize(n+1);
	out.resize(n+1);
	dfs_sz(); //rooting at 1, parent of root is 0
	dfs_hld();
}