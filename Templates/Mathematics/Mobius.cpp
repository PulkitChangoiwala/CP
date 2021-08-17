class Mobius{
	int n;
	vector<int> MU;
	vector<int> primes;
	vector<int> primeFactor;

public: 
	Mobius(int n){
		this->n = n;
		this->MU.resize(n+1,0);
		this->primeFactor.resize(n+1,-1);		
		calculateMobiusFunction();
	}

	void calculateMobiusFunction(){
		//using linear sieve method
		MU[1] = 1;
		primeFactor[1] = 1;
		for(int i=2; i<=n; ++i){
			if(primeFactor[i]==-1) {MU[i] = -1; primes.push_back(i); primeFactor[i]=i;}
			for(int j=0; j<primes.size() && primes[j]*i<=n; ++j){
				primeFactor[primes[j]*i] = primes[j];
				if(i%primes[j]==0) break;
				MU[primes[j]*i] = MU[primes[j]]*MU[i];
			}
		}

	}

	int mu(int n){
		return MU[n];
	}
};