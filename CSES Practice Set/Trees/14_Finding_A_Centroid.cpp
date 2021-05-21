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
#define s_ second
#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
void debug_arr(vector<int> &a){
	int len = a.size();
	fr(i,0,len){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
 
 
const int  mod = 1e9 +7;
const int mod1= 998244353;
 
 
// #include<bits/stdc++.h>
// using namespace std;
 
 
 
int n;
vector<vector<int>> adj;
vector<int> size;
int ct1, ct2;

void dfs_sz(int s=1, int p = 0){
    size[s] = 1;
    for(auto v : adj[s]){
        if(v!=p){
            dfs_sz(v,s);
            size[s] += size[v];
        }
    }
}

void dfs_ct(int s = 1, int p = 0){
    
    int f = true;
    for(auto v : adj[s]){
        if(v!=p && size[v]*2 > n) { f = false; dfs_ct(v,s); }
    }
    if(f) ct1 = s;
}
 
void solve(){ 
	cin >> n ;	
	int a,b;
	
	adj.resize(n+1);
	fr(i,0,n-1) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	size.resize(n+1);
	dfs_sz();
	dfs_ct();
	p1(ct1);
 
 
return;} // solve ends 
 
 
 
signed main() {
	// your code goes here
	fast
	{solve();}
	
	return 0;
}
 