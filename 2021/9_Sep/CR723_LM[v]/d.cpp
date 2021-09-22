
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
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

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
int n;
vector<int> t;

void build(){
	for(int i = n-1; i>=1; --i) t[i] = t[i<<1] + t[i<<1 | 1];
}

int query(int l, int r){ //[l,r)
	int res = 0;
	for(l+=n, r+=n; l<r; l >>= 1, r >>=1){
		if(l&1) res += t[l++];
		if(r&1) res += t[--r]; 
	}
	return res;

}

void modify(int ind, int value){
	for(t[ind+=n]+=value; ind >1; ind >>= 1) t[ind >> 1] = t[ind] + t[ind^1];
}


int countInversion(vector<int> & a, int mxVal=100000){
	n = mxVal+1;
	t.clear(); 
	t.resize(2*n,0);

	int cnt = 0, len = a.size();

	for(int i=0; i<len; ++i){
		cnt += query(a[i]+1, n);
		modify(a[i],1);
	}
	return cnt;
}

int countDistance(vector<int> a, vector<int>&b){

	int len = a.size();
	int maxVal = 0;
	unordered_map<int,deque<int>> Map;
	for(int i=0; i<len; ++i){
		Map[b[i]].push_back(i);
	}
	for(int i=0; i<len; ++i){
		int temp = Map[a[i]].front();
		Map[a[i]].pop_front();
		a[i] = temp;
		maxVal = max(maxVal, a[i]);
	}
	return countInversion(a, maxVal);
}

void solve(){ 
	string s;
	cin >> s;
	
	for(auto &ch : s){
		if(ch=='A') ch = 'a';
		else if(ch=='N') ch = 'b';
		else if(ch=='O') ch = 'c';
		else ch = 'd';
	}

	int swaps = 0;
	string ans = "";
	vector<int> a, res;
	vector<int> vt = {0,1,2,3};
	// vector<int> a = {5,2,3,1,4,5};
	// vector<int> b = {2,3,5,4,5,1};
	// swaps = countDistance(a,b);
	unordered_map<char,int> cnt;
	for(auto &ch : s) {
		a.push_back((ch-'a')); 
		cnt[ch]++;
	}
	
	res = a;

	do{
		vector<int> b;
		for(int i=0; i<4; ++i){
			char ch1 = char('a'+vt[i]);
			for(int j=0; j<cnt[ch1];++j){
				b.push_back(vt[i]);
			}
		}
		// debug(b);
		int temp = countDistance(a,b);
		// debug(temp);
		if(swaps<=temp){
			res = b;
			swaps = temp;
		}
	}while(next_permutation(all(vt)));

	debug(res);
	// debug(swaps);
	unordered_map<int,char> ch = {
		{0,'A'},
		{1,'N'},
		{2,'O'},
		{3,'T'}
	};
	for(auto el : res){
		ans += ch[el];
	}
	p1(ans);

return;} // solve ends 



signed main() {
	// your code goes here
	#ifndef ONLINE_JUDGE
		freopen("err", "w", stderr);
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

