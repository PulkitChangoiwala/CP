
#include <bits/stdc++.h>
using namespace std;
#define int long long
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
#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
void debug_arr(vector<int> &a){
	int len = a.size();
	fr(i,0,len){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
/*
# ones = x, # zeroes = y

x is odd:
    x%4==1 :-  Koa chooses 1, then repeats every move of Koala, then Koa will have 1(chosen)
    in first step + tt ones & koala will have tt ones. As after choosing intial one, #ones will
    be divisible by tt, then tt will be even
    
    hence koa wins
    
    
    x%4==3 :-
        y%2==0:- If second player repeats every move of first player, second player wins, as first 
        player will have even number of ones
        Koala Wins
        
        y%2==1: Koa chooses 1, now this case is same as previous one, with koa as second player
        Koa Wins
*/


const int  mod = 1e9 +7;
const int mod1= 998244353;
void solve(){ 
int n; cin >> n;
v(int) a(n); fr(i,0,n) cin >> a[i];
int t,o,z;



for(int j=30; j>=0; --j){
    t = 1<<j; o =0; z=0;
    for(int i=0; i<n; ++i){
        if(a[i] & t) o++;
        else z++;
    }
    if(o%2==0) continue;
    else {
      if(o%4==3 && z%2==0) p1("LOSE");
      else p1("WIN");
      return;
    }
}

p1("DRAW");


return;} // solve ends 



signed main() {
	// your code goes here
	fast
	int t; cin>>t; while(t--)
	{solve();}
	
	return 0;
}


