#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> ans;
int size(int i){
    if(ans[i]!=-1) return ans[i];    
    if(adj[i].size()==0) {ans[i]=0; return 0;}
    
    int res = 0;
    for(auto el : adj[i]) {
        res += size(el)+1;
    }
    ans[i] = res;
    return res;
}
void solve(){
    cin >> n;
    adj.resize(n+1);
    int a;
    for(int i=2;i<=n;++i) {
        cin >> a;
        adj[a].push_back(i);
    }
    ans.resize(n+1,-1);
    for(int i=1;i<=n;++i) {
        if(ans[i]==-1) size(i);
        cout<<ans[i]<<" ";  
        
    }
    cout<<endl;

}

int main() {
    solve();
	return 0;
}
