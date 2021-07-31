
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
    return (a+b)%mod;
}
int mul(int a, int b){
    return (1ll*a*b)%mod;
}
vector<int> fact, invf;

int processFactInvF(n){
    fact.clear(); fact.resize(n+1);
    invf.clear(); invf.resize(n+1);
}
int factt(int n){
    if(fact[n]) return fact[n];
    if(n==0 || n==1) return fact[n] = 1;
    return fact[n] = mul(factt(n-1),n);
}
int invff(int n){
    if(invf[n]) return invf[n];
    if(n==1) return invf[n] = 1;
    //invf[i] = invf[i+1]*(i+1)%mod; prove usine (i+1)! = (i+1)*(i!)
    int res = 1, x = factt(n), y = mod-2;
    while(y) {if(y&1) res = mul(res,x); x=mul(x,x); y>>=1;}
    return invf[n] = res;
}

int comb(int n, int r) {
    return mul(mul(factt(n), invff(r)), invff(n-r)); //=n!/(r!*(n-r)!)
}
*/



class ST {
	int n;
	vector<int> t;
	vector<int> lazy;
public:
	ST(int n) {
		this->n = n; 
		t.resize(4*n, 0); 
		lazy.resize(4*n,0); 
	}

	void build(int st, int end, vector<int>&arr, int root = 1){
		if(st==end) {t[root] = arr[st]; return;}
		if(st>end) return;
		int mid = st + (end-st)/2;
		build(st, mid, arr, 2*root);
		build(mid+1, end, arr, 2*root+1);
		t[root] = min(t[2*root],t[2*root+1]);
	}

	void push(int tl, int tr, int root){
		if(lazy[root]!=0){
			
			t[root] += lazy[root];
			if(tl!=tr){
				lazy[2*root]+=lazy[root];
				lazy[2*root+1]+=lazy[root];

			}
			lazy[root] = 0;
		}
	}

	//incremental update, i.e. increase each value by "val"
	void update(int l, int r, int val, int tl, int tr, int root){
		push(tl, tr, root);
		if(l>r) return;
		if(tl == l && tr == r){
			lazy[root] += val;
			push(tl, tr, root);
			return;
		}
		int tm = (tl+tr)/2;
		update(l,min(r,tm), val, tl, tm, 2*root);
		update(max(l,tm+1), r, val, tm+1, tr, 2*root+1);
		t[root] = min(t[2*root], t[2*root+1]);
	}

	int query(int l, int r, int tl, int tr, int root){
		if(l>r) return 1e9; // infinity value, should change according to the possible range of t[i]
		push(tl, tr, root); //push of lazy tree
		if(l==tl && r == tr) {return t[root];}
		int tm = tl + (tr-tl)/2;
		return min( query(l, min(r, tm), tl, tm, 2*root),
			query(max(l, tm+1), r, tm+1, tr, 2*root+1)
			);
	}

};

void solve(){ 
	int n,m;	
	cin >> n >> m;
	v(v(int)) vt(n, v(int)(3));
	fr(i,0,n){ 
		cin >> vt[i][0] >> vt[i][1] >> vt[i][2];
		//as we need segments to overlap
		vt[i][0]++; //atleast starting of this segment should be covered by some other segment
		if(vt[i][0]>vt[i][1]) {vt[i][0] = 0; vt[i][1] = 0;} 
	}

	sort(all(vt), [&](vector<int> &a, vector<int> &b){
		return a[2] < b[2];
	});

	ST st(m+1);
	debug(vt);
	int mn, j = 0, ans = 1e9;
	fr(i,0,n){
		st.update(vt[i][0], vt[i][1], 1, 0, m, 1); //increase by one
		mn = st.query(2,m, 0, m, 1);
		while(j<=i && mn >= 1){
			ans = min(ans, vt[i][2]-vt[j][2]);
			st.update(vt[j][0], vt[j][1], -1, 0, m, 1); //decrement by one
			mn = st.query(2,m, 0, m, 1);
			j++;
		}
	}


	p1(ans);





return;} // solve ends 



signed main() {
	// your code goes here
	#ifndef ONLINE_JUDGE
		freopen("err", "w", stderr);
	#endif
	fast


	auto start1 = chrono::high_resolution_clock::now();
	int t = 1; 
	// cin>>t; 
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

