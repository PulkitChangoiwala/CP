#include <bits/stdc++.h>
using namespace std;
#define int long long
#define for_(i,n) for(int i=0;i<n;++i)
#define for_1(i,n) for(int i=1;i<=n;++i)
const int mod= 1e9 +7;
const int inf=1e7;


vector<int> tree;
//int tree[40];
void build(vector<int> &ar,int root, int l, int r) // l & r are array indexes
{
    if(l==r){
        tree[root]=ar[l];
        return;
    }
    else{
        
        int mid = (l+r)/2;
        build(ar, 2*root, l, mid);
        build(ar, 2*root+1, mid+1, r);
        tree[root]=min(tree[2*root],tree[2*root+1]);
    }
    
}

//root =1  t_l=0, t_r=array.size()
int query(vector<int> &ar, int l , int r, int root, int t_l, int t_r) 
{
    if(l>r) return 0;
    else if(l==t_l && r== t_r)
    {
        return tree[root];
    }
    else{
        int mid = (t_l + t_r)/2;
        return min(query(ar,l, min(r, mid),2*root,t_l, mid),
        query(ar, max(l, mid+1), r, 2*root+1, mid+1, t_r));
    }
}






/*********************** LCA Algorithm

lca(u,v):- vertex w with the smallest height in shortest path from u to v

--> perform the dfs
--> store the vertices in an array say euler_tour in order in which they are visited by dfs.
--> store height of every vertices in another array. Can be done during dfs 


****************************/


vector<vector<int>> g;
vector<int> euler_tour; //max size 2*n
vector<int> e_height; //max size 2*n
vector<int> height; //max size n
vector<int> first;  //max size n
//vector<bool> visited;
bool visited[100];
void dfs(int s)
{   
    
    // it is first visit to s
    
    visited[s]=true;
    euler_tour.push_back(s);
    e_height.push_back(height[s]);
    first[s]=euler_tour.size()-1;
    for(auto v:g[s])
    {
        if(!visited[v])
        {   height[v]=height[s]+1;
            
            dfs(v);
            euler_tour.push_back(s);
            e_height.push_back(height[s]);
            
        }
        
    }
    return;
}


signed main()
{
   
   int n,m; cin>>n>>m;
   g.resize(n+1);
   for_(i,m)
   {
       int x,y; cin>>x>>y;
       g[x].push_back(y);
       g[y].push_back(x);
   }

   first.resize(n+1);
   height.resize(n+1);
   height[1]=1;
   dfs(1);
   int v1,v2;
   cin>>v1>>v2;
   build(e_height,1,0,e_height.size()-1);
   int l =min(first[v1],first[v2]);
   int r =max(first[v1],first[v2]);
   cout<<query(e_height,l,r,1,0,e_height.size()-1);
   /*
   for_(i,euler_tour.size())
   cout<<euler_tour[i]<<" ";
   cout<<endl;
   for_1(i,n)
   cout<<first[i]<<" ";
   cout<<endl;
   for_(i,e_height.size())
   cout<<e_height[i]<<" ";
   
   */
   
   
}



















