/***** Point assignment update, range minimum query ******/ 
/********
 Syntax:
 	n => number of elements in array
 	t => segment tree (with size 4*n)

 Terminology of function parameters
 	arr -> array for SGT to be built
 	st  -> start index of the interval of arr for which SGT to be build
 	end -> end index ------------- ---------------- 
	tl  -> start index of tree interval
	tr  -> end index of tree interval
 	root(here variable v is used) -> node representing the interval [tl, tr] in SGT

 ********/
//Min seg tree
class ST{ 
	int n;
	vector<int> t;
public:
	ST(int a){ n = a; t.resize(4*n);}
	void build(int st, int end, int v, vector<int> & arr){
		if(st == end) {t[v] = arr[st]; return;}
		int mid = (st+end)/2;
		build(st, mid, 2*v, arr);
		build(mid+1, end, 2*v+1, arr);
		t[v] = min(t[2*v],t[2*v+1]);
		return;
	}

	void update(int pos, int val, int tl, int tr, int v){
		if(tl==tr) {t[v] = val; return;}
		int tm = (tl+tr)/2;
		if(pos<=tm) update(pos, val, tl, tm, 2*v);
		else update(pos, val, tm+1, tr, 2*v+1);
		t[v] = min(t[2*v],t[2*v+1]);
	}

	int query(int l, int r, int tl, int tr, int v){
		if(l>r) return 1e9;
		if(tl == l && tr == r) return t[v];
		int tm = (tl+tr)/2;
		return min(query(l, min(r, tm), tl, tm, 2*v)
		,query(max(l,tm+1), r, tm+1,tr, 2*v+1));
	}

};