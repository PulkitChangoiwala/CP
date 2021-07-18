
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
const int mod = 1e9+7;
vector<int> dp(2000001);

void process(){
    dp[1] = dp[2] = 0;
    dp[3] = 4;
    dp[4] = 4;
    
    //each RDB level i consists of 
        //One root attached with two level i-2 RDB & one level i-1 RDB
        
    //dp[i] = dp[i-1] + 2*dp[i-2];
    //if children of root are green paint root with yellow, dp[i] += 4
    
    //i=
    //1 root green
    //2 root green
    //3-> children are green, paint root to yellow += 4
    //4-> one child(level 3 RDB) yellow => do not paint root => root green
    //5-> two children(level 3 RDB) yellow => do not paint root => root green
    //6-> all children green, paint root yellow, +=4
    
    // ==> all level where i%3==0 add +4 to answer
    for(int i=5; i<2000001; ++i){
        dp[i] = (dp[i-1] + (2*dp[i-2])%mod)%mod;
        dp[i] = (dp[i] + (i%3==0)*4)%mod;
    }
}
void solve(){
    int n;
    cin >> n;
    p1(dp[n]);
return;} // solve ends 



signed main() {
	// your code goes here
	fast
	process();
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
