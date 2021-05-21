//Update: Range Assignment & Query: Element Access
class Seg_Tree{

int n;
vector<int> t;
vector<bool> marked;
public:
	Seg_Tree(n){
		this-> n = n;
		t.resize(4*n);
		marked.resize(4*n);
	}
	void push(v) {
		if(marked[v]) {
			t[v*2] = t[v*2 + 1] = t[v];
			marked[v*2] = marked[v*2+1] = true;
			marked[v] = false;
		}
	}
	void build(int st, int end, int tnode, vector<int>&arr){
		if(st == end) {
			t[tnode] = arr[st];
			return;
		}
		int mid = (st+end)/2;
		build(st, mid, 2*tnode, arr);
		build(mid+1, end, 2*tnode+1, arr);
		t[tnode] = t[2*tnode] + t[2*tnode + 1]; //sum query
	}

	void update(int tl, int tr, int tnode, int l, int r, int val){
		if(l>r) return;
		if(l==tl && tr == r) { t[tnode] = val; marked[tnode] = true;}
		else {
			push(tnode); //old assignment to parent is pushed down to children
			int tm = (tl+tr)/2;
			update(tl, tm, 2*tnode, l, min(r,tm), val);
			update(tm+1, tr, 2*tnode +1, max(l,tm+1), r, val);
		} 
	}
	int query(int tl, int tr, int tnode, int pos){
		if(tl == tr) { return t[tnode];}
		push(v);
		int tm = (tl+tr)/2;
		if(pos <=tm) return query(tl,tm,2*tnode,pos);
		else return query(tm+1, tr, 2*tnode+1, pos);
	}
};

