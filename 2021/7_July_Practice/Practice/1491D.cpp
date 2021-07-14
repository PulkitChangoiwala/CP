#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long 
#define fr(i,s,e) for(int i=s;i<e;++i)
#define fr1(i,s,e) for(int i=s;i>e;--i)
#define p0(a) cout << a <<" "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
#define INF (ll)1e18 + 100
#define v(d) vector<d>
#define pr pair<int, int>
#define pr1(d1,d2) pair<d1,d2>
#define pb push_back
#define f first
#define s second
#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
void debug_arr(vector<int> &a){
	int len = a.size();
	fr(i,0,len){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}


const int  mod = 1e9 +7;
const int mod1= 998244353;




void solve(){ 
// #bits an > #bits a1 (or) an < a1 (or) condition 1  => NO
// Else => YES

// __builtin_popcount = int
// __builtin_popcountl = long int
// __builtin_popcountll = long long
int u,v;
cin >> u >> v;
int tv = __builtin_popcount(v), tu = __builtin_popcount(u);
if(v<u) p1("NO");
else {
    for(int i=30; i>=0; --i){
        int fv = v&(1<<i), fu = u&(1<<i);
        if(fv && tv>tu) {p1("NO"); return;}
        if(fv) tv--;
        if(fu) tu--;
    }
    p1("YES");
}

    

return;} // solve ends 



signed main() {
	// your code goes here
	fast
	int t; cin>>t; while(t--)
	{solve();}
	
	return 0;
}

 