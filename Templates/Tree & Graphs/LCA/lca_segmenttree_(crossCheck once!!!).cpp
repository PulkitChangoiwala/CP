




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



/**********************************************************************************************
				************************* LCA *********************************
***********************************************************************************************/

/************************ LCA Segment Tree ****************************/

/*
    preprocessing O(n) each query O(log n)
    logic: 
        do the euler tour. 
        for LCA(u,v) find first occurence of u,v in euler tour 
        and find lowest height of all vertices in between ( both are inclusive) that is LCA
*/


// int n;
// v(v(int)) adj; // resizing in main
struct LCA{
	vector<int> euler, height, first, tree; //do resizing as needed at max 2*(#euler arr size)
	int n, m;
	LCA(v(v(int)) &adj, int root=0){
		n = adj.size() - 1; // # nodes
		height.resize(n+1);
		first.resize(n+1);
		dfs(adj,root);
		
        m = euler.size();
		tree.resize(2*m);
		build(); //segment tree building
	}


    //generates array euler, it contains euler tour. euler[i] is a tree node number 
	void dfs(v(v(int)) &adj,int node,int h=0, int p = -1){
		height[node]=h;
		first[node] = euler.size();
		euler.push_back(node);
		for(auto to : adj[node]){
			if(to!=p){
				dfs(adj,to,h+1,node);
				euler.push_back(node);
			}
		}
	}

    //tree[i] contains the node number corresponding to the minimum height
	void build(){
		//root 1 based tree 
        for(int i=m; i<2*m; ++i) tree[i] = euler[i-m];
		for(int i = m-1;i>0;--i) {
			tree[i] = height[tree[2*i]]<height[tree[2*i+1]]? tree[2*i] : tree[2*i+1]; 
		}
	}

	int query(int l, int r){ 
    //[l,r) -> these are index of euler array
    // out of all nodes {euler[l], euler[l+1] ... euler[r-1]} we have to find the one which has minimum height
	int node= euler[l];
    int res= height[node];
	for(l+=m,r+=m; l<r; l>>=1,r>>=1){
		if(l&1) {
			if(height[tree[l]]<res) {node=tree[l];res=height[tree[l++]];}}
		if(r&1) {
			if(height[tree[--r]]<res) {node=tree[r]; res = height[tree[r]];}}
	}
	return node; //returns node of min height
	}	


    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(left, right+1);
        
    }

};







/************************ LCA Segment Tree ****************************/















void solve(){
    int n; 
   cin>>n;
   v(v(int)) adj(n+1);
   fr(i,0,n){
   	    int m;
        cin>>m;
   	    fr(i,0,m) { int x;cin>>x; adj[i].pb(x); adj[x].pb(i);}
   }
    
    LCA obj(adj);
 	int q; cin>>q;
 	fr(i,0,q){
 		int u,v; cin>>u>>v;
 	 		cout<<obj.lca(u,v)<<endl;
 
 	}

  
  return;} // solve ends 



signed main() {
	// your code goes here
	//int t; cin>>t; while(t--)
	{solve();}
	
	return 0;
}

