#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> ans;
void solve(){
    int c = 1e7+10; 
    
    vector<int> notprime(c+1,0), d(c+1);
    ans.clear();
    ans.resize(c+1,-1);
   
    
    for(int i=2; i*i<=c; ++i){
        if(notprime[i]) continue;
        for(int j = i*i; j<=c; j+=i ) {
            notprime[j] = i;
        }
    }

    //notprime[i] stores one prime factor of i, if it is not prime

    d[1] = 1;
    if(ans[d[1]] == -1) ans[d[1]] = 1;
    for(int i=2; i<=c; ++i){
        if(!notprime[i]) {d[i] = i+1;} //if i is prime
        else {
            //let p is one prime factor of i
            int p = notprime[i];
            d[i] = 1;
            int tmp = i;
            while(tmp%p == 0){
                tmp /= p;
                d[i] = d[i]*p+1; 
            }
            // now  d[i] = 1 + p^2 + p^2 .... p^(ep)
            d[i] *= d[tmp];
        }
        
        if(d[i] <= c && ans[d[i]] == -1) ans[d[i]] = i;
    }
    
    
    
}
signed main() {
	// your code goes here
	solve(); int c;
	int t; cin >> t;
	while(t--) {cin >> c; cout<<ans[c]<<"\n";}
	return 0;
}
