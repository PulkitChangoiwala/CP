class CentroidTree {
    int n;
    vector<bool> vis;
    vector<int> sz, parent;
    vector<vector<int>> tree,ctree;
public:
    CentroidTree(int n){
        this->n = n;
    //  this->ctree.resize(n+1);
        this->parent.resize(n+1); 
        this->sz.resize(n+1);
        this->vis.resize(n+1); 
        centroidDecomposition(1,0); 
    }
    void findSize(int s, int p){
        sz[s] = 1;
        for(auto v : tree[s]){
            if(!vis[v] && v!=p){
                findSize(v,s);
                sz[s] += sz[v];
            }
        }
        return;
    }

    int centroidNode(int s, int p, int n){   
        for(auto v : tree[s]){
                if(v!=p && !vis[v] && sz[v]>n/2){
                   return centroidNode(v, s, n);
                }
        }
        return s;
    }

    int centroidDecomposition(int s, int p){
     
        findSize(s,p);
        
        int u, ct = centroidNode(s, p, sz[s]);
        vis[ct] = true;
        parent[ct] = p;

        for(auto v : tree[ct]){
            if(!vis[v]) {
                u = centroidDecomposition(v, ct);
                // ctree[ct].push_back(u);
            }
        }

        return ct;
    }
    
    vector<int> getCT(){
        return parent;
    }
};





