
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

void solve(){
    int n,p;
    cin >> n >> p;
    v(int) a(n),ans;

    fr(i,0,n) cin>>a[i];
    sort(a.begin(),a.end());
    for(int x=0;;++x){
        v(int) lessThan(n);
        int cnt=0,j=0;
        for(int i=0;i<n;++i){
            while(j<n && a[j]<=x+i) {j++;cnt++;}
            lessThan[i] = cnt;
        }
        // p1(x);
        // debug_arr(lessThan);
        int fx_flag =0;
        for(int i=0;i<n;++i){
            if((lessThan[i] - i)%p==0) fx_flag = 1;
        }
        
        if(fx_flag==0) ans.pb(x);
        
        if(lessThan[0]==n) break;
    }
    
    p1(ans.size());
    debug_arr(ans);

return;} // solve ends 



signed main() {
	// your code goes here
	fast
// 	int t; cin>>t; while(t--)
	{solve();}
	
	return 0;
}


