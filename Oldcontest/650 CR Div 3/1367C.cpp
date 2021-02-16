



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


void solve(){ 
    
  int n,k;cin>>n>>k;
  string s;
  vector<int> one;
  cin>>s;
  one.push_back(-k-1);
  fr(i,n) {
  	if(s[i]=='1'){
  		one.push_back(i);
  	}}
  	one.push_back(n+k);

  	/*
	
  	*/
  	int prev = one[0];
  	int next = one[1];
  	one.erase(one.begin());
  	one.erase(one.begin());
  	int cnt=0;
  	fr(i,n){
  		while(i>next || prev>i){
  			prev=next;
  			next= *(one.begin());
  			one.erase(one.begin());
  		}
  		if(s[i]=='0'){
  			if(i>prev+k && i+k<next){
  				cnt++;
  				prev=i;
  			}
  		}

  	}
  	cout<<cnt<<endl;
  return;} // solve ends 



signed main() {
	// your code goes here
	int t; cin>>t; while(t--)
	{solve();}
	
	return 0;
}






