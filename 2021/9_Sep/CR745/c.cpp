
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
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*

		 	Size       Timelimit   Sure Shot       			    Try

1.   n <= 200      1s          n^3          			   n^4 (with pruning)
2.   n <= 500      1s          n^3(may be            n^4 (with pruning)
																small adjustment) 					
3.   n <= 5000     1s          n^2
4.   n <= 2*10^5   1s          nLogn								 n(rootN) may work in some cases
5.   n <= 10^6     1s					 nLogn

If Timelimit > 1s, Scale them accordingly.

*/



int pref[402][402];
int get(int i, int j, int i1, int j1, int to){
	int ones = pref[i1+1][j1+1] - pref[i][j1+1] - pref[i1+1][j] + pref[i][j];

	if(to==0) return ones;
	return (j1-j+1)*(i1-i+1) - ones; 
}

void solve(){ 
	
	int n, m;
	cin >> n >> m;

	v(string) a(n);
	fr(i,0,n){
		cin >> a[i];
	}

	fr(i,1,n+1){
		fr(j,1,m+1){
			pref[i][j] = pref[i-1][j] + pref[i][j-1] 
				- pref[i-1][j-1] + (a[i-1][j-1]=='1');
		}
	}

	int ans = 17;
	for(int b=4; b<=m; ++b){
		for(int j=0;j+b-1<m; ++j){
			int prev = 0, i = 4, prefMax, st = j, end = j+b-1;
			//base case
			prev = get(i,st+1,i,end-1,1) 
				+ get(0,st,i-1,st,1) + get(0,end,i-1,end,1)
				+ get(0,st+1,i-1,end-1,0); 

			prefMax = (a[0][st]=='0') + (a[0][end]=='0') + get(0,st+1,0,end-1,0)
				- get(0,st+1,0,end-1,1);

			ans = min(ans, prev - prefMax);
			for(i=5; i<n; ++i){

				int I = i-4, curr_remove = 
				- get(I,st+1,I,end-1,1) 
				+  get(0,st+1,I,end-1,0) 
				+ get(0,st,I,st,1) + get(0,end,I,end,1);

				prefMax = max(curr_remove, prefMax);


				int curr = prev + get(i,st+1,i,end-1,1) + 
						(-get(i-1,st+1,i-1,end-1,1) + get(i-1,st+1,i-1,end-1,0) + 
							(a[i-1][st]=='0') + 
							(a[i-1][end]=='0'));

				ans = min(ans, curr-prefMax);
				prev = curr;
			}				
		}
	}

	p1(ans);

return;} // solve ends 



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

