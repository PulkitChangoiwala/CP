//Question: 421. Maximum XOR of Two Numbers in an Array
#include<bits/stdc++.h>
using namespace std;

class Trie{
public:
	int count;
	vector<Trie*> children;
	Trie(){
		count = 0;
		children.resize(2, NULL);
	}

};

int xor_(Trie* root, int val){

	bitset<33> bs(val);
	int bit;
	int ans = 0;
	for(int i = 32; i>=0 ;--i){
		bit = bs[i];
		if(root->children[bit^1] == NULL){
			root = root->children[bit];
		}
		else {	
			ans |= (1<<i);
			root = root->children[bit^1];
		}
	}
	return ans;
}

void insert(Trie* root, int a){
	bitset<33> bs(a);
	int bit;
	for(int i=32; i>=0; --i){
		bit = bs[i];
		if(root->children[bit] == NULL){
			root->children[bit] = new Trie;
		}
		root = root->children[bit];
	}
	return;
}

int findMaximumXOR(vector<int>& nums) {

	int ans = INT_MIN;
	int n = nums.size();
	Trie* root = new Trie;
	for(int i=0; i<n; ++i){
		insert(root, nums[i]);
		ans = max(ans, xor_(root, nums[i]));
	}

	return ans;
}
    


int main(){
	int n; cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;++i) cin>>nums[i];
	cout<<findMaximumXOR(nums)<<endl;
	return 0;
}