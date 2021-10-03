
#include <bits/stdc++.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
#define int long long
#define fr(i,s,e) for(int i=s;i<e;++i)
#define fr1(i,s,e) for(int i=s;i>e;--i)
#define p0(a) cout << a <<" "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
#define INF (ll)1e18 + 100
#define v(d) vector<d>
#define all(x) (x).begin(), (x).end()
#define pr pair<int, int>
#define pr1(d1,d2) pair<d1,d2>
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define endl "\n"
#define sz(x) ((int)(x).size())
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

// const int  mod = 1e9 +7;
const int mod= 998244353;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
//void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


/*
Convention:
	- Stripe: Band of alternate 0 & 1, eg: 0101010101.... or 1010101010...
	- RowStripe0: A stripe which starts with 0, and forms the row of the grid. Eg: 010101...
	- RowStripe1: A stripe which starts with 1, and forms the row of the grid. Eg: 101010...
	- Similarly, ColStripe0, ColStripe1
	- n: number of rows, m: number of columns
	- chess pattern: grid with chessboard pattern(first cell white)
	- anti chess pattern: grid with inverted chessboard pattern(first cell black)

Observations:
	O1 A valid grid consists of either
		1) Combination of n RowStripes: 2^n ways
		2) or Combination of m ColStripes: 2^m ways	
		3) chess & antichess patterns can be obtained by both 1) & 2)
			=> # ways to form valid grids, when all cells are empty = 2^n + 2^m - 2
	
	O2 As we can see we can segragate answer into two part, 
		1) Grids which are formed by RowStripes
		2) Grids which are formed by ColStripes

		Thus, from now on, we treat them separately.

	O3 Partially filled grid.
		- Say column c has some cell already filled.
			- Case 1: c has cells filled according to the chess(or anti chess) pattern only
					- Then, column c can has only one possible configuration.
					 => # ways to form valid grid with ColStripes = 2^(m-1)
					- If such k columns are already filled
					 => # ways to form valid grid with ColStripes = 2^(m-k)
			
			- Case 2: Column c has cells corresponding to both chess and antichess pattern
				- Then, we can't fill the cell c neither with ColStripe0 nor with ColStripe1
				=> # ways to form valid grid with ColStripes = 0
				- c is thus a bad_column

		- Similar derivation if some row r is filled

		- Collission case:
			- If grid was completely empty then there were two collisions, as explained in O1.3
			- If grid was partially filled
				- Case 1: If grid filled with chess (or anti chess) pattern
					- Subtract 1 from final answer
				- Case 2: If grid is filled with both pattern
					- No subtraction is required, as chess or anti chess pattern cant be achieved
Code
	C1 Mark columns which are already filled
		- For each column maintain whether it is filled in ColStripe0 pattern or ColStripe1 pattern

	C2 Similar to C1, mark rows which are filled
*/


int bad_rows, bad_cols, empty_rows, empty_cols, antiChess, chess;

void add(int x, int y, int color, vector<vector<int>> &Row, vector<vector<int>> &Col){
	//add a cell, check if row(or col) is filled, check if new bad row(or col) is generated

	int stripeType = (x+color)%2; //checks which stripe it is, 0101... => 0 & 10101... => 1
	if(Col[y][0] + Col[y][1] == 0) empty_cols--;
	if(Col[y][stripeType]==0 && (Col[y][1-stripeType]!=0)) bad_cols++;
	Col[y][stripeType]++;

	stripeType = (y+color)%2; //checks which stripe it is, 0101... => 0 & 10101... => 1
	if(Row[x][0] + Row[x][1] == 0) empty_rows--;
	if(Row[x][stripeType]==0 && (Row[x][1-stripeType]!=0)) bad_rows++;
	Row[x][stripeType]++;

	// (x+y+color)%2 == 0 for chess pattern &  == 1 for antichess pattern
	if((x+y+color)%2 == 0) chess++;
	else antiChess++;

}

void remove(int x, int y, int color, vector<vector<int>> &Row, vector<vector<int>> &Col){
	//removing a cell, check if row(or col) is emptied, check if new bad row(or col) is generated
	int stripeType = (x+color)%2; //checks which stripe it is, 0101... => 0 & 10101... => 1	
	if(Col[y][stripeType] == 1 && Col[y][1-stripeType] == 0 ) empty_cols++;
	if(Col[y][stripeType] == 1 && (Col[y][1-stripeType]!=0) ) bad_cols--;
	Col[y][stripeType]--;

	stripeType = (y+color)%2; //checks which stripe it is, 0101... => 0 & 10101... => 1
	if(Row[x][stripeType]==1 && Row[x][1-stripeType]==0) empty_rows++;
	if(Row[x][stripeType]==1 && (Row[x][1-stripeType]!=0)) bad_rows--;
	Row[x][stripeType]--;

	// (x+y+color)%2 == 0 for chess pattern &  == 1 for antichess pattern
	if((x+y+color)%2 == 0) chess--;
	else antiChess--;
}

void solve(){ 
	int n,m,k;
	cin >> n >> m >> k;
	map<pair<int,int>, int> cells;
	empty_cols = m; empty_rows = n;
	vector<vector<int>> filledRow(n, vector<int>(2)), filledCol(m, vector<int>(2));
	vector<int> pow2(max(m,n)+1);
	pow2[0] = 1;
	for(int i=1; i<=max(m,n); ++i)
		pow2[i] = (pow2[i-1]*2)%mod;


	while(k--){
		int x,y,t;
		cin >> x >> y >> t;
		--x; --y;

		if(cells.count({x,y})){
			remove(x,y,cells[{x,y}],filledRow,filledCol);
			cells.erase({x,y});
		}

		if(t!=-1){
			cells[{x,y}] = t;
			add(x,y,cells[{x,y}],filledRow,filledCol);
		}

		long long ans = 0;
		if(bad_cols==0)
			ans = (ans + pow2[empty_cols])%mod;
		if(bad_rows==0)
			ans = (ans + pow2[empty_rows])%mod;

		//remove collision
		if(chess==antiChess && chess==0)
			ans = (ans - 2 + mod)%mod;
		else if(chess == 0 || antiChess == 0)
			ans = (ans - 1 + mod)%mod;

		p1(ans);
	}
return;} // solve ends 


signed main() {
	// your code goes here
	#ifndef ONLINE_JUDGE
		freopen("err", "w", stderr);
	#endif
	fast


	auto start1 = chrono::high_resolution_clock::now();
	int t = 1; 
	while(t--)
	{	
		solve();
	}

	auto stop1 = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop1 - start1);
	#ifndef ONLINE_JUDGE
	cerr << "Time in ms: " << duration . count() / 1000 << endl;
	#endif

	
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

