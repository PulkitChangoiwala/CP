#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {

	int t; cin >> t;
    /*
       
    */	
	while(t--){
	   int n;
	   cin >> n;
	   vector<vector<int>> p(n, vector<int>(4,0));
	   for(int i=0;i<n;++i){
	       for(int j=0;j<4;++j){
	           cin >> p[i][j];
	       }
	   }         
	    map<pair<int,int>,int> mp; 
	    int d, k=0;
	    int gcd=0,prd=1;
	    int ans = 0,a,b,cnt;
	    for(auto &v : p){
	       a = v[3]-v[1]; b = v[2]-v[0];
	       d = __gcd(abs(a),abs(b));
	       if(a==0 && b == 0) {
	           mp[{a,b}]++;
	       }
	       else {
	           a/=d; b/= d;
	           mp[{a,b}]++;
	       }
	       k++;
	       
	    }
//	    cout<<__gcd(9,0)<<endl;

	 
/*	    for(auto el : mp){
	       a = el.first.first;
	       b = el.first.second;
	       cnt = el.second;
	    //   cout << a << " " << b << " " << cnt <<endl;
	    }
*/	    pair<int,int> pr,pr1;
	    for(auto el : mp){
	       a = el.first.first;
	       b = el.first.second;
	       cnt = el.second;
	       if(a==0 && b == 0) continue;
	       pr1.first = -a; pr1.second = -b;
	       if(mp.find(pr1) != mp.end())
	       { 
	         ans += cnt*mp[pr1];
	         mp[pr1] = 0;
	       }
	       mp[{a,b}] = 0;
	    }
	    cout << ans <<"\n";//<< endl << endl;
	   
	    
	    
	}
	return 0;
}