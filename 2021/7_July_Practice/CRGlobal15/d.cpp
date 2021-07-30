
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



void solve(){ 
	int n, flag = 0;
	cin >> n;
	v(int) a;
	set<int> st;
	a.clear(); st.clear();
	a.resize(n);
	set<int> st1;
	fr(i,0,n) { 
		cin >> a[i]; 
		if(st1.find(a[i])!=st1.end() || st1.find(-a[i])!=st1.end()) {flag = 1;}
		else 
		st1.insert(a[i]);
	}

	if((st1.find(0)!=st1.end()) || flag) {p1("YES"); return;}
	// st.insert(a[0]);
	// st.insert(-a[0]);
	// fr(i,1,n){
	// 	// if(st.find(a[i])!=st.end()) {flag = 1; break;}
	// 	debug(st);
	// 	vector<int> tmp;
	// 	for(auto el : st){
	// 		// debug(el);
	// 		auto it1 = st1.find(el+a[i]);
	// 		auto it2 = st1.find(el-a[i]);
	// 		if(((it1!=st1.end()) && (*it1 != a[i])) || 
	// 			((it2!=st1.end()) && (*it2 != a[i]))){
	// 			// debug(st1);
	// 			// debug(el+a[i]);
	// 			flag = 1; break;

	// 		}
	// 		tmp.pb(el+a[i]); 
	// 		tmp.pb(el-a[i]);
	// 	}

	// 	if(flag) break;
	// 	for(auto el : tmp){
	// 		if(el) {
	// 			st.insert(el);

	// 		}
	// 	}

	// 	st.insert(a[i]);
	// 	st.insert(-a[i]);
	// }
	fr(j,0,n){
		st.clear();
		fr(i,0,n){
			if(i==j) continue;
			vector<int> tmp;
			for(auto el : st){
				tmp.pb(el+a[i]); 
				tmp.pb(el-a[i]);
			}

			for(auto el : tmp){
					st.insert(el);
			}
			st.insert(a[i]);
			st.insert(-a[i]);
		}
		auto it1 = st.find(a[j]);
		auto it2 = st.find(-a[j]);
		if(it1!=st.end() || it2!=st.end()) {flag = 1; break;}
	}
	debug(st);
	if(flag) {p1("YES"); return;}
	p1("NO");

return;} // solve ends 



signed main() {
	// your code goes here
	#ifndef ONLINE_JUDGE
		freopen("err", "w", stderr);
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

