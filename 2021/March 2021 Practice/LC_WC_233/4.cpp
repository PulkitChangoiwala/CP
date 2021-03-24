class Trie{
public:
	int count;
	vector<Trie*> children;
	Trie(){
		count = 0;
		children.resize(2, NULL);
	}
};


class Solution {
public:

void insert(Trie* root, int num){
	bitset<33> bs(num);
	int bit;
	for(int i =32; i>=0; --i){
		bit = bs[i];
		if(root->children[bit] == NULL){
			root->children[bit] = new Trie;
		}
		root = root->children[bit];
		root->count++;
	}
	return;
}

int xor_range(Trie* root, int k, int num){ //returns number of pairs with num as one element having xor strictly less than k
	bitset<33> bs(num);
	bitset<33> bsk(k);
	int bit, bitk;
	int ans = 0;
	for(int i = 32; i>=0; --i){
		if(!root) break;
		bit = bs[i];
		bitk = bsk[i];
		if(bitk == 0){
			root = root->children[bit];
		}
		else {
			if(root->children[bit]) {ans += root->children[bit]->count;}
			root = root->children[bit^1];
		}

	/*	
		if( (1ll<<i) <= k){
			if(root->children[bit]) ans += root->children[bit]->count;
			root = root->children[bit^1];
			k -= (1ll<<i);
		}
		else{
			root = root->children[bit];
		}*/
	}
	return ans;
}

int countPairs(vector<int>& nums, int low, int high) {
    Trie* root= new Trie;
    int n = nums.size();/*
    for(int i = 0; i<n; ++i){
    	
    }*/
    int ans_l = 0, ans_h = 0;
    for(int i=0; i<n; ++i){
    	insert(root, nums[i]);
    	ans_l += xor_range(root, low, nums[i]);
    	ans_h += xor_range(root, high+1, nums[i]);
    }
    return (ans_h - ans_l);

}


};