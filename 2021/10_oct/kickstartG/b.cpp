
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


int d1(vector<int> &vt, int x, int y){
	//bottom left, top right
	int x1 = min(abs(x-vt[0]), abs(x-vt[2]));
	int y1 = min(abs(y-vt[1]), abs(y-vt[3]));
	if(vt[0]<=x && x<=vt[2]){
		x1 = 0;
	}
	if(vt[1]<=y && y<=vt[3]){
		y1 = 0;
	}
	return x1+y1;
}

int d(v(v(int)) &pt, int x, int y){
	int res = 0;
	for(auto &vt : pt){
		res += d1(vt,x,y);
	}
	return res;
}
int g(v(pr) &pt, int x){
	int res = 0;

	for(auto &t : pt){
		if(t.ss == 1){
			res += t.ff-x;
		}
	}
	return res;
}

int f(v(pr) &pt){
	int n = pt.size(), ed = 0, st = 1, last = pt[0].ff, total = pt.size()/2;
	int dis = 0, curr = INF, ans = pt[0].ff;
	dis = curr = g(pt,ans);	
	// debug(pt);
	// debug(dis);
	// debug(last);
	for(int i=1; i<n; ++i){
		int change = pt[i].ff - last;
		if(pt[i].ss == -1){ //end
			dis += ed*(change);
			ed++;
			st--;
			dis -= (total - st - ed)*(change);
		}
		else {  //start
			dis += ed*(change);
			dis -= (total - st - ed)*(change);
			st++;
		}
		// debug(dis);
		if(dis < curr){
			curr = dis;
			ans = pt[i].ff;
		}
		last = pt[i].ff;
	}

	return ans;
}
int tcnt;
void solve(){ 
	int k;
	cin >> k;
	v(v(int)) pts(k, v(int)(4));
	fr(i,0,k){
		cin >> pts[i][0] >> pts[i][1] >> pts[i][2] >> pts[i][3];
	}

	v(int) ans(2);
	// int curr = INF;
	// for(int x=-110; x<=110; ++x){
	// 	for(int y=-110; y<=110; ++y){
	// 		int dis = d(pts,x,y);
	// 		if(dis < curr){
	// 			ans = {x,y};
	// 			curr = dis;
	// 		}
	// 	}
	// }

	v(pr) xs, ys;
	for(auto &vt : pts){
		xs.push_back({vt[0],1});
		xs.push_back({vt[2],-1});
		ys.push_back({vt[1],1});
		ys.push_back({vt[3],-1});

	}
	sort(all(xs));
	sort(all(ys));
	ans[0] = f(xs);
	ans[1] = f(ys);

	++tcnt;
	cout<<"Case #"<<tcnt<<": ";
	cout<<ans[0]<<" "<<ans[1]<<endl;

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

