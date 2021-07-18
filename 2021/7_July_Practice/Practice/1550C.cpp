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
const int mod = 998244353;

int ad(int a, int b){
    return (a+b)%mod;
}
int mul(int a, int b){
    return (1ll*a*b)%mod;
}

int LIS(v(int) & a){
    vector<int> dp(a.size(),1);
    int mx = 1;
    dp[0] = 1;
    for(int i=1; i<=a.size()-1; ++i){
        for(int j=0; j<i; ++j){
            if(a[j]<=a[i]) dp[i] = max(dp[i], dp[j]+1);
        }
        mx = max(mx,dp[i]);
    }
    // debug_arr(a);
    // debug_arr(dp);
    return mx;
}
int check(v(int) &a, int k){
    //size k sub array
    int res = 0;
    for(int i=0; i<=a.size()-k; ++i){
        //array from i to i+k-1
        //check if increasing or decreasing seq of size 3 exists or not
        
        vector<int> arr(a.begin()+i, a.begin()+i+k);
        // debug_arr(arr);
        if(LIS(arr) < 3){
            reverse(all(arr));
            if(LIS(arr)<3) res++; //check dec seq 
        }
    }
    return res;
}

void solve(){

// Bad triple iff ai >= aj >= ak or ai <= aj <= ak
// Property used: every n^2 + 1 contains at least one n+1 size monotonic subsequence
// A sub array is bad if it contains bad triple
// All subarrays of size >= 5 is bad
// We need to check only subarrays of size 3, 4 
    
    int n; cin >> n;
    v(int) a(n);
    fr(i,0,n) cin >> a[i];
    
    int ans = n + n-1; //good subarrays of size 1,2 respectively
    
    //check return good subarrays
    ans += check(a,3); 
    ans += check(a,4);
    // p1(check(a,4));
    p1(ans);
    // v(int)anst = {2,2,2,2,2,2,2,2};
    // p1(LIS(anst));

return;} // solve ends 



signed main() {
	// your code goes here
	fast
	int t; cin>>t; while(t--)
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