
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


/***** Range incre update, range maximum query ******/ 
/********
 Syntax:
 	n => number of elements in array
 	t => segment tree (with size 4*n)
 	lazy => lazy tree (with size 4*n)

 Terminology of function parameters
 	arr -> array for SGT to be built
 	st  -> start index of the interval of arr for which SGT to be build
 	end -> end index ------------- ---------------- 
	tl  -> start index of tree interval
	tr  -> end index of tree interval
 	root -> node representing the interval [tl, tr] in SGT

 ********/
vector<int> dp1;
class ST {
	
	int n;
	vector<pr> t;
	vector<pr> lazy;
public:
	ST(int n) {
		this->n = n; 
		t.resize(4*n, {0,-1}); 
		lazy.resize(4*n, {0,-1}); 
	}

	void build(int st, int end, vector<int>&arr, int root = 1){
		if(st==end) {t[root] = {arr[st],st}; return;}
		if(st>end) return;
		int mid = st + (end-st)/2;
		build(st, mid, arr, 2*root);
		build(mid+1, end, arr, 2*root+1);
		t[root] = t[2*root].first > t[2*root+1].first ? t[2*root] : t[2*root+1];
	}

	void push(int tl, int tr, int root){
		if(lazy[root].first!=0){
			t[root].first  = lazy[root].first;
			t[root].second = lazy[root].ss;
			if(tl!=tr){
				lazy[2*root].ff    = lazy[root].ff;
				lazy[2*root+1].ff  = lazy[root].ff;
				lazy[2*root].ss = lazy[2*root+1].ss = lazy[root].ss;

			}
			lazy[root] = {0,-1};
		}
	}

	//incr update, i.e. each value is "val"
	void update(int l, int r, int val, int ind, int tl, int tr, int root){
		push(tl, tr, root);
		if(l>r) return;
		if(tl == l && tr == r){
			lazy[root].first  = val;
			lazy[root].second = ind;
			push(tl, tr, root);
			return;
		}
		int tm = (tl+tr)/2;
		update(l,min(r,tm), val, ind, tl, tm, 2*root);
		update(max(l,tm+1), r, val, ind, tm+1, tr, 2*root+1);
		t[root] = t[2*root].first > t[2*root+1].first ? t[2*root] : t[2*root+1];
	}

	pair<int,int> query(int l, int r, int tl, int tr, int root){
		if(l>r) return {-1e9,-1}; // infinity value, should change according to the possible range of t[i]
		push(tl, tr, root); //push of lazy tree
		debug(mp(l,r)); debug(mp(tl,tr)); debug(t[root]);

		if(l==tl && r == tr) {return t[root];}
		int tm = tl + (tr-tl)/2;
		pr q1 = query(l, min(r, tm), tl, tm, 2*root), q2 = query(max(l, tm+1), r, tm+1, tr, 2*root+1);
		return q1.first > q2.first ? q1 : q2;
	}

};

void coordinate_compression(vector<int> &a){
    int n = a.size();
    vector<pair<int, int>> pairs(n);
    for(int i = 0; i < n; ++i) { pairs[i] = {a[i], i};}
    sort(pairs.begin(), pairs.end());
    int nxt = 0;
    for(int i = 0; i < n; ++i) {
	    if(i > 0 && pairs[i-1].first != pairs[i].first) nxt++;
	    a[pairs[i].second] = nxt;
    }
}

void solve(){ 
	int n,m;
	cin >> n >> m;
	vector<vector<pair<int,int>>> segments(n);

	fr(i,0,m){
		int x,l,r; cin >> x >> l >> r;
		segments[x-1].push_back({l,r});
	}

	vector<int> tmp;
	fr(i,0,n){
		for(auto p : segments[i]){
			tmp.pb(p.ff);
			tmp.pb(p.ss);
		}
	}
	int j = 0, N = 0;
	coordinate_compression(tmp);

	fr(i,0,n){
		for(auto &p : segments[i]){
			p.ff = tmp[j++]; N = max(N,p.ff);
			p.ss = tmp[j++]; N = max(N,p.ss);
		}
	}
	tmp.clear();

	ST sgt(N+1);
	v(int) dp(n,-1);
	dp1.resize(n,1);
	fr(i,0,n){
		int mxi = 0, mx = 0;
		for(auto &p : segments[i]){
			pr pp = sgt.query(p.ff, p.ss, 0, N, 1);
			debug(pp);
			if(pp.ss>=0 && dp1[i] < dp1[pp.ss]+1){
				dp1[i] = dp1[pp.ss]+1;
				dp[i] = pp.ss;
			}
		}

		for(auto &p : segments[i])
			sgt.update(p.ff, p.ss, dp1[i], i, 0, N, 1);

	}

	// pr pp = sgt.query(0,N,0,N,1);
	debug(dp1);
	debug(dp);
	int st=0; 
	fr(i,0,n) if(dp1[i]>dp1[st]) st = i;

	p1(n-dp1[st]);
	debug(st);
	vector<bool> is(n,true);
	while(st!=-1){
		is[st] = false;
		st = dp[st];
	}

	fr(i,0,n){
		if(is[i]) cout<<i+1<<" ";
	}
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

