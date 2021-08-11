
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



void solve(){ 
	int n;
	cin >> n;
	vector<int> vt;
	long long ans = 0;
	fr(i,0,n){
		int sz;
		cin >> sz;
		int x=0,y=0,cnt = 1,mx=0,sum=0;
		cin >> y;
		x = y;
		fr(j,1,sz){		
			cin >> y;
			if(y<x) {
				vt.pb(cnt);
				sum += cnt;
				mx = max(mx,cnt);
				cnt = 1;
				x = y;
			}
			else{
				cnt++;
				x = y;
			}
		}
		if(cnt>0) { 
			vt.pb(cnt); 
			sum += cnt;
			mx = max(mx,cnt);
		}
		int tans = sum - mx;
		// debug(tans);
		ans += tans;
		// for(auto el : vt) cout<<el<<" ";cout<<endl;
		// debug(vt);
	}
	// sort(all(vt));
	multiset<int> st(all(vt));
	long long tt, sz = vt.size();
	while(st.size()>1){
		int tmp1 = *(st.begin()); st.erase(st.begin());
		int tmp2 = *(st.begin()); st.erase(st.begin());
		ans += (tmp1+tmp2);
		st.insert(tmp1+tmp2);

	}	
	// tt = sz-1; 
	// fr(i,1,sz){
	// 	ans += tt*vt[i];
	// 	tt--;
	// }
	// ans += (sz-1)*vt[0];
	p1(ans); 

return;} // solve ends 



signed main() {
	// your code goes here
	// #ifndef ONLINE_JUDGE
	// 	freopen("err", "w", stderr);
	// #endif
	// fast


	// auto start1 = chrono::high_resolution_clock::now();
	int t = 1; 
	cin>>t; 
	while(t--)
	{solve();}
	// auto stop1 = chrono::high_resolution_clock::now();
	// auto duration = chrono::duration_cast<chrono::microseconds>(stop1 - start1);
	// #ifndef ONLINE_JUDGE
	// cerr << "Time in ms: " << duration . count() / 1000 << endl;
	// #endif

	
	return 0;
}











