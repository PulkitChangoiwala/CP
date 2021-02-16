
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
bool local_maxima(int a, int  b, int c){
	return (a<=b && b>c);
}

bool local_minima(int a, int  b, int c){
	return (a>b && b<=c);
}

void solve(){ int t; cin>>t;while(t--)
{
    
  int n; cin>>n;vector<int> a(n);
  fr(i,n) cin>>a[i];
  
  /*
	logic find max drop in height from it's peak
  */
  int power=-1,tmp;
  fr(i,n-1){

  	if(a[i]>a[i+1]){
  		int diff = a[i]-a[i+1];
  		power=max(power,(int)(log2(diff)));
  		a[i+1]=a[i];
  	}
  }
  cout<<(power+1)<<endl;
  
}return;} //while loop and solve ends respectively



signed main() {
	// your code goes here
	solve();
	return 0;
}




