
#include <bits/stdc++.h>
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

const int  mod = 1e9 +7;
const int mod1= 998244353;

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

int twice_area(pair<int,int> &pt1, pair<int,int> &pt2, pair<int,int> &pt3){
	return abs(
		pt1.first*(pt2.second - pt3.second) 
		+ pt2.first*(pt3.second - pt1.second) 
		+ pt3.first*(pt1.second - pt2.second)		
	);
}
bool onLine(pair<int,int> &pt1, pair<int,int> &pt2, pair<int,int> &on){
	return (pt1.second - on.second)*(pt2.first - on.first) 
			== (pt1.first - on.first)*(pt2.second - on.second);
}
bool inTriangle(pair<int,int> &pt1, pair<int,int> &pt2, pair<int,int> &pt3,
	pair<int,int> &in)
{
	int a = twice_area(pt1,pt2,pt3);
	int b = twice_area(pt1,pt2,in);
	int c = twice_area(pt1,in,pt3);
	int d = twice_area(in,pt2,pt3);

	if(a==b+c+d){
		if(!onLine(pt1,pt2,in) && !onLine(pt2,pt3,in) && !onLine(pt3,pt1,in))
			return true;
	}

	return false;

}
int dis(pair<int,int> &pt1, pair<int,int> &pt2){
	return (pt1.first - pt2.first)*(pt1.first - pt2.first)
	+ (pt1.second - pt2.second)*(pt1.second - pt2.second);
}
double perimeter(pair<int,int> &pt1, pair<int,int> &pt2, pair<int,int> &pt3){
	return sqrt(dis(pt1,pt2)) + sqrt(dis(pt2,pt3)) + sqrt(dis(pt3,pt1));
}
int tcnt;
void solve(){
	++tcnt; 
	int n;
	cin >> n;
	v(pr) white;
	pr blue;
	fr(i,0,n){
		int x,y;
		cin >> x >> y;
		white.pb({x,y});
	}
	cin >> blue.ff >> blue.ss;

	double ans = -1.0;
	fr(i,0,n){
		fr(j,i+1,n){
			fr(k,j+1,n){
				if(inTriangle(white[i], white[j], white[k], blue)){
					if(ans==-1) ans = perimeter(white[i], white[j], white[k]);
					else ans = min(ans, perimeter(white[i], white[j], white[k]));	
				}
			}
		}
	}

	//case of quadriletral
	fr(i,0,n){
		fr(j,i+1,n){

			if(onLine(white[i], white[j], blue)) continue;
			//points[i]-blue-p & points[j]-blue-q
			int currp = INF, currq = INF;
			pr p,q;
			fr(k,0,n){
				if(white[i] == white[k] || white[j] == white[k]) continue;
				if(onLine(white[i],blue,white[k]) && 
						sqrt(dis(white[i],blue))+sqrt(dis(white[k],blue)) == sqrt(dis(white[i], white[k]))){
						// debug(white[i]);
						// debug(white[k]);
						if(dis(white[k], white[j]) < currp)
							p = white[k];
							currp = dis(white[k], white[j]);

				}
				else if(onLine(white[j],blue,white[k]) &&
					sqrt(dis(white[j],blue))+ sqrt(dis(white[k],blue)) == sqrt(dis(white[j], white[k]))
					){
						// debug(white[j]);
						// debug(white[k]);

						if(dis(white[k],white[i]) < currq)
							q = white[k];
							currq = dis(white[k],white[i]);
				} 
			}
			if(currp < INF && currq<INF){
				double peri = sqrt(dis(white[i], white[j])) 
											+ sqrt(dis(white[i], q))
											+ sqrt(dis(p, white[j]))
											+ sqrt(dis(p, q));
				if(ans==-1) ans = peri;
				else ans  = min(ans, peri);
			}
		}
	}
	

	if(ans==-1){
		cout<<"Case #"<<tcnt<<": IMPOSSIBLE"<<endl;
	}
	else {
		cout<<"Case #"<<tcnt<<": "<<fixed<<setprecision(8)<<ans<<endl;;
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
	cin>>t; 
	while(t--)
	{solve();}
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

