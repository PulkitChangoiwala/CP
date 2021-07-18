
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


/*
Assign a number b[i] to i, s.t. a[i]==b[i] is maximised

i has to gift to b[i]
i wants to gift to a[i]


*/

void solve(){ 
	int n; cin >> n;
	v(int) a(n), b(n), cnt(n+1);
	fr(i,0,n) {cin >> a[i]; cnt[a[i]] = 1;}
	int unique = accumulate(cnt.begin(), cnt.end(),0);
	if(unique==n-1){
		p1(n-1);
		int el = 0, i1=0, i2 =0, el1 = 0;
		b = a;
		for(int i=1; i<=n; ++i) if(cnt[i]==0) el = i;
		// assign(all(cnt),0);
		cnt.assign(n+1,0);
		for(int i=0; i<n; ++i) { cnt[b[i]]++;
			if(cnt[b[i]]==2) el1 = b[i];
		}

		for(int i=0; i<n; ++i) {
			if(a[i]==el1){
				if(i1!=0) i2 = i+1;
				else i1 = i+1; 
			}
		}
		// debug_arr(b);
		// p4(i1,i2,el1, el);
		if(i1 == el ) b[i2-1] = el;
		else b[i1-1] = el; 
	}
	else {
		p1(unique);
		vector<int> elem, indices;
		// debug_arr(cnt);
		for(int i=0; i<n; ++i){
			if(cnt[a[i]]==1) {
				b[i] = a[i]; cnt[a[i]] = -1;
			}
			else {
				indices.pb(i);
			}
		}
		for(int i=1; i<=n;++i){
		  if(cnt[i]==0){
				elem.pb(i);
			} 
		}

		sort(all(indices));
		sort(all(elem));
		int j = 0, rr = elem.size()-1;
		for(auto i : indices){
			b[i] = elem[j]; j++;
		}
		
	
		if(indices[0]+1 == b[indices[0]]){
			swap(b[indices[0]], b[indices[1]]);
		}
		
		for(int k=1; k<indices.size();++k){
			int i = indices[k];
			if(i+1 == b[i]){
				int ttt = b[indices[0]];
				b[indices[0]]  = b[i];
				b[i] = ttt;
			}
		}

	}

	debug_arr(b);

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

