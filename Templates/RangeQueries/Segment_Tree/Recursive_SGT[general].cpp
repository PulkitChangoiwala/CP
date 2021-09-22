/*
    Convention.
        1 is the root of segment tree.
        L,R: Denotes Segment Tree Range = [0,N-1] for complete tree
        i,j: Denotes the interval range for which we need the answer

Sample Initialisation
    SegTree sgt;
    sgt.init(n);
    sgt.build(1,0,n-1,a);
Sample Query
    int ans = sgt.query(l,r).mn;  //l,r are 0-indexed
*/
struct NODE{
    // write required attributes
    ll mn;

    //Default values
    NODE(){
        mn = (ll)(1e13);
    }
};

struct SegTree{
    ll N;
    vector<NODE>st; // segment tree
    vector<bool>clazy;
    vector<ll>lazy;

    void init(ll n){
        N = n;
        st.resize(4*N+5);
        clazy.assign(4*N+5, false);
        lazy.assign(4*N+5,0);
    }

    // Write required merge function
    void merge(NODE &curr, NODE &l, NODE &r){
        curr.mn = min(l.mn, r.mn);
    }

    //Handle lazy propagation appropriately
    void propagate(ll node, ll L, ll R){
        if(L != R){
            clazy[node*2] = 1;
            clazy[node*2+1] = 1;
            lazy[node*2] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        st[node].mn = lazy[node]; //Assignment Update
        clazy[node] = 0;
    }

    void build(ll node, ll L, ll R, vector<int> &arr){ 
        //node-> NODE number. L,R array indexes (0-indexed)
        if(L==R){
            st[node].mn = arr[L];
            return;
        }
        ll mid = (L+R)/2;
        build(2*node,L,mid,arr);
        build(2*node+1,mid+1,R,arr);
        merge(st[node], st[2*node], st[2*node+1]);
    }

    NODE Query(ll node, ll L, ll R, ll i, ll j){
        if(clazy[node]){
            propagate(node,L,R);
        }
        if(j < L || i > R){
            return NODE();
        }
        if(i <= L && j >= R){ 
            //current tree node [L,R] completely lies inside [i,j]
            return st[node];
        }
        ll mid = (L+R)/2;
        NODE left = Query(2*node,L,mid,i,j);
        NODE right = Query(2*node+1, mid+1,R, i,j);
        NODE curr;
        merge(curr, left, right);
        return curr;
    }

    NODE pQuery(ll node, ll L, ll R, ll pos){
        if(clazy[node]){
            propagate(node,L,R);
        }
        if(L==R){
            return st[node];
        }
        ll mid = (L+R)/2;
        if(pos <= mid){
            return pQuery(2*node, L, mid, pos);
        }
        else{
            return pQuery(2*node+1,mid+1,R,pos);
        }
    }

    void Update(ll node, ll L, ll R, ll i, ll j, ll val) //assignment update
    {
        if(clazy[node])
            propagate(node, L, R);
        if(j<L || i>R)
            return;
        if(i<=L && R<=j)
        {
            clazy[node] = 1;
            lazy[node] = val;
            propagate(node, L, R);
            return;
        }
        ll mid = (L + R)/2;
        Update(node*2, L, mid, i, j, val);
        Update(node*2 + 1, mid + 1, R, i, j, val);
        merge(st[node], st[node*2], st[node*2 + 1]);
    }

    void pUpdate(ll node, ll L, ll R, ll pos, ll val)
    {
        if(clazy[node])
            propagate(node, L, R);
        if(L == R)
        {
            clazy[node] = 1;
            lazy[node] = val;
            propagate(node, L, R);
            return;
        }
        ll mid = (L + R)/2;
        if(pos <= mid)
            pUpdate(node*2, L, mid, pos, val);
        else
            pUpdate(node*2 + 1, mid + 1, R, pos, val);
        merge(st[node], st[node*2], st[node*2 + 1]);
    }

    NODE query(ll pos)
    {
        return pQuery(1, 0, N-1, pos);
    }

    NODE query(ll l, ll r)
    {
        return Query(1, 0, N-1, l, r);
    }

    void update(ll pos, ll val)
    {
        pUpdate(1, 0, N-1, pos, val);
    }

    void update(ll l, ll r, ll val)
    {
        Update(1, 0, N-1, l, r, val);
    }
};