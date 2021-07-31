

/***** Range incremental update, range minimum query ******/ 
/********
 Syntax:
 	n => number of elements in array
 	t => segment tree (with size 4*n)
 	lazy => lazy tree (with size 4*n)

 Terminology of function parameters
 	arr -> array for SGT to be built
 	st  -> start index of the interval of arr for which SGT to be build
 	end -> end index ------------- ---------------- 
	tl  -> start index of tree interval
	tr  -> end index of tree interval
 	root -> node representing the interval [tl, tr] in SGT

 ********/

class ST {
	
	int n;
	vector<int> t;
	vector<int> lazy;
public:
	ST(int n) {
		this->n = n; 
		t.resize(4*n, 0); 
		lazy.resize(4*n,0); 
	}

	void build(int st, int end, vector<int>&arr, int root = 1){
		if(st==end) {t[root] = arr[st]; return;}
		if(st>end) return;
		int mid = st + (end-st)/2;
		build(st, mid, arr, 2*root);
		build(mid+1, end, arr, 2*root+1);
		t[root] = min(t[2*root],t[2*root+1]);
	}

	void push(int tl, int tr, int root){
		if(lazy[root]!=0){
			
			t[root] += lazy[root];
			if(tl!=tr){
				lazy[2*root]+=lazy[root];
				lazy[2*root+1]+=lazy[root];

			}
			lazy[root] = 0;
		}
	}

	//incremental update, i.e. increase each value by "val"
	void update(int l, int r, int val, int tl, int tr, int root){
		push(tl, tr, root);
		if(l>r) return;
		if(tl == l && tr == r){
			lazy[root] += val;
			push(tl, tr, root);
			return;
		}
		int tm = (tl+tr)/2;
		update(l,min(r,tm), val, tl, tm, 2*root);
		update(max(l,tm+1), r, val, tm+1, tr, 2*root+1);
		t[root] = min(t[2*root], t[2*root+1]);
	}

	int query(int l, int r, int tl, int tr, int root){
		if(l>r) return 1e9; // infinity value, should change according to the possible range of t[i]
		push(tl, tr, root); //push of lazy tree
		if(l==tl && r == tr) {return t[root];}
		int tm = tl + (tr-tl)/2;
		return min( query(l, min(r, tm), tl, tm, 2*root),
			query(max(l, tm+1), r, tm+1, tr, 2*root+1)
			);
	}

};