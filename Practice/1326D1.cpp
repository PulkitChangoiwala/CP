
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

int  fun(string & s1,int len){

  vector<int> pi(2*len+1);
  len*=2; len++;
  for(int i=1;i<len;++i){
  	int j=pi[i-1];
  	while(j>0 && s1[i]!=s1[j]) j =pi[j-1];
  	if(s1[i]==s1[j]) ++j;
  	pi[i]=j;
  	}
  

  return(pi[len-1]); //palidrome present as prefix of s1 has pi[len-1] length

}

void solve(){ int t; cin>>t;while(t--)
{
    
  string s;
  cin>>s;
  string t;
  int n =s.length();
  string a="",b="";
  int indx=n;
  fr(i,n){
  	if(s[n-1-i]==s[i]){
  		a+=s[i];
  		b=s[n-i-1]+b;}
  	else {indx=i; break;}
  }
  if(n==1) {cout<<a<<endl; continue;}
  if(indx==n) {cout<<s<<endl; continue;}
  int len = n-2*indx;

  string t1 = s.substr(indx,len);
  string t2=t1; reverse(t2.begin(), t2.end());
  string s1= t1+'#'+t2;
  int x=fun(s1,len);
  string s2 =t2+'#'+t1;
  int y=fun(s2,len);

if(x>y)
	  {
 	 	a+=s.substr(indx,x);
		t=a+b;
	 } 
 else{  string tmp = 
	 	b=s.substr(n-indx-y,y)+b;	
	 	t=a+b;
 }
cout<<t<<endl;
}return;} //while loop and solve ends respectively



signed main() {
	// your code goes here
	solve();
	return 0;
}




