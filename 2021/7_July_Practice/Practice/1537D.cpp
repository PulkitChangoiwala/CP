
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
#define ppb pop_back()
#define f first
#define s second
#define endl "\n"
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
#define all(v) v.begin(), v.end()
void debug_arr(vector<int> &a){
	int len = a.size();
	fr(i,0,len){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
const int mod = 998244353;

int ad(int a, int b){
    return (a+b)%mod;
}
int mul(int a, int b){
    return (1ll*a*b)%mod;
}

/*
If n is prime or n==1 the Alice Loses
- Say n is odd:
 - n is prime, current player loses
 - Subtract a divisor, new n is even always.
 - New n can’t be a power of 2 as well.
=> n is losing state, because n is either prime or always offers a choice to go to next state which is not odd	

If n is even & > 2, then current player can not lose at this step
 - From n we can’t go to  a odd, only if n == 2^k
 - n != 2^k, then going to odd number is optimal

If n is power of 2, we can only go to an even number:
 - Suppose we go to n’
 - n’ is not power of 2, then n’ is surely a winning state, as proved above, so current player will lose, as it gives next player a winning state. 
 - Hence it will be potentially optimal to go to lower power of 2 from n
 - Suppose n == 2 -> losing
 - n==4 -> winning
 - n==8 -> losing ⇒ odd power of 2 are losing, even powers are winning


*/

void solve(){
    int n;
    cin >> n;
    
    if(n&1){
        p1("Bob");
    }
    else {
        if(__builtin_popcount(n)==1){ //power of 2
            if(__lg(n)%2){p1("Bob");} //__lg(n) gives highest set bit number, 0-based
            else p1("Alice");
        }
        else {
            p1("Alice");
        }
    }

return;} // solve ends 



signed main() {
	// your code goes here
	fast
	int t; cin>>t; while(t--)
	{solve();}
	
	return 0;
}


 
/*
 
Code belongs to:
 
 ▄████▄   ██░ ██  ▄▄▄       ███▄    █   ▄████  ▒█████   ██▓
▒██▀ ▀█  ▓██░ ██▒▒████▄     ██ ▀█   █  ██▒ ▀█▒▒██▒  ██▒▓██▒
▒▓█    ▄ ▒██▀▀██░▒██  ▀█▄  ▓██  ▀█ ██▒▒██░▄▄▄░▒██░  ██▒▒██▒
▒▓▓▄ ▄██▒░▓█ ░██ ░██▄▄▄▄██ ▓██▒  ▐▌██▒░▓█  ██▓▒██   ██░░██░
▒ ▓███▀ ░░▓█▒░██▓ ▓█   ▓██▒▒██░   ▓██░░▒▓███▀▒░ ████▓▒░░██░
░ ░▒ ▒  ░ ▒ ░░▒░▒ ▒▒   ▓▒█░░ ▒░   ▒ ▒  ░▒   ▒ ░ ▒░▒░▒░ ░▓  
  ░  ▒    ▒ ░▒░ ░  ▒   ▒▒ ░░ ░░   ░ ▒░  ░   ░   ░ ▒ ▒░  ▒ ░
░         ░  ░░ ░  ░   ▒      ░   ░ ░ ░ ░   ░ ░ ░ ░ ▒   ▒ ░
░ ░       ░  ░  ░      ░  ░         ░       ░     ░ ░   ░  
░                                                          
 
 
 
 */
