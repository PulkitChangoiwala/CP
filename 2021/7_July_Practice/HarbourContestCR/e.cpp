
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



int n,m;
int find(vector<int> &ds, int i) {
    return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
}
bool Union(vector<int> &ds, int i, int j){
	 i = find(ds, i), j = find(ds, j);
	 if(i==j) return false;
	 if(abs(ds[i]) < abs(ds[j])) swap(i,j); 
	 ds[i]+=ds[j]; 
	 ds[j]=i;
	 return true;
}

void shifted(v(int)&perm, int k){
	int j = 0;
	for(int i=n-k+1; i<=n; ++i) perm[j++] = i;
	for(int i=1;i<=n-k;++i) perm[j++] = i;
}

void solve(){ 
	cin >> n >> m;
	v(int) pp(n), pos(n+1),ans;
	v(int) perm(n), ds(n), possibleK;

	/*
	- Let permutation is [0,1,2,3, ..., n-1] instead
	of [1,2,3,...,n]
	- then kth right cyclic shift can be represented by
		- pk_i = (i-k)%n

	- we are allowed only m swaps
	=> 2*m elements can be swapped
	=> atleast n-2*m elements should be in correct position
	
	- Let cntk be the number of elements which are in 
	correct position of k cyclic shift
	- Observation: for each i there can be only one k, 
			such that pk_i = pi (p is permutation given in question)
			- Sigma cntk for all k == n
	
	- We need to find all k, s.t cntk >= n-2m
	

	Algorithm to find k
		- for each i, find k, such that both are in correct
			postion


	*/
	vector<int> cntk(n+1);
	fr(i,0,n) {
		cin >> pp[i];
		pos[pp[i]] = i;
		int oldIndex = pp[i]-1;
		if(i>=oldIndex) cntk[i-oldIndex]++;
		else cntk[n-1-oldIndex+i-0+1]++;

	}
	


	for(int k=0; k<=n-1;++k){
		if(cntk[k]<n-2*m) continue;
		shifted(perm, k);
		ds.assign(n, -1);
		fr(i,0,n){
			if(pos[perm[i]] != i) {
				Union(ds, pos[perm[i]], i);
			}
		}
		int swaps = 0;
		fr(i,0,n){
			if(ds[i]<0) swaps += abs(ds[i])-1;
		}
		if(swaps<=m) ans.pb(k);
		// p3("Para: ", k, swaps);
	}

	debug(ans);
	cout<<ans.size()<<" ";
	for(auto el : ans) cout<<el<<" ";
	cout<<endl;
return;}



signed main() {
	// your code goes here
	#ifndef ONLINE_JUDGE
		freopen("Error.txt", "w", stderr);
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

