int ind; 
long long mod1 = 1e9+7;
long long base1 = 27, invbase1 = 370370373; 

long long mod2 = 2147483647;
long long base2 = 256, invbase2 = 8388608; 

//checking if string t contains repeating substring of size k
bool isPresent(string &s, int k){
    
    string_view t(s);
    int n = t.length(), j=0;
    long long rh1 = 0, rh2 = 0, pbase1=1, pbase2=1;
    
    unordered_map<int,bool> mp1, mp2;
    
    for(int i=0; i+k-1<=n-1; ++i){     
        while(j<n && j<=i+k-1) {
            rh1 = (rh1 + 1ll*(t[j])*pbase1)%mod1;
            pbase1 = (pbase1*base1)%mod1;
            rh2 = (rh2 + 1ll*(t[j])*pbase2)%mod2;
            pbase2 = (pbase2*base2)%mod2;
            j++;
        }
        
        if(mp1.count(rh1) && mp2.count(rh2)) {ind = i; return true;}
        else {mp1[rh1]=true; mp2[rh2]=true;}
        
        rh1 = (rh1 + mod1 - (t[i]))%mod1;
        rh1 = (rh1*invbase1)%mod1;
        pbase1 = (pbase1*invbase1)%mod1;
        rh2 = (rh2 + mod2 - (t[i]))%mod2;
        rh2 = (rh2*invbase2)%mod2;
        pbase2 = (pbase2*invbase2)%mod2;

    }
        
    return false;
}