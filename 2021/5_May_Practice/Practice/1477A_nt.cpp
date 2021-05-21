#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {

	int t; cin >> t;
    /*
        let d = gcd(x1,x2,x3 ... xn)
        
        answer exists iff k is divisible by d 
        proof, 1)  Answer exists => K is divisible by d
            Every no. on board will be divisible by d, answer will generate with linear combination
            of numbers on board thus, answer that is  K will be divisible by d
        2) K is divisible by d => Answer exists
            Prove by induction
            If we can proved gcd can be generated, then we can show we can easily generate k
            Case 1, Let x1 = 0. 
                Base Case. {0,X2}. => d = x2.  Gcd i.e. x2 exists
                Ind Hypo.: g0 = gcd{0,x2,..xn-1} & g0 can be generated using the array values
                Ind. Step: g = gcd{0,x2,..n} = gcd{g0,xn}
                Now by Bezout Theoram. g0*s + xn*t = g => 2*(g0*s)-(2*t*xn) = 2*g can be generated
                Hence, g can be genrated.
                
                Now if we can generate the gcd d, then we can generate any t*d, hence k can be genrated
            
            Case  2: Let X1!=0, subtract x1 from all numbers and k. then Case 1
             
    */	
	while(t--){
	        
	    int n;
	    int k,g,x1,x; 
	    cin >> n >> k;
	    cin>>x1;
	    g = 0;
	    for(int i=2; i<=n;++i) {
	        cin >> x;
        	g = __gcd(x-x1,g);
	    }
    	k-=x1;
	    if(k%g==0) cout<<"YES\n";
	    else cout<<"NO\n";
	    
	}
	return 0;
}
