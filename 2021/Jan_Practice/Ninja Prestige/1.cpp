#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n, m,k;
	cin>>n>>m>>k;
    int mx=1,smx=0;
    for(int i=0;i<n;++i){
        int a; cin>>a;
        if(a>mx) {
            smx = mx;
            mx = a;
        }
        else if(a>smx) {
            smx=a;
        }
    }
    int ans = 0;
    //cout<<mx<<" "<<smx;
    int q = m/(k+1), r = m%(k+1);
    ans = q*(k*mx+smx) + r*mx;
    cout<<ans<<"\n";

    
	// Write your code here
}