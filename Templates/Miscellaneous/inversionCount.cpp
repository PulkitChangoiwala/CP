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
	for(t[ind+=n]+=value; ind >1; ind >>= 1) t[ind >> 1] = t[ind] + t[ind^1];
}


int countInversion(vector<int> & a, int mxVal=100000){
	n = mxVal+1;
	t.clear(); 
	t.resize(2*n,0);

	int cnt = 0, len = a.size();

	for(int i=0; i<len; ++i){
		cnt += query(a[i]+1, n);
		modify(a[i],1);
	}
	return cnt;
}

int countDistance(vector<int> a, vector<int>&b){

	int len = a.size();
	int maxVal = 0;
	unordered_map<int,deque<int>> Map;
	for(int i=0; i<len; ++i){
		Map[b[i]].push_back(i);
	}
	for(int i=0; i<len; ++i){
		int temp = Map[a[i]].front();
		Map[a[i]].pop_front();
		a[i] = temp;
		maxVal = max(maxVal, a[i]);
	}
	return countInversion(a, maxVal);
}