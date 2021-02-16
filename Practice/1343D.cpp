
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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


void solve(){ int t; cin>>t;while(t--)
{
    
  int n,k;
  cin>>n>>k;
  vector<int> a(n);
  fr(i,n){
  	cin>>a[i];
  }
  vector<int> cnt(2*k+1);
  vector<int> diff(2*k+1);
  // we will traverse for all value of x from 2 to 2*k

  /*
	for fix x: a pair can have 1) no replacement
	2) 1 replacement
	3) 2 replacement

  */
  
  fr(i,n/2){ //O(n):: 1) No replacement
  	cnt[a[i]+a[n-1-i]]++;
  }
  
  /*
	we can obtain one replacement iff x lies in l[i] & r[i]
	where l[i]&r[i] is min and max possible values for a[i]+a[n-1-i]

	we maintain a pref[j] which contains number of times sum j occurs
	and to do constant time updation we construct a differnce array diff[]
  */
  vector<int> pref(2*k+1);
  fr(i,n/2){  //O(n)
  	int l= min(a[i],a[n-1-i]) +1;
  	int r= max(a[i],a[n-1-i]) +k;
  	diff[l]++;
  	diff[r+1]--;
  	
  }

  int ans = n;
  for(int sum=2;sum<=2*k;++sum){ //O(k)
  	pref[sum] =  diff[sum] + pref[sum-1];
  	int sumans = pref[sum]- cnt[sum] + (n/2 - pref[sum])*2; // (n/2 - pref[sum])*2  = number of 2's replacement
   	ans=min(ans, sumans);
  }
  cout<<ans<<endl; //total O(n+k)
  
}return;} //while loop and solve ends respectively



signed main() {
	// your code goes here
	solve();
	return 0;
}




