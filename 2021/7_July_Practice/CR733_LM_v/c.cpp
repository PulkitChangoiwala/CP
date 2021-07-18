
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
#define all(vv)  vv.begin(), vv.end()
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
	

	int n; cin >> n;
	v(int) a(n), b(n);
	fr(i,0,n) cin >> a[i];
	fr(i,0,n) cin >> b[i];

	/*
		//find current result
		//dont increase ilya score
		n + x  - [n+x]/4

		n to lowest multiple of n, n

		n - n/4
		
		a1 a2 ... an 100 100 100 100 ... 100
		   bk ... bn   0   0   0   0     
		Let say current diff is x
		- we can add upto 300
		- while fourth number is 100-lowest now

		- iterate over suffix, add 300
	*/

	sort(all(a)); 
	sort(all(b));
	int ca = 0, cb = 0;
	for(int i = n-(n - n/4) ; i<=(n-1); ++i){
		ca += a[i]; cb += b[i];
	}
	// p2(ca,cb);

	int cnt = 0, tt = n-(n - n/4);
	int tmpi = tt-1;
	for(int i=n-(n - n/4); i<=n-1; ++i){
		if(ca>=cb) {p1(cnt); return;}
		int rem = 3 - n%4;
		n += rem;	
		for(int j=1; j<=rem;++j){
			cnt++;
			ca += 100;
			cb += (tmpi>=0 && tmpi < n ?b[tmpi--]:0);
			if(ca >= cb) {p1(cnt); return;}
		}
				
		n++;
		ca -= a[i];
		ca += 100;
		cb -= (tmpi>=0 && tmpi < n ?b[tmpi]:0);
		tmpi++;
		cnt++;
		if(ca>=cb) {p1(cnt); return;} 

	}


return;} // solve ends 



signed main() {
	// your code goes here
	fast
	int t; cin>>t; while(t--)
	{solve();}
	
	return 0;
}










/*

Code belongs to:

 ▄████▄   ██░ ██  ▄▄▄       ███▄    █   ▄████  ▒█████   ██▓
▒██▀ ▀█  ▓██░ ██▒▒████▄     ██ ▀█   █  ██▒ ▀█▒▒██▒  ██▒▓██▒
▒▓█    ▄ ▒██▀▀██░▒██  ▀█▄  ▓██  ▀█ ██▒▒██░▄▄▄░▒██░  ██▒▒██▒
▒▓▓▄ ▄██▒░▓█ ░██ ░██▄▄▄▄██ ▓██▒  ▐▌██▒░▓█  ██▓▒██   ██░░██░
▒ ▓███▀ ░░▓█▒░██▓ ▓█   ▓██▒▒██░   ▓██░░▒▓███▀▒░ ████▓▒░░██░
░ ░▒ ▒  ░ ▒ ░░▒░▒ ▒▒   ▓▒█░░ ▒░   ▒ ▒  ░▒   ▒ ░ ▒░▒░▒░ ░▓  
  ░  ▒    ▒ ░▒░ ░  ▒   ▒▒ ░░ ░░   ░ ▒░  ░   ░   ░ ▒ ▒░  ▒ ░
░         ░  ░░ ░  ░   ▒      ░   ░ ░ ░ ░   ░ ░ ░ ░ ▒   ▒ ░
░ ░       ░  ░  ░      ░  ░         ░       ░     ░ ░   ░  
░                                                          



 */

