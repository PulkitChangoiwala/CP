
#include <bits/stdc++.h>
#include <sys/resource.h>
using namespace std;
#define int long long
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
//void _print(int t) {cerr << t;}
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
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

int ans = 0;
map<pair<int,int>, int> Cnt; 
void dfs(int s, int p, int &timer, vector<int>&tin, vector<int>&low, vector<vector<int>> &adj){
    tin[s] = ++timer;
    low[s] = tin[s];
    
    for(auto &v : adj[s]){
        if(v==p) continue;
        //tree edge
        if(tin[v]==-1) {
            dfs(v,s,timer,tin,low,adj);
            low[s] = min(low[s],low[v]);
            //s-v is back-edge iff low[v]<=tin[s] 
            if(low[v]>tin[s] && Cnt[{min(v,s), max(v,s)}]==1) {ans++;}
        }
        //back-edge
        else { low[s] = min(low[s], tin[v]);}
         
    }

}

void bridges_in_graph(vector<vector<int>> &adj){
    int n = adj.size(), timer = 0;
    vector<int> tin(n,-1),low(n,-1);
    dfs(1,-1,timer,tin,low,adj);
    return;
}

int tcnt;
void solve(){ 
	int n;
	cin >> n;
	v(v(int)) adj(n+1);
	Cnt.clear();

	fr(i,0,n-1){
		int a,b;
		cin >> a >> b;

		Cnt[{min(a,b), max(a,b)}]++;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	vector<vector<int>> freq(n+1);
	fr(i,1,n+1) {
		int f;
		cin >> f;
		freq[f].pb(i);
	}

	fr(i,1,n+1){
		if(freq[i].size()){
			int prev = freq[i][0], sz = freq[i].size();
			for(int j=1; j<sz;++j){
				// temp[prev].insert(freq[i][j]);
				// temp[freq[i][j]].insert(prev);
				adj[prev].pb(freq[i][j]);
				adj[freq[i][j]].pb(prev);
				Cnt[{min(prev,freq[i][j]), max(prev,freq[i][j])}]++;
				prev = freq[i][j];
			}
		}
	}
	// freq.clear();

	ans = 0;
	bridges_in_graph(adj);
	++tcnt;
	cout<<"Case #"<<tcnt<<": ";
	cout<<ans<<endl;

return;} // solve ends 



signed main() {
	// your code goes here
	#ifndef ONLINE_JUDGE
		freopen("err", "w", stderr);
	#endif
	fast
	const rlim_t kStackSize = 500 * 1024 * 1024;
  	struct rlimit rl;
  	int result;

	result = getrlimit(RLIMIT_STACK, &rl);
	if (result == 0) {
	if (rl.rlim_cur < kStackSize) {
	  rl.rlim_cur = kStackSize;
	  result = setrlimit(RLIMIT_STACK, &rl);
	  if (result != 0) {
	    // fprintf(stderr, "setrlimit returned result = %d\n", result);
	  }
	}
}

	auto start1 = chrono::high_resolution_clock::now();
	int t = 1; 
	cin>>t; 
	while(t--)
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

