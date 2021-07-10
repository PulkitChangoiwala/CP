
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
	int n,k;
	cin >> n >> k;
	v(int) a(k),t(k);
	v(int) f(n+1,-1);
	set<pr> st;

	fr(i,0,k) {cin>>a[i];}
	fr(i,0,k) {cin>>t[i]; f[a[i]-1]=t[i]; st.insert({t[i]+a[i]-1,a[i]-1});}

	vector<int> ans(n,1e14);
	int l=-1, lmn=1e14, r=n,rmn=1e14;
	if(f[0]!=-1) {l=0;lmn=f[0]; ans[0]=lmn; st.erase({f[0]+0,0});}
	
	// fr(i,1,n){ if(f[i]!=-1 && f[i]+i<rmn) {rmn=f[i]+i; ans[0] = min(ans[0],rmn);r=i;}}
	if(st.size()){
		auto ppp = *(st.begin());
		rmn = ppp.f; r = ppp.s;
		ans[0] = min(ans[0],rmn);
	}

	fr(i,1,n){
		// ans[i] = min(lmn,rmn)+1;
		lmn++;
		if(f[i]!=-1 && f[i]<=lmn) {l=i; lmn=f[i]; ans[i] = min(ans[i],lmn); st.erase({f[i]+i,i});}
		else { ans[i] = min(ans[i],lmn); }

		if(f[i]!=-1) {if(st.find({f[i]+i,i})!=st.end()) st.erase({f[i]+i,i});}
		
		if(r==i) {
			//update r && rmn
			// if(st.find({f[i]+i,i})!=st.end())st.erase({f[i]+i,i});

			while(st.size()){
				auto ppp = *(st.begin());
				if(ppp.s<=i) st.erase(st.begin());
				else break; 
			}
			if(st.size()){
				auto ppp = *(st.begin());				
				rmn = ppp.f-i; r = ppp.s;
				ans[i] = min(ans[i],rmn);
			}
			else {rmn=1e14; r=n;}
		}
		else if(r<n){
			rmn--;		
			ans[i] = min(ans[i],rmn);
		}
		// p4(l,lmn,r,rmn);


	}
	debug_arr(ans);

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

