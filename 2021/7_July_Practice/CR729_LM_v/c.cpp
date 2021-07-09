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


int ad(int a, int b) { return (a+b)%mod;}
int mul(int a, int b) { return (1ll*a*b)%mod;}

void solve(){ 
    int n;
    cin >> n;
    //say f(i) = x => i is divisible by LCM(1,2,3...x-1)
    int lcm = 1, ans = 0;
    long double ld = 1.0;
    for(int x=2; lcm<=n;++x){
        int lcm1 = (lcm*x)/(__gcd(lcm,x));
        ans = ad(ans, mul(x, ad(floor(ld*n/lcm), -floor(ld*n/lcm1))));
        lcm = lcm1;

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