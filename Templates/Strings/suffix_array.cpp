#include<bits/stdc++.h>
using namespace std;


void suffix_array(string &s, vector<int> &p){

	s+= '$';
	int n = s.length();
	p.clear();
	p.resize(n);
	
	vector<int> c(n); //contains equivalence class c[i] is order substring starting from i
	
	//k=0, base case
	vector<pair<char, int>> temp;
	for(int i=0;i<n;++i){ temp.push_back({s[i], i});}
	sort(temp.begin(), temp.end());
	
	for(int i=0;i<n;++i) {p[i] = temp[i].second;}
	c[p[0]] = 0;
	for(int i=1;i<n;++i) {
		if(temp[i].first == temp[i-1].first){
			c[p[i]] = c[p[i-1]];
		}
		else {
			c[p[i]] = c[p[i-1]]+1;
		}
	}
	int k=0;
	while((1<<k)<n){
		//for k to k+1
		vector<pair<pair<int,int>,int>> temp;
		for(int i=0;i<n;++i){ temp.push_back({{c[i], c[(i+ (1<<k))%n]}, i});}
		sort(temp.begin(), temp.end());
		
		for(int i=0;i<n;++i) {p[i] = temp[i].second;}
		c[p[0]] = 0;
		for(int i=1;i<n;++i) {
			if(temp[i].first == temp[i-1].first){
				c[p[i]] = c[p[i-1]];
			}
			else {
				c[p[i]] = c[p[i-1]]+1;
			}
		}
		k++;
	}

return;
}

int main(){
	string s;
	cin>>s;
	vector<int> p;
	suffix_array(s,p);
	for(int i=0;i<(int)p.size();++i)
	{
		cout<<p[i]<<" ";
	}
	cout<<endl;
	return 0;
}