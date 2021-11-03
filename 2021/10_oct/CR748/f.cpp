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

/*
//solution 1
int a,b;
v(v(int)) diff;
int dp[41][41][41][41];
void dfs(int i, int r1, int r2, int red, string &s){
	if(i==s.length()-1){
		int res1 = red - (s.length()-red); 
		if(r1==0 && r2==0 && red && red<s.length())
			diff[i][abs(res1)]++;
		return;
	}
	if(dp[i][r1][r2][red]!=-1) return;
	//paint i+1 
	int nr1  = (r1*10 + (s[i+1]-'0'))%a; //red
	int nr2  = (r2*10 + (s[i+1]-'0'))%b; //black
	dfs(i+1, nr1, r2, red+1, s);
	dfs(i+1, r1, nr2, red, s);
	dp[i][r1][r2][red] = 1;
	return;
}

int dfs1(int i, int r1, int r2, int red, string &s, int d){
	if(i==s.length()-1){
		int res1 = red - (s.length()-red); 
		if(r1==0 && r2==0 && abs(res1) == d && abs(res1)!=s.length()) return 0;
		return -1;
	}
	if(dp[i][r1][r2][red]!=-1) return dp[i][r1][r2][red];
	//paint i+1 
	int nr1  = (r1*10 + (s[i+1]-'0'))%a; //red
	int nr2  = (r2*10 + (s[i+1]-'0'))%b; //black
	int res1 = dfs1(i+1, nr1, r2, red+1, s, d);
	int res2 = dfs1(i+1, r1, nr2, red, s, d);
	dp[i][r1][r2][red] = (res1>=0)?2*res1+1 : (res2>=0)? 2*res2 : -2;
	return dp[i][r1][r2][red];
}
void solve(){ 
	int n;
	cin >> n;
	cin >> a >> b;
	string s;
	cin >> s;
	memset(dp, -1, sizeof dp);
	diff.clear();
	diff.resize(n+1, vector<int>(100,-1));

	int nr1  = ((s[0]-'0'))%a; //red
	int nr2  = ((s[0]-'0'))%b; //black
	dfs(0,nr1,0,1,s);
	dfs(0,0,nr2,0,s);	

	for(int d=0; d<n; ++d){
		if(diff[n-1][d]!=-1){
			// p1(d);
			memset(dp, -1, sizeof dp);
			int mask, mask1 = dfs1(0,nr1,0,1,s,d), mask2 = dfs1(0,0,nr2,0,s,d);	
			string res = "";
			if(mask1 >=0)mask = 2*mask1 + 1;
			else mask = 2*mask2;
				
			// debug(mask);
			for(int i=0; i<n; ++i){
				if(mask&(1ll<<i)) res += 'R';
				else res += 'B';
			}
			p1(res);
			return;
		}
	}

	p1(-1);

return;} // solve ends 
*/

//solution 2

int n,a,b;
int curr[41], res[41];
int ans;
int vis[41][41][41][41];

void dfs(int i, int red, int r1, int r2, string &s){
	if(vis[i][red][r1][r2]) return;
	vis[i][red][r1][r2] = 1;

	if(i==n){
		if(!r1 && !r2 && red && red<n && abs(n-2*red) < ans){
			ans = abs(n-2*red);
			for(int i=0; i<n; ++i){
				res[i] = curr[i];
			}
		}
		return;
	}
	//current as red 
	curr[i] = 1;
	int nr1 = (r1*10 + s[i]-'0')%a;
	dfs(i+1,red+1,nr1,r2,s);
	//current as black
	curr[i] = 0;
	int nr2 = (r2*10 + s[i]-'0')%b;
	dfs(i+1,red,r1,nr2,s);	
}
void solve(){
	cin >> n;
	cin >> a >> b;
	string s;
	cin >> s;
	ans = 50;
	memset(vis, 0, sizeof vis);
	dfs(0,0,0,0,s);
	if(ans==50) {
		p1(-1);
		return;
	}
	string st = "";
	for(int i=0; i<n; ++i){
		if(res[i]) st += 'R';
		else st += 'B';
	}
	p1(st);

}

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