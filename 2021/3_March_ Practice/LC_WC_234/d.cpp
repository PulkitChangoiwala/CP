class Solution {
public:
    int mod = 1e9+7;
    long long be(int x1, int y){
        long long res = 1;
        long long x = x1;
        while(y>0){
            if(y&1) res = (res*1ll*x)%mod;
            x = (x*x)%mod;
            y >>= 1;
        }
        return  res;
    }
    int maxNiceDivisors(int pf) {
        //number of nice divisors is equal to multiplication of count of each prime divisor
        //thus question is find maximum possible multiplication of numbers, whose sum is say S
        /*	
        	Let, a1+a2+...+ak = s
        	and a1*a2*...*ak is maximised
			observations:
			1) Say, ci >= 4 possible, now take (ci1 = floor(ci/2), ci2 = ceil(ci/2))
				note, ci1+ci2 = ci, but ci1 * ci2 >= ci, thus our optimal solution does not 
				contain any ci >= 4

			2) We can always replace three 2s by two 3s thus making sum maximum

        */
    
        if(pf == 1) return 1;    
        int cnt3 = 0;
        int cnt2 = 0;
        int rem = 0;
        cnt3 = pf/3;
        rem = pf%3;
        if(rem == 2)  cnt2++;
        else if(rem == 1) {cnt3--; cnt2 +=2;}
        long long ans = 0;
        ans = (be(3, cnt3) * be(2, cnt2))%mod;
        return (int)ans;
        

    }
};