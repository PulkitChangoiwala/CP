/*
Reference: https://cp-algorithms.com/string/manacher.html
	Algorithm have 3 cases

	1) Current index i > r => run brute force at i then update r
	2) i<=r, Let j(= l+(r-i)) be the mirror image of i in segment [l,r] ... for odd length case 
		2.1) l-(count[j]-1) <= l => count[i] = r-i+1 => brute force => update r
		2.2) l-(count[j]-1) > l  => count[i] = count[j]
	
	2') i<=r, Let j(= l+(r-i)+1) be the mirror image of i in segment [l,r] ... for even length case 
		2.1) l-(count[j]-1) <= l => count[i] = r-i+1 => brute force => update r
		2.2) l-(count[j]-1) > l  => count[i] = count[j]

Note: 
	- longestPal -> longest palindrome ending at i
	- longest palindrom starting at i = longest palindrome ending at n-1-i in the reversed string.
		Thus, run Manacher for reversed string to know length of longest palindrom starting at i

*/
class Manacher{
	int n;
	string s;
	vector<vector<int>> cntPal; //count of palindrome centered at i
    vector<vector<int>> longestPal; //longest palindrome ending at i
public: 
	Manacher(string &t){
		this->n = t.length();
		this->s = t;
		cntPal.resize(2, vector<int>(n));
        longestPal.resize(2, vector<int>(n));
        for(int i=0; i<n; ++i) {longestPal[0][i] = 1;}
		runManacherAlgo();
	}

	void runManacherAlgo(){
		//type = 0, odd length, type = 1 even length
		for(int type = 0; type <= 1; ++type){
			for(int i=0, l=0, r=-1; i<n; ++i){ 
			//[l,r] denotes right most palindrome, k denotes count of pal. centered at i
				int k = ((i>r) ? 1-type : min(cntPal[type][l+r-i+type], r-i+1));
                while(0<=i-k-type && i+k<n && s[i-k-type] == s[i+k]) {
                    longestPal[type][i+k] = max(longestPal[type][i+k],2*k+1+type);
                    k++;
                }
                cntPal[type][i] = k--;
				if(i+k>r) {l=i-k-type; r = i+k;}
			}
		}
	}


    vector<vector<int>> getPalInfo(){
        return longestPal;
    }
};