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

vector<vector<int>> tree, ctree;
vector<int> sz;
vector<bool> vis;
int root;
void findSize(int s, int p){
    sz[s] = 1;
    for(auto v : tree[s]){
        if(!vis[v] && v!=p){
            findSize(v,s);
            sz[s] += sz[v];
        }
    }
}

int findCentroid(int s, int p, int n){
    for(auto v : tree[s]){
        if(!vis[v] && v!=p && sz[v] > n/2){
            return findCentroid(v,s,n);
        }
    }
    return s;
}


int centroidDecomposition(int s, int p){
    //sz.assign(tree.size(),0);
    findSize(s,p);
    int u, ct = findCentroid(s,p,sz[s]);
    vis[ct] = true;
    if(p==0) root = ct;

    for(auto v : tree[ct]){
        if(!vis[v]) {
            u = centroidDecomposition(v,ct);
            ctree[ct].push_back(u);
        }
    }
    return ct;
}

void process(int n){
    ctree.clear();
    ctree.resize(n+1);
    sz.clear();
    sz.resize(n+1);
    vis.clear();
    vis.resize(n+1);
    centroidDecomposition(1,0);
}

vector<char> assign;
void ass(int s, int p, int d){
    if(d>=26) { assign[0] = '!'; return;} 
    assign[s] = (char)('A' + d);
    for(auto v : ctree[s]){
        if(v!=p){
            ass(v,s,d+1);
        }
    }

}
void solve(){
    int n,x,y;
    cin >> n;
    tree.clear();
    tree.resize(n+1);
    fr(i,0,n-1) {
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }

    process(n);

    assign.clear();
    assign.resize(n+1);
    ass(root, 0, 0);
    if(assign[0] != '!'){
        for(int i=1;i<=n; ++i)cout<<assign[i] <<" ";
        cout<<endl;
    }
    else {
        p1("Impossible!");
    }
    return;
    
}

signed main() {
	// your code goes here
    solve();
	return 0;
}