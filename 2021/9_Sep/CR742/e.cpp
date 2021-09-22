
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


/***** Range incremental update, range assignment update, range sum query ******/ 
/********
 Syntax:
 	n => number of elements in array
 	t => segment tree (with size 4*n)
 	lazy => lazy tree (with size 4*n) for incremental updates
 	lazy_ => lazy tree (with size 4*n) for assignmental updates
 Terminology of function parameters
 	arr -> array for SGT to be built
 	st  -> start index of the interval of arr for which SGT to be build
 	end -> end index ------------- ---------------- 
	tl  -> start index of tree interval
	tr  -> end index of tree interval
 	root(here var v is used) -> node representing the interval [tl, tr] in SGT
 	type -> type of update, incremental or update,  type==1 for incremental

 ********/

vector<int> a;
struct NODE{
    // write required attributes
    // ll mn;

	ll l, r, ans;
    //Default values
    NODE(){
    	l = -1;
    	r = -1;
    	ans = 0;
        // mn = (ll)(1e13);
    }
};

struct SegTree{
    ll N;
    vector<NODE>st; // segment tree
    vector<bool>clazy;
    vector<ll>lazy;

    /*
        Convention.
            1 is the root of segment tree.
            L,R: Denotes Segment Tree Range = [1,N] for complete tree
            i,j: Denotes the interval range for which we need the answer
    */

    void init(ll n){
        N = n;
        st.resize(4*N+5);
        clazy.assign(4*N+5, false);
        lazy.assign(4*N+5,0);
    }

    // Write required merge function
    void merge(NODE &curr, NODE &l, NODE &r, int i, int j){
		
    	if(l.l==-1) {curr = r; return;}
    	else if(r.l==-1) {curr=l; return;}

		int mid = (i+j)/2;
		curr.ans = l.ans + r.ans;
		curr.l   = l.l;
		curr.r   = r.r;

		if(a[mid] > a[mid+1]){
			return; 
		}

		curr.ans += (l.r)*(r.l);
		curr.l   += ((l.r == mid-i+1) ? r.l : 0);
		curr.r   += ((r.r == j-mid)   ? l.r : 0); 
		return;
    }

    void build(ll node, ll L, ll R, vector<int> &arr){ 
    	//node-> NODE number. L,R array indexes (0-indexed)
        if(L==R){
            st[node].ans = 1;
            st[node].l   = 1;
            st[node].r   = 1;
            return;
        }
        ll mid = (L+R)/2;
        build(2*node,L,mid,arr);
        build(2*node+1,mid+1,R,arr);
        merge(st[node], st[2*node], st[2*node+1], L, R);
    }

    NODE Query(ll node, ll L, ll R, ll i, ll j){

        if(j < L || i > R){
            return NODE();
        }
        if(i <= L && j >= R){ 
            //current tree node [L,R] completely lies inside [i,j]
            return st[node];
        }
        ll mid = (L+R)/2;
        NODE left = Query(2*node,L,mid,i,j);
        NODE right = Query(2*node+1, mid+1,R, i,j);
        NODE curr;
        merge(curr, left, right, L, R);
        return curr;
    }

    void pUpdate(ll node, ll L, ll R, ll pos, ll val)
	{

		if(L == R)
		{
			st[node].ans = 1;
			st[node].l = 1;
			st[node].r = 1;
			return;
		}
		ll mid = (L + R)/2;
		if(pos <= mid)
			pUpdate(node*2, L, mid, pos, val);
		else
			pUpdate(node*2 + 1, mid + 1, R, pos, val);
		merge(st[node], st[node*2], st[node*2 + 1], L, R);
	}

	NODE query(ll l, ll r)
	{
		return Query(1, 0, N-1, l, r);
	}

	void update(ll pos, ll val)
	{
		pUpdate(1, 0, N-1, pos, val);
	}

};



// pair<int,pair<int,int>> query(int l, int r, vector<int>&a){
// 	if(l==r){
// 		return {1,{1,1}};
// 	}
// 	int mid = (l+r)/2;
// 	pair<int,pair<int,int>> pp1 = query(l,mid,a); 
// 	pair<int,pair<int,int>> pp2 = query(mid+1,r,a);
// 	if(a[mid] > a[mid+1]){
// 		return {pp1.ff + pp2.ff, {pp1.ss.ff, pp2.ss.ss}};
// 	}

// 	int x = pp1.ff + pp2.ff + (pp1.ss.ss)*(pp2.ss.ff);
// 	int y = pp1.ss.ff + ((mid-l+1==pp1.ss.ff) ? pp2.ss.ff : 0);
// 	int z = pp2.ss.ss + ((r-mid == pp2.ss.ff) ? pp1.ss.ss : 0);
// 	return {x,{y,z}};

// }

void solve(){ 
	
	int n,q;
	cin >> n >> q;
	a.clear();
	a.resize(n);
	fr(i,0,n) 
		cin >> a[i];

	SegTree sgt;
	sgt.init(n);
	sgt.build(1,0,n-1,a);
	debug(a);
	fr(i,0,q){
		int t, l, r;
		cin >> t >> l >> r;
		l--; r--;

		if(t==2){
			// int ans = query(l,r,a).ff;
			int ans = sgt.query(l,r).ans; 
			p1(ans);
		}
		else {
			r++;
			debug(a);
			a[l] = r;
			debug(a);
			sgt.update(l,r);
		}

	}

return;} // solve ends 



signed main() {
	// your code goes here
	#ifndef ONLINE_JUDGE
		freopen("err", "w", stderr);
	#endif
	fast


	auto start1 = chrono::high_resolution_clock::now();
	int t = 1; 
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

