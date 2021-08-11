
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

/*

A noble is defined to be vulnerable if both of the following conditions are satisfied:

the noble has at least one friend, and
all of that noble's friends have a higher power.


 - single node does not get affected
 - and at the end of any process, all nodes should be isolated, other wise we cam always kill someone


 4 - 1 - 3

*/

void solve(){ 
	int n, m;
	cin >> n >> m;
	int cnt  = 0; 
	int mx = 1e9;
	vector<int> s(n+1, 0), l(n+1, 0);

	int u, v;
	fr(i,0,m){
		cin >> u >> v;
		int t1 = min(u,v), t2 = max(u,v);
		l[t1]++; s[t2]++;
	}

	for(int i=1;i <=n; ++i) if(l[i]==0) cnt++;

	int t,q;
	cin >> q;
	fr(i,0,q){
		cin >> t;
		if(t==1){
			cin >> u >> v;
			int t1 = min(u,v), t2 = max(u,v);
			l[t1]++; s[t2]++;
			if(l[t1]==1) cnt--;
		}
		else if(t==2){
			cin >> u >> v;
			int t1 = min(u,v), t2 = max(u,v);
			l[t1]--; s[t2]--;
			if(l[t1]==0) cnt++;
		}
		else if(t==3){
			//cnt of i's such that l[i] = 0;
			p1(cnt);
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

