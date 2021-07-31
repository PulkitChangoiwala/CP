#include <bits/stdc++.h>
using namespace std;

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
//Question
//https://www.geeksforgeeks.org/find-given-string-can-represented-substring-iterating-substring-n-times/
void solve(){
    string s;
    cin>>s;

    int n = s.length();
    
    vector<int> lps(n);
    calculate_lps(s, lps);
    //for(int i=0;i<n;++i) cout<<lps[i]<<" ";
    int largest_pref = lps[n-1];
    int period = n-largest_pref;
    if(n%period == 0 && period!=n) cout<<period<<endl;
    else cout<<-1<<endl;
    cout<<endl;
    return;
}

int main() {

    int t;
    cin>>t;
    while(t--)
    solve();
	return 0;
}
