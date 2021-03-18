#include<bits/stdc++.h>
using namespace std;


#define int long long

vector<int> X{0,0,1,-1};
vector<int> Y{1,-1,0,0};
vector<vector<bool>> visited;
int n, m;

bool isValid(int x, int y){
	return (x>=0 && x<n && y>=0 && y<m);
}

void dfs(int sx, int sy, vector<vector<int>> & a){

	visited[sx][sy] = true;
	for(int i=0;i<4;++i){
		int x = sx + X[i]; int y = sy + Y[i];
		if(isValid(x,y) && !visited[x][y]){
			if(a[x][y]==a[sx][sy])
			dfs(x,y,a);
		}
	}

}
bool isPossible(int sx, int sy, vector<vector<int>> & a){
	//It is basically call to dfs function 

	dfs(sx,sy,a);
	return visited[n-1][m-1];
}

signed main(){
	//use binary search
	int c;
	cin>>n>>m>>c;
	vector<vector<int>> mat(n, vector<int>(m));
	for(int i=0;i<n;++i) for(int j =0; j<m; ++j) cin>>mat[i][j];

	int l=0, r = c;
	while(l<r){
		int mid_t = l + (r-l)/2;
		vector<vector<int>> a(n, vector<int>(m));
		for(int i=0;i<n;++i) for(int j =0; j<m; ++j) a[i][j] = min(c, mat[i][j]+mid_t);		
		visited.clear();
		visited.resize(n, vector<bool>(m));
		if(isPossible(0,0,a)){
			r = mid_t;
		}
		else{
			l = mid_t+1;
		}

	}
	cout<<l<<endl;

}