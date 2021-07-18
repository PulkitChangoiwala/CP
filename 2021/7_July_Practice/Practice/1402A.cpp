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
#define ppb pop_back()
#define f first
#define s second
#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
#define all(v) v.begin(), v.end()
void debug_arr(vector<int> &a){
	int len = a.size();
	fr(i,0,len){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
const int mod = 1e9+7;

int inv2 = 500000004;
int ad(int a, int b){
    return (a+b)%mod;
}
int mul(int a, int b){
    return (1ll*a*b)%mod;
}
void solve(){
    int n; cin >> n;
    vector<int> h(n+1), w(n+1);
    fr(i,0,n) cin >> h[i+1];
    fr(i,0,n) cin >> w[i+1];
    h.pb(0); w.pb(0);
    
    int ans = 0;
    v(int) dp(n+1);
    v(int) st1, st2;
    for(int i=1; i<h.size(); ++i){
        
        // debug_arr(st1);
        // debug_arr(st2);
        
        int width = 0, height = st1.size()?0:st1.back();
        while(st1.size() && st1.back()>h[i]){ 
            int h1 = st1.back(); st1.ppb; int w1 = st2.back(); st2.ppb;
            int tt3 = mul(width, mul(ad(width,1),inv2));
            width = ad(width, w1);
            int tt1 = mul(h1, mul(ad(h1,1),inv2)); //# of fancy rectangles in h1 height, width 1
            int tt2 = mul(width, mul(ad(width,1),inv2));
            // p3(tt1,tt2,tt3);
            ans = ad(ans, ad(mul(tt1,tt2), ad(mod,-mul(tt1,tt3))));
            // p1(ans);
        }
        int h1 = h[i];
        int tt3 = mul(width, mul(ad(width,1),inv2));
        int tt1 = mul(h1, mul(ad(h1,1),inv2)); //# of fancy rectangles in h1 height, width 1
        ans = ad(ans, ad(mod,-mul(tt1,tt3)));

        width = ad(width, w[i]);
        if(st1.size() && st1.back()==h[i]) { 
            int tmp = st2.back(); st2.ppb; st2.pb(ad(tmp,width));
        }
        else {st1.pb(h[i]); st2.pb(width);}
        // debug_arr(st1);
        // debug_arr(st2);
    }
    p1(ans);
return;} // solve ends 



signed main() {
	// your code goes here
	fast
// 	int t; cin>>t; while(t--)
	{solve();}
	
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