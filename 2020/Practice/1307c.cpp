



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long 
#define fr(i,n) for(int i=0;i<n;++i)
#define fr1(i,n) for(int i=1;i<=n;++i)
#define p0(a) cout << a <<" "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
#define INF (ll)1e18 + 100

const int  mod = 1e9 +7;
const int mod1= 998244353;


void solve(){ 
    
  string s;
  cin>>s;
  int n=s.length();
  //subseq of length 1 or 2
  vector<int> cnt(26);int mx1=0;  int mx2=0;
  vector<vector<int>> dp(26,vector<int>(26));
  
  cnt[s[0]-'a']=1;
  for(int i=1;i<=n-1;++i){
  	
  	vector<vector<int>> new_dp(26,vector<int>(26));
  	new_dp=dp;
  	fr(j,26){
  			new_dp[j][s[i]-'a'] += cnt[j];
  	}
  	cnt[s[i]-'a']++;
  	dp=new_dp;

 }


 fr(i,26){
 	mx1=max(mx1,cnt[i]);
 	fr(j,26){
 		mx2=max(mx2,dp[i][j]);
 	}
 }
 cout<<max(mx2,mx1)<<endl;
  return;} // solve ends 



signed main() {
	// your code goes here
	//int t; cin>>t; while(t--)
	{solve();}
	
	return 0;
}






