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
void debug_arr(vector<int> &a){
	int len = a.size();
	fr(i,0,len){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}


const int  mod = 1e9 +7;
const int mod1= 998244353;
int n,m,f;
v(v(int)) adj;
v(int) p,h,vis,good;

void dfs(int s, int par=-1){
    if(!f) return;
    vis[s] = p[s];
    int gs = 0;
    for(auto v : adj[s]){
        if(v!=par){
            dfs(v,s);
            vis[s] += vis[v];
            gs += good[v];
        }
    }
    
    int tt = (vis[s] + h[s]);
    // cout<<s<<" "<<tt<<endl;
    good[s] = tt/2;
    if(f && tt%2==0  && (0<=good[s] && good[s]<=vis[s]) && gs<=good[s]) f = 1;
    else f = 0;
}
void solve(){ 
cin >> n >> m;
adj.clear(); p.clear(); h.clear(); vis.clear(); good.clear();
adj.resize(n+1); p.resize(n+1); h.resize(n+1); vis.resize(n+1); good.resize(n+1);
fr(i,1,n+1) cin >> p[i];
fr(i,1,n+1) cin >> h[i];
int x,y;
fr(i,1,n) {cin>>x>>y; adj[x].pb(y); adj[y].pb(x);}
f=1;
// debug_arr(p);
// debug_arr(h);
dfs(1);
// debug_arr(vis);
// debug_arr(good);
if(f) p1("Yes");
else p1("No");

return;} // solve ends 



signed main() {
	// your code goes here
	fast
	int t; cin>>t; while(t--)
	{solve();}
	
	return 0;
}

 