#include<bits/stdc++.h>
using namespace std;
//https://www.quora.com/q/threadsiiithyderabad/Tutorial-on-Trie-and-example-problems
class Trie {
	public:
	int count;
	vector<Trie*> next;
	Trie(){
		count = 0;
		next.resize(27,NULL);
	}
};

void insert(string st, Trie* curr_node){
	int ind;
	string s = st + '#'; //# is EOL Character
	for(auto c : s){
		curr_node->count++;
		if(c == '#') ind = 26;
		else ind = c - 'a';
		if(curr_node->next[ind]!=NULL){ //considering a to z alphabets
			curr_node = curr_node->next[ind];
		}
		else {
			curr_node->next[ind] = new Trie;
			curr_node = curr_node->next[ind];
		}
	}

	return;
}

int search(string s, Trie* root){
	if(root == NULL) return -1;
	for(auto c : s){
		if(root->next[c-'a']!=NULL){
			root = root->next[c-'a'];
		}
		else {
			return -1;
		}
	}
	return root->count;
}
void print(Trie* root, string out){
	if(root->next[26]) {
		cout<<out<<endl;
	}

	for(int i=0;i<26;++i){
		char c = i + 'a';
		if(root->next[i])
			print(root->next[i], out+c);
	}
	return;
}
int main(){
	Trie* root = new Trie;

	insert("pulkit", root);
	insert("pulki", root);
	insert("pulk", root);
	insert("pul", root);
	insert("pu", root);
	insert("p", root);

	insert("pulkitchangoiwala", root);
	insert("pulkitchangoiwala", root);
	cout<<search("pulkitchangoiwala", root)<<endl;
	print(root, "");
	return 0;
}