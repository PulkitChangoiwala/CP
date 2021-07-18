
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

int ad(int a, int b){
    return (a+b)%mod;
}
int mul(int a, int b){
    return (1ll*a*b)%mod;
}
void solve(){
    v(int) a(6); fr(i,0,6) cin >> a[i];
    int n; cin >> n;
    v(int) b(n); fr(i,0,n) cin >> b[i];
    
    v(pr) vv;
    fr(i,0,6)
        fr(j,0,n)
            vv.pb({b[j]-a[i],j});
            
    sort(all(vv));
    
    int ans = 1e18;
    
    
    int j=0, unique=0;
    v(int) cnt(n);
    for(int i=0; i<vv.size(); ++i){
        if(i>j) j = i;
        while(j<vv.size() && unique<n){ cnt[vv[j].s]++; if(cnt[vv[j].s]==1) unique++; j++;}
        // cout<<unique<<endl;
        if(unique==n){
            ans = min(ans, vv[j-1].first - vv[i].first);
            cnt[vv[i].s]--;
            if(cnt[vv[i].s]==0) unique--;
        }
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
