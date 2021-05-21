#include<bits/stdc++.h>
using namespace std;
#define int long long

//Lazy Propagation, Range Updates, Range Query
//Update: Add number to a range. Query: Find max in range.


class Seg_Tree {
int n;
int INF = 1e18;
vector<int> t;
vector<int> lazy;
public:
	Seg_Tree(int n)
	{	
		this->n = n;
		t.resize(4*n);
		lazy.resize(4*n);
	}

	void push(int v){
		t[2*v] += lazy[v];
		lazy[2*v] += lazy[v];
		t[2*v+1] += lazy[v];
		lazy[2*v+1] += lazy[v]; 
		lazy[v] = 0;
	}

	void build(int st, int end, int tnode, vector<int> &arr){
		if(st == end){
			t[tnode] = arr[st];
			lazy[tnode] = 0;
			return;
		}
		int mid = (st+end)/2;
		build(st,mid, 2*tnode, arr);
		build(mid+1, end, 2*tnode+1, arr);
		t[tnode] = max(t[2*tnode], t[2*tnode+1]);
		lazy[tnode] = 0;
	}
	void update(int tl, int tr, int tnode, int l, int r, int addend){ //interval [l,r]
		if(l>r) return; //Interval is undefined
		if(l==tl && tr == r) {
			t[tnode] += addend;
			lazy[tnode] += addend;
		}
		else {
			push(tnode);
			int tm = (tl + tr)/2;
			update(tl, tm, tnode*2, l,min(r,tm),addend);
			update(tm+1, tr, tnode*2+1, max(l,tm+1),r,addend);
			t[tnode] = max(t[2*tnode], t[2*tnode+1]);				
		}	
	}
	int query(int tl, int tr, int tnode, int l, int r){ //[l,r] is range on which query needs to be done
		//[tl,tr] is range represented by the node
		if(l > r) return -INF; //Max Queries
		if(l<=tl && tr<=r) return t[tnode];
		int tm = (tl+tr)/2;
		push(tnode);
		return max( query(tl,tm,2*tnode,l,min(tm,r)), 
					query(tm+1,tr,2*tnode+1, max(l,tm+1),r));
	}

};

signed main(){
	int n,q;
	cin >> n >> q;
	Seg_Tree st(n);
	vector<int> arr(n),ps(n);
	for(int i=0; i<n; ++i) cin >> arr[i];
	ps[0] = arr[0];
	for(int i=1; i<n; ++i) ps[i] = ps[i-1] + arr[i];


	st.build(0,n-1,1,ps);	
	int type,a,b;
	for(int i=0; i<q; ++i) {
		cin >> type >> a >> b;
		if(type == 1){
			//prefix ending at [a-1 to n-1] needs to be updates
			st.update(0,n-1,1,a-1,n-1,b-arr[a-1]);
			arr[a-1] = b;
		}
		else {
			int temp = a==1? 0 : st.query(0,n-1,1,a-2,a-2);
			cout << max(0ll,st.query(0,n-1,1,a-1,b-1)-temp)<<endl;
		}
	}

return 0;
}