
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

int p(int ind,  int k){
    if(ind <=k ) return ind;
    else return k - (ind-k);
}
const int  mod = 1e9 +7;
const int mod1= 998244353;
void solve(){ 
int n,k,l,f=1; cin >> n >> k >> l;
v(int) d(n+1);
fr(i,1,n+1) cin >> d[i];
// fr(i,0,k+1) p[i] = i;
// int j = k-1;
// fr(i,k+1,2*k) p[i] = j--;
int t,t1,pos = 2*k-1;
fr(i,0,n+1){
    if(i && d[i]+p(pos%(2*k), k)>l) {f=0; break;}
    if(i==n) break;
    t = -d[i+1] + l;
    // cout<<t<<endl;
    t1 = max(k, 2*k-t);
    // cout<<t1<<endl;
    if(i==0 || k+d[i]<=l || (pos>=k && t1-pos>0)) pos = t1%(2*k);
    else pos = (pos+1)%(2*k);
    // cout<<pos<<endl;

}

if(f) p1("Yes");
else p1("No");

return;} // solve ends 



signed main() {
	// your code goes here
	fast
	int t; cin>>t; while(t--)
	{solve();}
	
	return 0;
}


