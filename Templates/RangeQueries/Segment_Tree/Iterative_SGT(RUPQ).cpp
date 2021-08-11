/*************************** Sum Queries ***************************/ 
/**** Range Updates Point Queries ****
 Syntax:
 This iterative SGT contains 2*n-1 nodes, with index 1 as root node of SGT

 	n => number of elements in array
 	t => segment tree (resize it to 2*n)
		initially, all elements of array t will be set to zero
	marked => (resize it to 2*n)
	contains information about whether a node is marked or not in SGT (resize it 2*n)

 ********/



int n;
vector<int> t;
vector<bool> marked;


void modify(int l, int r, int val){ //[l,r) increase by val
	for(l+=n, r+=n;  l<r; l>>=1, r>>=1){
		if(l&1){t[l] += val; marked[l] = true; l++;}
		if(r&1){--r; t[r] += val; marked[r] = true;}
	}
}

int query(int ind){
	int res = arr[ind];
	for(ind+=n; ind >=1; ind >>=1){
		if(marked[ind]) res += t[ind];
	}
	return res;
}