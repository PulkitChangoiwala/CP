class Segment_Tree{
	int operation; //0 for sum, 1 for min, 2 for max
	vector<int> seg_tree; //Store sum value for sum operation, whereas index value for other two
	vector<int> array; //original array
public:
	Segment_Tree(int op, vector<int> &arr){
		this->operation = op;
		this->array = arr;
		int n = array.size(); (this->seg_tree).resize(2*n);
		if(op == 0 ) for(int i=n;i<2*n;++i) (this->seg_tree)[i] = arr[i-n]; //zero indexed array
		else if(op == 1 || op == 2) for(int i=n;i<2*n;++i) (this->seg_tree)[i] = i-n; //zero indexed array 	

	}

	void build(){ 
		for(int i = n-1; i>=1; i--) {
			if(operation==0) {seg_tree[i] = seg_tree[i<<1] + seg_tree[i<<1|1]; /*2*i & 2*i+1*/ }
			else if(operation == 1) {seg_tree[i] = array[seg_tree[i<<1]] < array[seg_tree[i<<1|1]] ? seg_tree[i<<1] : seg_tree[i<<1|1];}
			else if(operation == 2) {seg_tree[i] = array[seg_tree[i<<1]] > array[seg_tree[i<<1|1]] ? seg_tree[i<<1] : seg_tree[i<<1|1];}
		
		}
	}
	
	void modify(int ind, int value){ //ind is index in original array
		seg_tree[ind+n] = operation == 0 ? value : seg_tree[ind+n];
		for(; ind>1; ind >>= 1) {
			if(operation==0) {seg_tree[ind>>1] = seg_tree[ind] + seg_tree[ind^1]; }
			else if(operation == 1) {seg_tree[ind>>1] = array[seg_tree[ind]] < array[seg_tree[ind^1]] ? seg_tree[ind] : seg_tree[ind^1];}
			else if(operation == 2) {seg_tree[ind>>1] = array[seg_tree[ind]] > array[seg_tree[ind^1]] ? seg_tree[ind] : seg_tree[ind^1];}
		}
	}
	
	int query(int l, int r){ //Query on [l,r)
		int ans;
		ans = operation == 0 ? 0 : l;
		for(l+=n,r+=n; l<r; l >>= 1, r >>=1;){
			//l or r is odd, means it is right child of its parent
			if(operation == 0) {
				if(l&1) {ans += seg_tree[l++];}
				if(r&1) {ans += seg_tree[--r];}
			}
			else if(operation == 1){
				if(l&1) {ans = array[seg_tree[l]] < array[seg_tree[ans]] ? seg_tree[l] : seg_tree[ans]; l++;}
				if(r&1) {--r; ans = array[seg_tree[r]] < array[seg_tree[ans]] ? seg_tree[r] : seg_tree[ans]; }
			}
			else if(operation == 2){
				if(l&1) {ans = array[seg_tree[l]] > array[seg_tree[ans]] ? seg_tree[l] : seg_tree[ans]; l++;}
				if(r&1) {--r; ans = array[seg_tree[r]] > array[seg_tree[ans]] ? seg_tree[r] : seg_tree[ans]; }
			}
		}
		return ans;
	}		


};