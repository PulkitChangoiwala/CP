#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long 
#define fr(i,s,e) for(int i=s;i<e;++i)
#define fr1(i,s,e) for(int i=s;i>e;--i)
#define p0(a) cout << a <<" "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
#define INF (ll)1e18 + 100
#define v(d) vector<d>
#define pr pair<int, int>
#define pr1(d1,d2) pair<d1,d2>
#define pb push_back
#define f first
#define s second
#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
void debug_arr(vector<int> &a){
	int len = a.size();
	fr(i,0,len){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}


const int  mod = 1e9 +7;
const int mod1= 998244353;



void solve(){ 
int n,ans=0;
cin >> n;
v(int) a(n);
fr(i,0,n) {cin >> a[i];}

v(v(int)) cnt1(n,v(int)(n+1)), cnt2(n,v(int)(n)); 
//cnt1 -> cnt of element i in 0...j included
//cnt2 -> cnt of pairs in subarray i...j included

cnt1[0][a[0]]++;
fr(i,1,n){
    cnt1[i] = cnt1[i-1];
    cnt1[i][a[i]]++;
}

for(int l=2; l<=n; ++l){
    for(int i=0;i+l-1<n;++i){
        int j  = i+l-1;
        cnt2[i][j] = cnt2[i][j-1] + cnt1[j-1][a[j]] - (i==0?0:cnt1[i-1][a[j]]);
    }
}


for(int i=0;i<n;++i){
    for(int k=i+2; k<n; ++k){
        if(a[i]==a[k]){
            ans += cnt2[i+1][n-1] - cnt2[i+1][k] - cnt2[k][n-1];
        }
    }
}

p1(ans);

return;} // solve ends 



signed main() {
	// your code goes here
	fast
	int t; cin>>t; while(t--)
	{solve();}
	
	return 0;
}

 