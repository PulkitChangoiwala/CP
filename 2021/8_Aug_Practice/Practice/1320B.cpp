
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

int n,m;
v(v(int)) adj;

void solve(){ 
	cin >> n >> m;
	adj.clear();
	adj.resize(n+1);
	v(v(int)) adjr(n+1);
	fr(i,0,m){
		int x,y;
		cin >> x >> y;
		adj[x].pb(y);
		adjr[y].pb(x); //reverse graphs
	}
	int k;
	cin >> k;
	v(int) p(k);
	fr(i,0,k) cin >> p[i];
	v(int) dis(n+1, -1);

	//find sssp from p[k-1]
	queue<int> q;
	q.push(p[k-1]);
	dis[p[k-1]] = 0;
	while(!q.empty()){
		int v = q.front(); q.pop();

		for(auto u : adjr[v]){
			if(dis[u]==-1){
				q.push(u);
				dis[u] = dis[v]+1;
			}
		}
	}
	debug(dis);
	int mn = 0;
	//min
	for(int i=1; i<k; ++i){
		if(dis[p[i]] != dis[p[i-1]]-1) mn++;
	}

	//max 
	int mx = 0;

	for(int i=0; i<k-1; ++i){
		int f = -1;
		for(auto u : adj[p[i]]){
			debug(mp(p[i],u));
			if(dis[u] == dis[p[i]]-1 && u != p[i+1]){
				debug(f);
				f = u;
			}
		}

		if(f==-1) {
			// if(dis[p[i+1]] != dis[p[i]]-1) mx++;
		}	
		else {
			debug(f);
			mx++;
		}
	}
	p2(mn,mx);
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
