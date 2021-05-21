#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {

	int t; cin >> t;
    /*
        Let just fix remainder  = r
        then a = b*r + r = (b+1)*r
        r+1 <=  b <=y
        & (b+1)*r <= x => b<= x/r - 1
        =>  r+1 <= b <= min(y, x/r-1)
        => possible pairs, min(y, x/r-1) - (r+1) + 1
        
        Limit of r.
        1) r < b => r < y
        2) b*(r+1) = a <=x
            => r*(r+1) <= x <= (Root x)*(Root X + 1)
            => r <= root X
    */	
	while(t--){
	    int x,y; 
	    cin >> x >> y;
	    int ans = 0;
	    int lim = (int)sqrt(x)+5; //Taking Extra Than Limit
        for(int r = 1; r <= lim; ++r) {
            int cnt = min(y, x/r - 1) - (r+1) + 1;
            ans += cnt>0? cnt :  0;
        }
	    cout<<ans<<"\n";
	}
	return 0;
}