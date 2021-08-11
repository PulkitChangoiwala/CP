// #include<bits/stdc++.h>
// using namespace std;



int n, l;
vector<vector<int>> adj;

int ctr;
vector<int> tin, tout;
vector<vector<int>> ancestors;

void dfs(int s, int p)
{
    tin[s] = ++ctr;
    ancestors[s][0] = p;
    
    for (int v : adj[s]) {
        if (v != p)
            dfs(v, s);
    }
    tout[s] = ++ctr;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(ancestors[u][i], v))
            u = ancestors[u][i];
    }
    return ancestors[u][0];
}

void preprocess(int root) {
    tin.resize(n+1);
    tout.resize(n+1);
    ctr = 0;
    l = ceil(log2(n));
    ancestors.assign(n+1, vector<int>(l + 1));
    dfs(root, root);
    for(int i=1; i<=l; ++i){
        for(int j=1; j<=n; ++j) {
            ancestors[j][i] = ancestors[ancestors[j][i-1]][i-1];
        }
    }
}