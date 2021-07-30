
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
#define f first
#define s second
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
	/*
		algo: 
			- free points do an optimal construction
			- then calculate total intersection
	*/
	int n,k;
	cin >> n >> k;
	int ans = (n-k)*(n-k-1)/2; //all rem n-k  chords

	v(pr) a(k);
	v(int) fre(2*n+1, 1);
	fr(i,0,k) {
		cin >> a[i].f >> a[i].s; 
		fre[a[i].f]=0; fre[a[i].s]=0;
	}
	// debug(ans);
	// debug(fre);
	fr(i,0,k){
		int x = min(a[i].f, a[i].s), y = max(a[i].f, a[i].s); 
		int t1=0,t2=0;
		// debug(x); debug(y);
		for(int j=x+1; j<y; ++j){
			if(fre[j]) t1++;
		}
		// debug(i);
		// debug(t1);

		t2 = 2*(n-k) - t1;
		// debug(t2);
		ans += min(t1,t2);
	}
	debug(ans);
	int tmp = 0;
	fr(i,0,k){
		int x = min(a[i].f, a[i].s), y = max(a[i].f, a[i].s);
		fr(j,0,k){
			if(i==j) continue;
			int x1 = min(a[j].f, a[j].s), y1 = max(a[j].f, a[j].s);
			vector<int> tt = {x,x1,y,y1};
			sort(all(tt));
			if(tt[0]==x && tt[1]==x1 && tt[2]==y && tt[3]==y1) tmp++;
			else if(tt[0]==x1 && tt[1]==x && tt[2]==y1 && tt[3]==y) tmp++;

		} 
	}
	debug(tmp);
	ans += tmp/2;

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

