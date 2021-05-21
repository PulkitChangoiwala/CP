//Update: Range Assignment & Query: Element Access
class Seg_Tree{

int n;
vector<int> t; //store new updates only
public:
	Seg_Tree(n){
		this-> n = n;
		t.resize(4*n);
	}
	void build(int st, int end, int tnode, vector<int>&arr){
		if(st == end) {
			t[tnode] = arr[st];
			return;
		}
		int mid = (st+end)/2;
		build(st, mid, 2*tnode, arr);
		build(mid+1, end, 2*tnode+1, arr);
		t[tnode] = 0 //sum query
	}

	void update(int tl, int tr, int tnode, int l, int r, int addend){
		if(l>r) return;
		if(l==tl && tr == r) { t[tnode] += addend;}
		else {
			int tm = (tl+tr)/2;
			update(tl, tm, 2*tnode, l, min(r,tm), addend);
			update(tm+1, tr, 2*tnode +1, max(l,tm+1), r, addend);
		} 
	}
	int query(int tl, int tr, int tnode, int pos){
		if(tl == tr) { return t[tnode];}
		int tm = (tl+tr)/2;
		if(pos <=tm) return t[tnode] + query(tl,tm,2*tnode,pos);
		else return t[tnode] + query(tm+1, tr, 2*tnode+1, pos);
	}
};


class Segi_Tree{
int n;
vector<int> t;
public:
	Segi_Tree(n, vector<int>&arr){
		this->n = n;
		t.resize(2*n);
		for(int i=n; i<2*n; ++i) t[i] = arr[i-n];
	}
	void update(int l, int r, int val){
		for(l+=n, r+=n; l<r; l>>=1, r>>=1) {
			if(l&1) t[l++] += val;
			if(r&1) t[--r] += val;
		}
	}
	int query(int i){
		int res = t[i+=n];
		for(; i>1; i>>=1) {res += t[i>>1];}
	}
};