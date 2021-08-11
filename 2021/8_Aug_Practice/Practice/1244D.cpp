
#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
void _print(int t) {cerr << t;}
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

/*

int ad(int a, int b){
	a = (a+mod)%mod;
	b = (b+mod)%mod;
    return (a+b)%mod;
}
int mul(int a, int b){
    return (1ll*a*b)%mod;
}

struct Combo {
    vector<long long> facs;
    vector<long long> invfacs;
    int N;
 
    Combo(int N) {
        this->N=N;
        facs.assign(N+1,0);
        invfacs.assign(N+1,0);
        facs[0] = 1;
        for (int i = 1; i <= N; i++) {
            facs[i] = (facs[i-1]*i)%mod;
        }
        invfacs[N] = power(facs[N],mod-2);
        for (int i = N-1; i >= 0; i--) {
            invfacs[i] = (invfacs[i+1]*(i+1))%mod;
        }
    }
 
    ll choose(int n, int k) {
        if (n<0||k<0||n<k) return 0LL;
        ll denInv = (invfacs[k]*invfacs[n-k])%mod;
        ll ans = (facs[n]*denInv)%mod;
        return ans;
    }
 
    ll power(ll x, ll y) {
        ll ans = 1;
        x %= mod;
        while (y > 0) {
            if (y%2==1) ans = (ans*x)%mod;
            y /= 2;
            x = (x*x)%mod;
        }
        return ans;
    }
};

*/


const int N=1e5+3;
struct edge{int v,nxt;}g[N+N];
int n,a[N][3],head[N],k,root,d[N],t[3],c[N];long long s,ans=1e18;
inline void Insert(int u,int v){g[++k]=(edge){v,head[u]};head[u]=k;}
inline void Dfs1(int u,int k,int fa){
	int v;
	s+=a[u][t[k]];c[u]=t[k];
	for(int i=head[u];i;i=g[i].nxt)if((v=g[i].v)!=fa)
	  Dfs1(v,(k+1)%3,u);
}
void solve(){ 
	int u,v;
	scanf("%d",&n);

	for(int j=0;j<3;j++)
	  for(u=1;u<=n;u++)scanf("%d",&a[u][j]);

	for(int i=1;i<n;i++){
	  scanf("%d%d",&u,&v),Insert(u,v),Insert(v,u),d[u]++,d[v]++;
	  if(d[u]>2||d[v]>2) {p1("-1"); return;}
	}

	for(u=1;u<=n;u++)if(d[u]==1)root=u;

	for(int i=0;i<3;i++)t[i]=i;
	do{
	s=0;
	Dfs1(root,0,0);
	ans=std::min(ans,s);
	}while(std::next_permutation(t,t+3));
	printf("%lld\n",ans);
	for(int i=0;i<3;i++)t[i]=i;
	do{
	s=0;
	Dfs1(root,0,0);
	if(ans==s){
	  for(u=1;u<=n;u++)printf("%d ",c[u]+1);
	  return ;
	}
	}while(std::next_permutation(t,t+3));	

return;} // solve ends 



signed main() {
	// your code goes here
	#ifndef ONLINE_JUDGE
		freopen("err", "w", stderr);
	#endif
	fast


	auto start1 = chrono::high_resolution_clock::now();
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

