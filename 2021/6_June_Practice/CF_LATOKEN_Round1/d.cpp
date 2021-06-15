#include <bits/stdc++.h>
using namespace std;

#define INF (ll)1e18 + 100

#define endl "\n"
#define fastest ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);   

const int  mod = 1e9 +7;
vector<int> ds;
#define int long long
#define ll long long 
#define fr(i,s,e) for(int i=s;i<e;++i)

#define p1(a) cout << a << endl

signed main() {
    fastest
    int n;
    cin >> n;
    set<pair<int,int>> st;
    vector<int> d(n+1);
    set<int> s1,s2;
    
    cout<<"? 1\n";
    cout.flush();
    fr(i,1,n+1) {
        cin >> d[i];
        
        if(d[i]==1) st.insert({1,i});
        
        if(d[i]&1) s1.insert(i);
        else s2.insert(i);
    }
    
    s2.erase(1);
    if(s2.size()<s1.size()){
        s1.clear();
        for(auto el : s2) s1.insert(el);
    }
    
    for(auto el : s1){
        cout<<"? "<<el<<endl;
        cout.flush();
        fr(i,1,n+1) {
            cin >> d[i];
            if(d[i]==1) st.insert({min(el,i),max(el,i)});
        }
    }
    
    cout<<"!\n";
    cout.flush();
    for(auto &el : st){
        cout<<el.first<<" "<<el.second<<endl;
        cout.flush();
    }
    
    return 0;
}