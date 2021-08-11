void calculate_lps(string &s, vector<int> &lps){
    
    lps[0]=0;
    int n = s.length();
    int i=1, j=0;
    
    while(i<n){
        while(j>0 && s[i]!=s[j]){
            j = lps[j-1];            
        }
        if(s[i] == s[j]) ++j;
        lps[i] = j;
        i++;
    }
    return;
    
}