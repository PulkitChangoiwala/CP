
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




void solve(){ 
	int n, MIN = 1e9;
	cin >> n;

	v(int) a(n);
	fr(i,0,n) {cin >> a[i]; MIN = min(MIN, a[i]);}
	map<int,int> num;
	fr(i,0,n){
		a[i] -= MIN;
		num[a[i]]++;
	}
	for(auto &pp : num){
		if(pp.second >= n/2){
			p1(-1);
			return;
		}
	}

	sort(all(a));
	int ans = 1;
	// for(int i=n/2 + 1;)
	// debug(a);
	for(int i=n/2; i>=0; --i){
		vector<int> b(a.begin()+i+1, a.end());
		// debug(b);
		int z = 0;
		for(auto &el : b) {
			el -= a[i];
			if(!el) z++;
		}
		// debug(b);
		
		map<int,int> temp;
		for(int j=b.size()-1; j>=0; --j){
			int sq = sqrt(b[j]);
			for(int k=1; k<=sq; ++k){
				if(b[j]%k==0) {
					temp[k]++;
					if(temp[k] + z >= n/2 - 1) ans = max(ans, k);

					if(k*k!=b[j]) {
						int k1 = b[j]/k;
						temp[k1]++;
						if(temp[k1] + z >= n/2 - 1) ans = max(ans, k1);
					}
				}
			}
		}
	}
	p1(ans);

/*
	int Max = num.rbegin()->ff;
	int ans = 1;
	for(int d=Max; d>=1; --d){
		int tt = 0;
		map<int,int> temp;
		for(auto &pp : a){
			temp[pp%d]+= 1;
			tt = max(temp[pp%d], tt);
		}
		if(tt>=n/2)
			{ans = d; break;}
	}	
	p1(ans);
*/

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

