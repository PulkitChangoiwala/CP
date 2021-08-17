const int maxN = 1000; //changeable
vector<int> prime;
bool is_composite[maxN];
void linearSieve(int n){
	//every number x, can be uniquely represented as x = p*i, 
	//where p is the smallest prime factor of x
	prime.clear();
	fill(is_composite, is_composite+n+1, false);
	for(int i=2; i<=n; ++i){
		if(!is_composite[i]) prime.push_back(i);
		for(int j=0; j<prime.size() && prime[j]*i<=n; ++j){
			is_composite[prime[j]*i] = true;
			if(i%prime[j]==0) break;
		}
	}
}