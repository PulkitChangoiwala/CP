#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long 
#define fr(i,s,e) for(int i=s;i<e;++i)
#define fr1(i,s,e) for(int i=s;i>e;--i)
#define p0(a) cout << a <<" "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
#define INF (ll)1e18 + 100
#define v(d) vector<d>
#define pr pair<int, int>
#define pr1(d1,d2) pair<d1,d2>
#define pb push_back
#define f first
#define s second
#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	

vector<vector<int>> tree,ctree;
vector<int> sz, parent;
vector<bool> vis;

void findSize(int s, int p){
    sz[s] = 1;
    for(auto v : tree[s]){
        if(!vis[v] && v!=p){
            findSize(v,s);
            sz[s] += sz[v];
        }
    }
    return;
}

int centroidNode(int s, int p, int n){
    if(n==1) return s;
    
    for(auto v : tree[s]){
        if(v!=p){
            if(!vis[v] && sz[v]>n/2){
               return centroidNode(v, s, n);
            }
        }
    }
    return s;

}


int centroidDecomposition(int s, int p){
    int ct,u;

    findSize(s,p);
    
    ct = centroidNode(s, p, sz[s]);
    vis[ct] = true;
    parent[ct] = p;

    for(auto v : tree[ct]){
        if(!vis[v]) {
            u = centroidDecomposition(v, ct);
            // ctree[ct].push_back(u);
        }
    }

    return ct;
}


void process(int n){
//    ctree.clear(); ctree.resize(n+1);
    parent.clear();parent.resize(n+1); 
    sz.clear(); sz.resize(n+1);
    vis.clear(); vis.resize(n+1); 
    centroidDecomposition(1,0); 
    return;
}


vector<int> answer;
vector<int> depth;
vector<vector<int>> ancestors;
vector<int> tin,tout;
int l,ctr;

void findDepth(int s, int p, int d){
    tin[s] = ++ctr;
    depth[s] = d;
    ancestors[s][0] = p;
    for(auto v : tree[s]){
        if(v!=p) {
            findDepth(v,s,d+1);
        }
    }
    tout[s] = ++ctr;
    return;
}

bool isanc(int a, int b){
    return tin[a]<= tin[b] && tout[b]<=tout[a];
}

int lca_(int a, int b){
    if(isanc(a,b)) return a;
    else if(isanc(b,a)) return b;
    
    for(int i=l;i>=0;--i){
        if(ancestors[a][i]!=0 && !isanc(ancestors[a][i],b)) a = ancestors[a][i];
    }
    return ancestors[a][0];
}

int dis_(int a, int b){
    int lca = lca_(a,b);
    return depth[a]+depth[b] - 2*depth[lca];
}
void update(int v){
    int t = v;
    answer[t] = 0;
    
    while(1){
        answer[t] = min(answer[t],dis_(v,t));
        if(parent[t] == 0) break;
        t = parent[t];
    }
  
} 

int query(int v){
    int t = v,d=0;
    int ans = 1e9;    
    while(1){
        ans = min(ans, dis_(v,t)+answer[t]);
        if(parent[t] == 0) break;
        t = parent[t];
    }
    return ans;
}
void solve(){
    int n,m,x,y;
    cin >> n >> m;
    l = ceil(log2(n)) + 1;
    
    tree.clear();
    tree.resize(n+1);
    answer.clear();
    answer.resize(n+1, 1e9);
    depth.clear();
    depth.resize(n+1,0);
    ancestors.clear(); tin.clear(); tout.clear();
    ancestors.resize(n+1, vector<int>(l+1,0)); tin.resize(n+1,0); tout.resize(n+1,0);

    fr(i,0,n-1){
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    process(n);
    findDepth(1,0,0);
    for(int i=1;i<=l;++i){
        for(int v=1;v<=n;++v){
            ancestors[v][i] = ancestors[ancestors[v][i-1]][i-1];
        }
    }
    
    update(1);
    int t,v; 
    fr(i,0,m) {
        cin >> t >> v;
        if(t==1){
            update(v);
        }
        else {
            p1(query(v));
        }
    }
    return;
    
}

signed main() {
	// your code goes here
    solve();
	return 0;
}