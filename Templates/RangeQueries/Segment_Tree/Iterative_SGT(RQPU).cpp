

/*************************** Sum Queries ***************************/ 
/********
 Syntax:
 This iterative SGT contains 2*n-1 nodes, with index 1 as root node
 	n => number of elements in array
 	t => segment tree (resize it to 2*n)
 	t[n] to t[2*n-1] contains original array, for which we are making Segment Tree
 ********/
int n;
vector<int> t;

void build(){
	for(int i = n-1; i>=1; --i) t[i] = t[i<<1] + t[i<<1 | 1];
}

int query(int l, int r){ //[l,r)
	int res = 0;
	for(l+=n, r+=n; l<r; l >>= 1, r >>=1){
		if(l&1) res += t[l++];
		if(r&1) res += t[--r]; 
	}
	return res;

}

void modify(int ind, int value){
	for(t[ind+=n]=value; ind >1; ind >>= 1) t[ind >> 1] = t[ind] + t[ind^1];
}



/*************************** Min Queries ***************************/ 
/********
 Syntax:
 This iterative SGT contains 2*n-1 nodes, with index 1 as root node
 	n => number of elements in array
 	t => segment tree (resize it to 2*n)
 	t[n] to t[2*n-1] contains original array, for which we are making Segment Tree
 ********/

int n;
int inf = 1e9;
vector<int> t;

void build(){
	for(int i = n-1; i>=1; --i ) t[i] = min(t[i<<1], t[i<<1|1]);
}

int query(int l, int r){ //[l,r)
	int res = inf + 1;
	for(l+=n,r+=n; l<r; l >>= 1, r >>= 1){
		if(l&1) res = min(res, t[l++]);
		if(r&1) res = min(res, t[--r]);
	}

	return res;
}

void modify(int ind, int val){
	for(t[ind+=n] = val; ind > 1; ind >>= 1) t[ind >> 1] = min(t[ind], t[ind^1]);
}

int inf = 1e9;
class SGT{
	int n;
	vector<int> t;
public: 
	SGT(int n, vector<int> &arr){
		this->n = n;
		this->t.resize(2*n);
		for(int i=n; i<2*n; ++i)
			t[i] = arr[i-n];

		build();
	}
	void build(){
		for(int i = n-1; i>=1; --i ) t[i] = min(t[i<<1], t[i<<1|1]);
	}

	int query(int l, int r){ //[l,r)
		int res = inf + 1;
		for(l+=n,r+=n; l<r; l >>= 1, r >>= 1){
			if(l&1) res = min(res, t[l++]);
			if(r&1) res = min(res, t[--r]);
		}

		return res;
	}

	void modify(int ind, int val){
		for(t[ind+=n] = val; ind > 1; ind >>= 1) t[ind >> 1] = min(t[ind], t[ind^1]);
	}
};