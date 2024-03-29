
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






//CSES : https://cses.fi/problemset/task/1735





class ST {
	int n;
	vector<int> t;
	vector<int> lazy;
	vector<int> lazy_;
public:
	ST(int n) {this->n = n; t.resize(4*n); lazy.resize(4*n,0); lazy_.resize(4*n,0);}
	
	void push(int tl, int tr, int v){
		if(lazy_[v]!=0) { //assignment updates
			//first do assignment updates
			t[v] = (tr-tl+1)*lazy_[v];
			if(tl!=tr){
				lazy_[2*v] = lazy_[2*v+1] = lazy_[v];
				lazy[2*v] = lazy[2*v+1] = 0;
			}
			lazy_[v] = 0;
		}

		if(lazy[v]!=0){
			t[v] += (tr-tl+1)*lazy[v];
			if(tl!=tr){
				lazy[2*v] +=  lazy[v]; lazy[2*v+1] += lazy[v];
			}
			lazy[v] = 0;
		} 
	}
	
	void build(int st, int end, int v, vector<int> & arr){
		if(st == end) {t[v]=arr[st];  return;}
		int mid = (st+end)/2;
		build(st, mid, 2*v, arr);
		build(mid+1, end, 2*v+1, arr);
		t[v] = t[2*v] + t[2*v+1];
	}
	void update(int tl, int tr, int v, int l, int r, int val, int type){
		push(tl,tr,v);
		if(l>r) return;
		if(tl == l && tr == r) {
			if(type==1){
				lazy[v]+=val;	
			} 
			else {
				lazy_[v] = val;
				lazy[v] = 0;
			}
			push(tl, tr, v);
			return;}




		int tm = (tl+tr)/2;
		update(tl,tm,2*v,l,min(r,tm),val,type);
		update(tm+1, tr,2*v+1, max(l,tm+1),r,val,type);
		t[v] = t[2*v] + t[2*v+1];		
	}
	
	int query(int tl, int tr, int v, int l, int r){
		
		if(l>r) return 0;
		push(tl,tr,v);
		if(l==tl && tr==r) return t[v];
		int tm = (tl+tr)/2;
		return (query(tl,tm,2*v,l,min(tm,r)) 
			+ query(tm+1, tr, 2*v+1, max(l,tm+1),r));
	}
	void print(){
		debug_arr(t);
	}
};

























void solve(){ 
	int n, q;
	cin >> n >> q;

	vector<int> arr(n);
	fr(i,0,n) cin>>arr[i];
	ST s1(n);
	s1.build(0,n-1,1,arr);
	//s1.print();
	int tmp,a,b,x;
	fr(i,0,q){
		
		cin >> tmp;
		if(tmp==1){
			cin >> a >> b >> x;
			s1.update(0,n-1,1,a-1,b-1,x,1);
		}
		else if(tmp==2){
			cin >> a >> b >> x;
			s1.update(0,n-1,1,a-1,b-1,x,2);
		}
		else {
			cin >> a >> b;
			p1(s1.query(0,n-1,1,a-1,b-1));
		}
	}

return;} // solve ends 



signed main() {
	// your code goes here
	fast
	{solve();}
	
	return 0;
}
