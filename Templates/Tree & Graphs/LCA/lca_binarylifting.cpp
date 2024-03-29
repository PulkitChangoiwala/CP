




#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long 
#define fr(i,s,e) for(int i=s;i<e;++i)
#define fr1(i,s,e) for(int i=s;i>e;--i)
#define p0(a) cout << a <<" "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
#define INF (ll)1e18 + 100
#define v(d) vector<d>
#define pr pair<int, int>
#define pr1(d1,d2) pair<d1,d2>
#define pb push_back
#define f first
#define s second

void dubug_arr(vector<int> &a){
	int len = a.size();
	fr(i,0,len){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}


const int  mod = 1e9 +7;
const int mod1= 998244353;



/************** LCA Binary Lifting ****************/
//preprocessing:- O(nlogn) each query:- O(log n)
// logic: store all ancestor of u at height 1,2,4,8... above

int n;
int logn; //logn  = ceil(log2(n));
int timer;

vector<vector<int>> time_; //discovery time of node i is time_[i][0] in dfs and last discovery time is time_[i][1]
vector<vector<int>> ancestor;// ancestor.resize(n+1,vector<int>(logn+1))
vector<vector<int>> adj;

void dfs(int v, int p){

	time_[v][0]=++timer;
	ancestor[v][0]=p; //immediate ancestor
	for(int i=1;i<=logn;++i){
		ancestor[v][i] = ancestor[ancestor[v][i-1]][i-1];
	}
	for(auto u: adj[v]){
		if(u!=p)
		dfs(u,v);
	}
	time_[v][1]=++timer;
}

bool is_ancestor(int u,int v){
	return ( (time_[u][0]<=time_[v][0])&&(time_[u][1]>=time_[v][1]) );
}
int lca(int u, int v){
	if(is_ancestor(u,v)){ return u;}
	if(is_ancestor(v,u)){ return v;}
	else{
		for(int i=logn;i>=0;--i){
			if(!is_ancestor(ancestor[u][i],v)) {
				u=ancestor[u][i]; 
				//it will store the child of LCA which is also the ancestor of u
				//first time if conditioned is executed when u = LCA.child	
			}
		}
	}

	return ancestor[u][0]; // parent of u which is lca

}

void preprocess(int root){
	time_.resize(n+1,vector<int>(2));
	timer=0;
	logn=ceil(log2(n)); 
	ancestor.resize(n+1,vector<int>(logn+1));
	dfs(root,root);
}
/************** LCA Binary Lifting ****************/



/**********************************************************************************************
				************************* LCA *********************************
***********************************************************************************************/


void solve(){ 
 cin>>n;
  adj.resize(n+1);
   fr(i,1,n+1){
   	int m;cin>>m;
   	fr(i,0,m){ int x;cin>>x; adj[i].pb(x); adj[x].pb(i);}
   }
   preprocess(1);
 	int q; cin>>q;
 	fr(i,0,q){
 		int u,v; cin>>u>>v;
 		// LCA obj(adj);
 		//obj.LCA(adj);
 		cout<<lca(u,v)<<endl;
 
 	}
  
  return;} // solve ends 



signed main() {
	// your code goes here
	int t; cin>>t; while(t--)
	{solve();}
	
	return 0;
}


