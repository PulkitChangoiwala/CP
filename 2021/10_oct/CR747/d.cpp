
#include <bits/stdc++.h>
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


// int find(vector<int> &ds, int i) {
//     return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
// }

// bool Union(vector<int> &ds, int i, int j){
// 	 i = find(ds, i), j = find(ds, j);
// 	 if(i==j) return false;
// 	 if(abs(ds[i]) < abs(ds[j])) swap(i,j); 
// 	 ds[i]+=ds[j]; 
// 	 ds[j]=i;
// 	 return true;
// }

int flag;
//0 for imposter, 1 crewmate
int dfs(int st, vector<vector<pair<int,int>>> &adj, vector<int>&vis, int type){
	int res = 1-type;
	vis[st] = type;
	// cout<<st<<" "<<type<<endl;
	for(auto &pp : adj[st]){
		int T = (type==0)? 1-pp.second : pp.second;
		if(vis[pp.first]==-1){
			res += dfs(pp.first, adj, vis, T);
		}
		else if(vis[pp.first]!=T){
			flag = -1;
			return -1;
		}
	}
	return res;
}
void solve(){ 
	int n,m;
	cin >> n >> m;
	vector<vector<pair<int,int>>> adj(n+1);	
	fr(i,0,m){
		int it,j;
		cin >> it >> j;
		string s;
		cin >> s;
		int type = (s=="imposter")? 0 : 1;
		adj[it].pb({j,type});
		adj[j].pb({it,type});
	}

	// debug(adj);
	flag = 0;
	int ans = 0;
	vector<int> vis(n+1, -1);
	vector<int> res1;
	for(int i=1; i<=n; ++i){
		if(vis[i]==-1){
			int t1 = dfs(i,adj,vis,0);
			ans += t1;
			res1.push_back(t1);
		}

	}


	int ans1 = 0;
	vis.assign(n+1,-1);
	vector<int> res2;
	int Nflag = flag;
	flag = 0;
	for(int i=1; i<=n; ++i){
		if(vis[i]==-1){
			int t1 = dfs(i,adj,vis,1);
			ans1 += t1;
			res2.push_back(t1);
		}
	}

	if(flag == -1  && Nflag == -1) p1(-1);
	else if(flag==-1) p1(ans);
	else if(Nflag==-1) p1(ans1);
	else {
		int res = 0;
		for(int i=0; i<res1.size(); ++i){
			res += max(res1[i], res2[i]);
		}
		p1(res);
	}

return;} // solve ends 



signed main() {
	// your code goes here
	#ifndef ONLINE_JUDGE
		freopen("/home/changoi/Desktop/Main/CP/Debug/err", "w", stderr);
	#endif
	fast


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










/******************


     Size       Timelimit     Sure Shot       			    Try

1.   n <= 200      1s          n^3                   n^4 (with pruning)
2.   n <= 500      1s          n^3(small prune)      n^4 (with pruning) 					
3.   n <= 5000     1s          n^2
4.   n <= 2*10^5   1s          nLogn                 n(rootN) may work in some cases
5.   n <= 10^6     1s          nLogn

If Timelimit > 1s, Scale them accordingly.



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

**************/

