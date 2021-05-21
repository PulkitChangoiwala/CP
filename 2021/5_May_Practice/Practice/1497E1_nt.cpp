#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> isprime(1e7+1);
vector<int> mask(1e7+1);
void preprocess(){
    int n = 1e7;
    
    isprime[1] = 1;
    int i;
    for(i=2; i*i<=n; ++i){
        if(isprime[i]==0){
            isprime[i] = i;
            for(int j = i*i; j<=n; j+=i){
                if(isprime[j]==0) isprime[j] = i; //smallest prime factor 
            }
        }
    }
    for(;i<=n; ++i) {
        if(isprime[i]==0) isprime[i] = i;
    }

}

int mask_(int v){
    if(v==1) {mask[v]=1; return 1;}
    if(mask[v]) return mask[v];
    mask[v] =1;
    int spf,j,cnt=0;
    j = v;
    spf = isprime[j];
    int ct =0;
    while(j%spf==0){
        j/=spf;
        cnt++;
    }
    if(cnt&1) mask[v] = mask[v] * spf;
    mask[v] *= mask_(j);
    return mask[v];
    
}
void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto & v : a) cin >> v;
    unordered_map<int,int> mp;
    int ans = 1;


    for(auto v : a){
        mask_(v);
   //     cout<<v <<" " << mask[v] << endl;
        if(mp[mask[v]] == ans) {
            ans++;
            mp[mask[v]] = ans;
        }
        else mp[mask[v]] = ans;
    }
    
    cout<<ans<<"\n";
    
}
signed main() {
	// your code goes here
	preprocess();
	int t; cin >> t;
	while(t--) {solve();}

	return 0;
}