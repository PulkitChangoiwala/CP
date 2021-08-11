
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define fr(i,s,e) for(int i=s;i<e;++i)
#define fr1(i,s,e) for(int i=s;i>e;--i)
#define p0(a) cout << a <<" "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
#define INF (ll)1e18 + 100
#define v(d) vector<d>
#define all(x) (x).begin(), (x).end()
#define pr pair<int, int>
#define pr1(d1,d2) pair<d1,d2>
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define endl "\n"
#define sz(x) ((int)(x).size())
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

const int  mod = 1e9 +7;
const int mod1= 998244353;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*

int ad(int a, int b){
	a = (a+mod)%mod;
	b = (b+mod)%mod;
    return (a+b)%mod;
}
int mul(int a, int b){
    return (1ll*a*b)%mod;
}

struct Combo {
    vector<long long> facs;
    vector<long long> invfacs;
    int N;
 
    Combo(int N) {
        this->N=N;
        facs.assign(N+1,0);
        invfacs.assign(N+1,0);
        facs[0] = 1;
        for (int i = 1; i <= N; i++) {
            facs[i] = (facs[i-1]*i)%mod;
        }
        invfacs[N] = power(facs[N],mod-2);
        for (int i = N-1; i >= 0; i--) {
            invfacs[i] = (invfacs[i+1]*(i+1))%mod;
        }
    }
 
    ll choose(int n, int k) {
        if (n<0||k<0||n<k) return 0LL;
        ll denInv = (invfacs[k]*invfacs[n-k])%mod;
        ll ans = (facs[n]*denInv)%mod;
        return ans;
    }
 
    ll power(ll x, ll y) {
        ll ans = 1;
        x %= mod;
        while (y > 0) {
            if (y%2==1) ans = (ans*x)%mod;
            y /= 2;
            x = (x*x)%mod;
        }
        return ans;
    }
};

*/


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

vector<int> dp, parent;
int dfs(int i, int v, vector<int>&p, vector<vector<int>> &dis){
	//i,v are last taken index in, and last taken node v = p[i]
	int n = dis.size()-1, m = p.size();

	if(i==m-1) return 0; 
	if(dp[i]!=-1) return dp[i];

	int ans = m+1;
	for(int u = 1; u<=n; ++u){
		if(u==v) continue;
		int ind = i + dis[p[i]][u]; 
		if(ind < m && p[ind] == u) {
			debug(mp(v,u));
			debug(mp(i,ind));

			int tans =  dfs(ind, u, p, dis)+1; 
			if(tans<ans){
				parent[i] = ind;
				ans = tans;
			}
 		}

	}

	return dp[i] = ans;
}

void solve(){ 
	int n, edges=0;
	cin >> n;
	//directed graph
	vector<vector<int>> dis(n+1, vector<int>(n+1));

	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			char ch;
			cin >> ch;
			if(ch=='1'){
				edges++;
				dis[i][j] = 1;
			}
			else {
				dis[i][j] = 1e9;
			}
		}
	}

	floyad_warshall(n,edges,dis);
	int m; cin >> m;
	vector<int> p(m); fr(i,0,m) cin >> p[i];

	/*
		Algorithm: Let v1 v2 .... vk be the shortest subsequence
			- v1 = p1, vk = pm
			- Possibilities of v2 -> p2 p3... pm-1
				=> If(dis[p1][pi]==i-1) 
					we can take pi as v2
			=> Lets say we fixed v2 as pi, now
				Continue the same algorithm with v3, v3 can be chosen from pi+1 ... pm-1


	*/

	dp.clear(); parent.clear();
	dp.resize(m+1,-1); parent.resize(m+1,-1);
	int mnK = 1+ dfs(0, p[0], p, dis);

	int ind = 0;
	vector<int> ans;
	for(int i=mnK; i>0; --i){
		ans.pb(p[ind]);
		ind = parent[ind];
	}
	// reverse(all(ans));
	p1(mnK);
	for(auto el : ans) cout<<el<<" ";
	cout<<endl;		



return;} // solve ends 



signed main() {
	// your code goes here
	#ifndef ONLINE_JUDGE
		freopen("err", "w", stderr);
	#endif
	fast


	auto start1 = chrono::high_resolution_clock::now();
	
	{solve();}
	auto stop1 = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop1 - start1);
	#ifndef ONLINE_JUDGE
	cerr << "Time in ms: " << duration . count() / 1000 << endl;
	#endif

	
	return 0;
}










/*

Code belongs to:

 ▄████▄   ██░ ██  ▄▄▄       ███▄    █   ▄████  ▒█████   ██▓
▒██▀ ▀█  ▓██░ ██▒▒████▄     ██ ▀█   █  ██▒ ▀█▒▒██▒  ██▒▓██▒
▒▓█    ▄ ▒██▀▀██░▒██  ▀█▄  ▓██  ▀█ ██▒▒██░▄▄▄░▒██░  ██▒▒██▒
▒▓▓▄ ▄██▒░▓█ ░██ ░██▄▄▄▄██ ▓██▒  ▐▌██▒░▓█  ██▓▒██   ██░░██░
▒ ▓███▀ ░░▓█▒░██▓ ▓█   ▓██▒▒██░   ▓██░░▒▓███▀▒░ ████▓▒░░██░
░ ░▒ ▒  ░ ▒ ░░▒░▒ ▒▒   ▓▒█░░ ▒░   ▒ ▒  ░▒   ▒ ░ ▒░▒░▒░ ░▓  
  ░  ▒    ▒ ░▒░ ░  ▒   ▒▒ ░░ ░░   ░ ▒░  ░   ░   ░ ▒ ▒░  ▒ ░
░         ░  ░░ ░  ░   ▒      ░   ░ ░ ░ ░   ░ ░ ░ ░ ▒   ▒ ░
░ ░       ░  ░  ░      ░  ░         ░       ░     ░ ░   ░  
░                                                          



 */

