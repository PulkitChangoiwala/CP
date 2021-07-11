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
	int n;
    cin >> n; v(pr) ba(n);
    fr(i,0,n) {cin >> ba[i].s >> ba[i].f; }
    sort(ba.begin(), ba.end());
    int m = 0, cp = 0, j=n-1,i=0;
    for(int i=0; i<=j; ){
        if(ba[i].f<=cp){ m+= ba[i].s; cp+= ba[i].s; ++i;}
        else {
            while(i<=j && cp<ba[i].f){
                int tmp = min(ba[j].s, ba[i].f-cp); 
                cp += tmp;
                ba[j].s -=  tmp;
                m += 2*tmp;
                if(ba[j].s==0) j--;
            }
        }
    }
    p1(m);

return;} // solve ends 



signed main() {
	// your code goes here
	fast
	
	{solve();}
	
	return 0;
}











