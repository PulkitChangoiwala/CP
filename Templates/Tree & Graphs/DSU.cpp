int find(vector<int> &ds, int i) {
    return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
}

bool Union(vector<int> &ds, int i, int j){
	 i = find(ds, i), j = find(ds, j);
	 if(i==j) return false;
	 if(abs(ds[i]) < abs(ds[j])) swap(i,j); 
	 ds[i]+=ds[j]; 
	 ds[j]=i;
	 return true;
}