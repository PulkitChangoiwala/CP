
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
vector<int> mn,help1; vector<pr> help;
void check(int &ans, vector<int>&pref, int t){
    // for(int i=1; i<=pref.size()-1;++i){
    //     if(pref[i]>=t) break;
    //     ans++;
    // }
    int ind = lower_bound(help1.begin(),help1.end(),t)-help1.begin();
    if(ind==help1.size()) ans += help1.size();
    else ans += mn[ind];
}


void solve(){ 
int n,m,t,q,mx=-1e16;
cin >> n >> m;
v(int) a(n), x(m), pref(n+1);
help.clear(); mn.clear(); help1.clear(); mn.resize(n);
fr(i,0,n) {cin >> a[i]; pref[i+1] = pref[i] + a[i]; mx = max(mx, pref[i+1]); help.pb({pref[i+1],i});}
sort(help.begin(), help.end());
mn[n-1] = help[n-1].s; 
fr1(i,n-2,-1){mn[i]=min(mn[i+1],help[i].s);}
fr(i,0,n) help1.pb(help[i].f);
// debug_arr(pref);
// for(auto el: help) p2(el.f,el.s);
// debug_arr(help1);
// debug_arr(mn);
fr(i,0,m) {
    cin >> x[i]; t= x[i];
    int  ans = 0;
    check(ans,pref,t);
    if(ans==n){
        
        if(pref[n]<=0){ cout<<-1<<" "; continue; }   
        q=0;
        t -= pref[n];
        if(t-mx>0) {q = ceil(1.0*(t-mx)/pref[n]); t -= q*pref[n];}
        ans += q*(n);
        // p1(ans);
        check(ans,pref,t);
    }
    cout<<ans<<" ";
    }

cout<<endl;
    

return;} // solve ends 



signed main() {
    // your code goes here
    fast
    int t; cin>>t; while(t--)
    {solve();}
    
    return 0;
}


