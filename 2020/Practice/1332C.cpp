
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
    int n,k;cin>>n>>k;
    string s; cin>>s;
  	int ansm=0;
  	// {s[i]...s[k+i-1]} is palindrome far all i in final answer
  	// s[0] = s[k-1]=s[k]=s[2*k-1]  and so on
  	//s[1] = s[k-2] = s[k+1]= s[2*k-2] and so on
  	if(k==1){
  		vector<int> count(26);
  		int j=0,mx=-1; while(j<n){mx = max(mx,++count[s[j]-'a']);++j;} 
  		ansm+=n-mx;

  	}
  	else {
	  	for(int i=0;i<k/2;++i){
	  		
	  		int mx=-1; int cnt=0; int j=0;
	  		vector<int> count(26);
	  		while((j*k)<n){
	  			cnt+=2;
	  			mx= max(mx,++count[s[j*k+i]-'a']);
	  			mx= max(mx, ++count[s[((j+1)*k-i-1)]-'a']); 
	  			j++;
	  		}

	  		ansm+= cnt-mx;
	  		count.clear();
	  	}
	  if(k%2){
	  		int mx=-1; int cnt=0;
		  	vector<int> count(26);
		  	for(int i= k/2;i<n;i+=k){cnt++;
		  		mx= max(mx,++count[s[i]-'a']);}
		  		
		  	ansm+=cnt-mx;	
		  		}}
  	cout<<ansm<<endl;
}return;} //while loop and solve ends respectively



signed main() {
	// your code goes here
	solve();
	return 0;
}




