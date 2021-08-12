class Prime {
	int n;
	vector<int> primeFactor; //stores smallest primeFactor
public:
	Prime(int n){
		this->n = n;
		primeFactor.resize(n+1,-1);
		sieve();
	}

	void sieve(){
		primeFactor[1] = 1; 
		for(int i=2; i<=n; ++i){
			if(primeFactor[i]!=-1) continue;
			
			primeFactor[i] = i; //setting primeFactor of a prime number as itself
			for(int j=2*i; j<=n; j+=i){
				if(primeFactor[j]==-1){
					primeFactor[j] = i;
				}
			}
		}
	}
	int getPrimeFactor(int k){
		return primeFactor[k];
	}

	vector<pair<int,int>> getPrimeFactors(int k){
		if(k==0) return {};
		if(k==1) return {{1,1}};
		int factor = primeFactor[k];
		vector<pair<int,int>> res;
		while(k>1){
			int power = 0;
			while(k%factor==0){
				k /= factor;
				power++;
			}
			res.push_back({factor, power});
			factor = primeFactor[k];
		}
		return res;
	}

};