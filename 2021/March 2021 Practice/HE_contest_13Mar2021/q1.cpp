 #include <bits/stdc++.h>
 using namespace std;

signed main(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int ans = 0;
    for(int i=0;i<n;++i){
        if(s[i]!=t[i]) ans++;
        while(i<n && s[i]!=t[i]){
            i++;
        }
    }
    cout<<ans<<endl;
return 0;
}
