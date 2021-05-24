#include <bits/stdc++.h>
using namespace std;
//#define int long long
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

int main() {
	// your code goes here
	#define int long long
	int u,v;
	cin >> u >> v;
	if(u > v || u%2 != v%2) {p1(-1); return 0;}
	if(u==v) {if(u==0) {p1(0);return 0;} p1(1); p1(u); return 0;}
	
	
    int and_ = v - u;
    //as  a+b = a^b + 2(a&b)
    and_ /= 2;
    int ans = 0;
    int t1,t2;
    for(int i=log2(v)+1; i>=0; --i){
        t1 = (and_ & (1ll<<i));
        t2 = (u & (1ll<<i));
        if( t1 && t2 ) {p1(3); p3(u,(v-u)/2,(v-u)/2); return 0;}
        if(t1 && !t2) { ans += t1;}
        if(!t1 && t2) { ans += t2;}
    }
    p1(2);
    p2(ans, (u^ans));
    
	
	return 0;
}