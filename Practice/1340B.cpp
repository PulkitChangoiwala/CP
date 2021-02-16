
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
vector<vector<int>> changes;
vector<string> digits ={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int dp[2005][2005][11];  
int n;
int calc(string s, int d){
	int c=0;
	fr(i,7){
		if(s[i]=='0' && digits[d][i] == '1') c++;
		else if(s[i]=='1' && digits[d][i] == '0') return -1;

	}
	return c;
}

int calculate(int indx, int k, int d){
	if(indx==n && k==0) { dp[indx][k][d]=1; return dp[indx][k][d]; } 
	else if((indx == n && k>0)|| k<0){dp[indx][k][d]= 0; return dp[indx][k][d];}	
	else if(dp[indx][k][d]!=-1) {return dp[indx][k][d];}
	dp[indx][k][d]=0;
    fr(dgt,10){
    		
    	if(changes[indx][dgt] !=-1){
    		dp[indx][k][d] =max(dp[indx][k][d],calculate(indx+1, k-changes[indx][dgt], dgt));
    	}
    } 
    return dp[indx][k][d];  
}
string ans="";
void findans(int indx, int k, int d){
 	if(indx==n) return ;
 	else{
 		for(int i=9;i>=0;--i){
 			if(dp[indx+1][k-changes[indx][i]][i]==1) {ans+= to_string(i);findans(indx+1,k-changes[indx][i],i); return;}

 		}
 	
 	}
 	

}
void solve(){ //int t; cin>>t;while(t--)
{
    
  int k;cin>>n>>k;
  vector<string> in(n);
  fr(i,n)
  {cin>>in[i];}
  //find for all input string what number of changes require for obtaining 
  // digits 0 to 9
  changes.resize(n,vector<int>(10)); // space n*d
  fr(i,n){  // time O(70*n)
  	fr(d,10){
  		changes[i][d]=calc(in[i],d);	
  	}
  }

  /****************
  dp transition from
  <indx, k, i> ---> to it's children 
  d from 0 to 9: <indx+1, k-changes[indx+1][d], d>
	
	dp[i][k][d] = true if any of it's children is positive

	generating answer: start <0, k, 0>  go to it's child <1,k-changes[0][dgt],dgt> where dgt 
	largest d (in [0,9]) such that dp[1][k-changes[0][dgt]][dgt]== true
  ************/
	memset(dp, -1, sizeof(dp));
	calculate(0,k,0); //calculate dp. O(n*k*10)
	findans(0,k,0);
	if(ans.length())cout<<ans<<endl;  
  	else cout<<-1<<endl;
}return;} //while loop and solve ends respectively



signed main() {
	// your code goes here
	solve();
	return 0;
}




