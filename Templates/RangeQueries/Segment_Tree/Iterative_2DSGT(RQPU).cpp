int n,m;
vector<vector<int>> t; //takes 4*n*m memory

void build(){
	
	//first building segment tree for each row, storing in t[n to 2*n-1][1 to m-1] 
	for(int i = n; i<2*n; ++i)
		for(int j = m-1; j>=1; --j) 
			t[i][j] = t[i][j<<1] + t[i][j<<1|1];

	//Building Segment Tree of rows' segment tree. Store it in t[1 to n-1][1 to 2*m-1]
	for(int j=1; j<2*m; ++j)
		for(int i=n-1; i>=1; --i )
			t[i][j] = t[i<<1][j] + t[i<<1|1][j];

}

//Suppose we find query for sub matrix with top left corner (a,b) & bottom right corner (c,d) (all 0 indexed)
//then L1 = a, R1 = c+1, l2 = b, r2 = d+1 
int query(int L1, int R1, int l2, int r2){ //[l1,r1), [l2,r2)
	int res = 0;
	int l1 = L1, r1 = R1;
	for(l2+=m, r2+=m; l2 < r2; l2 >>= 1, r2 >>= 1){
		if(l2&1) {
			l1 = L1, r1 = R1;
			for(l1+=n,r1+=n; l1<r1; l1>>=1,r1>>=1) {
				if(l1&1) {res += t[l1][l2]; ++l1;}
				if(r1&1) {--r1; res += t[r1][l2];}
			}
			++l2;
		}
		if(r2&1){
			--r2;
			l1 = L1, r1 = R1;
			for(l1+=n,r1+=n; l1<r1; l1>>=1, r1>>=1){
				if(l1&1) {res += t[l1][r2]; ++l1;}
				if(r1&1) {--r1; res += t[r1][r2];}	
			}
		}
	}
	return res;
}

// arr[i][j] was updated, t[i+n][j+m] reflects the new value 
void update(int i, int j, int val){
	i+=n; j+=m;
	int I=i, J = j;

	t[i][j] = val;  //new value


	for(j=J;j>1;j>>=1) t[i][j>>1] = t[i][j] + t[i][j^1];
	
	for(i=I;i>1; i>>=1){
		for(j=J;j>=1; j>>=1) 
			t[i>>1][j] = t[i][j] + t[i^1][j];	
	}
	 	
}

void preprocess(int n1, int m1){ 
		
	n = n1
	m = m1;
	t.resize(2*n, vector<int>(2*m,0));
	char ch;
	fr(i,n,2*n) { 
		fr(j,m,2*m) {
			// set t[i][j] as array entires t[i][j] = arr[i-n][j-m]
		}
	}
	build();
return;}  
