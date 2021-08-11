
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

// void _print(ll t) {cerr << t;}
// void _print(int t) {cerr << t;}
// void _print(string t) {cerr << t;}
// void _print(char t) {cerr << t;}
// void _print(lld t) {cerr << t;}
// void _print(double t) {cerr << t;}
// void _print(ull t) {cerr << t;}

// template <class T, class V> void _print(pair <T, V> p);
// template <class T> void _print(vector <T> v);
// template <class T> void _print(set <T> v);
// template <class T, class V> void _print(map <T, V> v);
// template <class T> void _print(multiset <T> v);
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


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
/*
Let we have to answer for x
let at ith minute we just cross or equal to x
at 
i th minute ->  3*i C x
i+1 ->  3*(i+1) C x
i+2 ->  3*(i+2) C x
.
.
.

3*n ->	3*nCx


ans[x] = sigma{i from 1 to N} 3iCx

dp[x][m] = sigma{i from 0 to N-1} 3i+mCx

so ans[x] = dp[x][0] + 3*nCx

we now using 
1) hockey stick identity:
	1cr + 2cr .... ncr == n+1cr+1

2) nCr = n-1Cr-1 + n-1Cr

//three dp states for each x

We have three equations to solve for each x
*** dp[x][0] + dp[x][1] + dp[x][2] = 
	sigma{i from 0 to 3*N-1}(iCx)  = 3*NCx+1 (using identity 1)

*** dp[x][1] = sigma(3i+1Cx) = sigma(3iCx) + sigma(3iCx-1)
		 = dp[x][0] + dp[x-1][0]
*** similarly, dp[x][2] = dp[x][1] + dp[x-1][1]


Equations:
a) dp[x][0] + dp[x][1] + dp[x][2] = 3*NCx+1 
b) dp[x][1] = dp[x][0] + dp[x-1][0]
c) dp[x][2] = dp[x][0] + dp[x-1][0] + dp[x-1][1]
answer for x, ans[x] = dp[x][0] + 3*nCx

Base Cases
dp[0][0] = sigma{i from 0 to N-1}(0C0) = N
dp[0][1] = sigma{i from 0 to N-1}(1C0) = N
dp[0][2] = sigma{i from 0 to N-1}(2C0) = N

//solving
1) 3*dp[x][0] + 2*dp[x-1][0] + dp[x-1][1] = 3*nCx+1

*/



void solve(){ 
	int n, q;
	cin >> n >> q;

	int dp[3*n+1][3];
	dp[0][0] = n;
	dp[0][1] = n;
	dp[0][2] = n;

	Combo c(3*n+1);
	int inv3 = 333333336; 
	for(int x = 1; x<=3*n; ++x){
		dp[x][0] = mul(ad(c.choose(3*n,x+1), -ad(mul(2, dp[x-1][0]), dp[x-1][1])), inv3);
		dp[x][1] = ad(dp[x][0],dp[x-1][0]);
		dp[x][2] = ad(dp[x][1],dp[x-1][1]);
	}

	//preprocess

	fr(i,0,q){
		int x;
		cin >> x;
		//ans[x] = dp[x][0] + 3*nCx
		int ans = ad(dp[x][0], c.choose(3*n,x));
		p1(ans);


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

