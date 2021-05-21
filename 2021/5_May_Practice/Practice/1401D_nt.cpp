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
#define s_ second
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
 
 
// #include<bits/stdc++.h>
// using namespace std;
 
 
 
int n;
vector<vector<int>> adj;
vector<int> cnt,sze;

void dfs(int s, int p, vector<pair<int,int>> &edges){
    sze[s] = 1ll;
    if(p) edges.push_back({s,p});
    for(auto v : adj[s]){
        if(v!=p){
            dfs(v,s,edges);
            sze[s]+=sze[v];
        }
    }
}


void solve(){ 
	cin >> n ;	
	int a,b;
	
	adj.clear();
	adj.resize(n+1);
	vector<pair<int,int>> edges;
	
	fr(i,0,n-1) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);

	}
	sze.clear();
	sze.resize(n+1,0ll);
	cnt.clear();
	cnt.resize(n-1);
	dfs(1,0,edges);
	vector<pair<int,int>> sort_Ed;
	for(int i=0; i<n-1; ++i){
	   // p2(edges[i].s, edges[i].f)
	    cnt[i] = sze[edges[i].first] * (n-sze[edges[i].first]);
	    sort_Ed.pb({cnt[i],i});
	}
//	debug_arr(cnt);
    int m;
    cin >> m;
    vector<int> prime(m);
    for(int i=0;i<m;++i){
        cin >> prime[i];
    }
//    sort(sort_Ed.begin(), sort_Ed.end());
    sort(prime.begin(), prime.end(), greater<int>());
    sort(cnt.begin(), cnt.end(), greater<int>());
    //debug_arr(cnt);
    //debug_arr(prime);
    int ans = 0;
    
    if(m<=n-1){
        for(int i=0; i<n-1; ++i){
            if(i<m) ans = ((((cnt[i])*prime[i])%mod)+ans)%mod; 
            else ans = (ans+cnt[i])%mod;
        }
    }
    else {
        int tmp = cnt[0],i;
        for(i=0; i<=(m-n+1); ++i){
            tmp = (tmp*prime[i])%mod;
        }
        ans = (ans+tmp)%mod;
        int k = 1;
        for(;i<m;++i){
            ans = (((cnt[k]*prime[i])%mod)+ans)%mod;
            k++;
        }
    }


    cout<<ans<<endl;
    
    
 
return;} // solve ends 
 
 
 
signed main() {
	// your code goes here
	fast
	int t; cin >> t; while(t--)
	{solve();}
	
	return 0;
}
 