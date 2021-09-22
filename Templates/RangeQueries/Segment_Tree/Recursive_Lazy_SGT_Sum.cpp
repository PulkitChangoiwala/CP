/***** Range incremental update, range assignment update, range sum query ******/ 
/********
 Syntax:
 	n => number of elements in array
 	t => segment tree (with size 4*n)
 	lazy => lazy tree (with size 4*n) for incremental updates
 	lazy_ => lazy tree (with size 4*n) for assignmental updates
 Terminology of function parameters
 	arr -> array for SGT to be built
 	st  -> start index of the interval of arr for which SGT to be build
 	end -> end index ------------- ---------------- 
	tl  -> start index of tree interval
	tr  -> end index of tree interval
 	root(here var v is used) -> node representing the interval [tl, tr] in SGT
 	type -> type of update, incremental or update,  type==1 for incremental

 ********/


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

		if(lazy[v]!=0){ //incremental updates
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
			if(type==1){ //incremental update
				lazy[v]+=val;	
			} 
			else { //assignment update
				lazy_[v] = val;
				lazy[v] = 0;
			}
			push(tl, tr, v);
			return;
		}
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
};