
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


// int inf = 1e9;
class SGT{
	int n;
	vector<int> t;
public: 
	SGT(int n){
		this->n = n;
		this->t.resize(2*n);
		// for(int i=n; i<2*n; ++i)
		// 	t[i] = arr[i-n];

		// build();
	}
	void build(){
		for(int i = n-1; i>=1; --i) t[i] = t[i<<1] + t[i<<1 | 1];
	}

	int query(int l, int r){ //[l,r)
		int res = 0;
		for(l+=n, r+=n; l<r; l >>= 1, r >>=1){
			if(l&1) res += t[l++];
			if(r&1) res += t[--r]; 
		}
		return res;

	}

	void modify(int ind, int value){
		for(t[ind+=n]=value; ind >1; ind >>= 1) t[ind >> 1] = t[ind] + t[ind^1];
	}
};

void solve(){
	int n,m;
	cin >> n >> m;
	v(pr) a(n*m);

	fr(i,0,n*m){
		cin >> a[i].ff;
		a[i].ss = i;
	}

	sort(all(a));
	debug(a);
	int ans = 0;
	fr(i,0,n){ //place row wise
		//i*m to i*m+m-1
		for(int j=i*m; j<=i*m+m-1; ++j) a[j].ss *= -1;
		sort(a.begin()+i*m, a.begin()+i*m+m);
		for(int j=i*m; j<=i*m+m-1; ++j){
			for(int k=i*m; k<j; ++k){
				if(abs(a[k].ss) < abs(a[j].ss))
					ans++;
			}
		}
	}

	p1(ans);
}

/*
void solve(){ 
	int n, m;
	cin >> n >> m;
	// v(v(int)) a(n, v(int)(m))
	v(int) a(n*m),b;
	fr(i,0,n*m) cin >> a[i];
	b = a;
	sort(all(b));

	vector<SGT> t;
	fr(i,0,n){
		SGT temp(m+2);
		t.push_back(temp);
	}

	unordered_map<int, priority_queue<pr>> mp1;

	int ans = 0;
	fr(i,0,n*m){
		if(!mp1.count(a[i])){
			auto it  = upper_bound(all(b),a[i]) - b.begin(); //last seat number, 1-indexed
			auto it1 = lower_bound(all(b),a[i]) - b.begin();
			it1++; //first seat number,1-indexed
			int i1 = (it1-1)/m, j1 = (it1-1)%m, i2 = (it-1)/m, j2 = (it-1)%m; 			
			
			// cout<<a[i]<<" "<<it<<" "<<it1<<endl;
			if(i1==i2){
				int x = i1;
				for(int y=j1; y<=j2; ++y){
					mp1[a[i]].push({-x,y});
				}
			}
			else {
						for(int x=i1; x<=i1; ++x){
							for(int y=j1; y<=m-1; ++y){
								mp1[a[i]].push({-x,y});
								}
						}			
						for(int x=i1+1; x<i2; ++x){
							for(int y=0; y<=m-1; ++y){
								mp1[a[i]].push({-x,y});
							}
						}

						for(int x=i2; x<=i2; ++x){
							for(int y=0; y<=j2; ++y){
								mp1[a[i]].push({-x,y});
							}
						}
			}
		}
	}

	// for(auto &el : mp1){
	// 	cout<<endl<<el.ff<<endl;
	// 	while(el.ss.size()){
	// 		auto pp = el.ss.top();
	// 		el.ss.pop();
	// 		cout<<pp.ss<<" "<<pp.ff<<endl;
	// 	}
	// }
	// cout<<t.size()<<endl;
	fr(i,0,m*n){
		auto seat = mp1[a[i]].top();
		mp1[a[i]].pop();
		auto x = -seat.ff, y = seat.ss;
		debug(mp(x,y));
		ans += t[x].query(0,y);
		t[x].modify(y,1);

	}
	
	p1(ans);



return;} // solve ends 

*/

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

