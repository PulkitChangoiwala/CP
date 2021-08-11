#include<bits/stdc++.h>
using namespace std;

/*****************************************
****************************************
Fenwick Tree for One Dimensional Arrays
****************************************
****************************************/
class fenwickTree_sum{

	vector<int> bit;
	vector<int> a;
	int n;
public:
	fenwickTree_sum(int n){
		this->n = n; //One-Based Indexing
		bit.assign(n, 0);
	}

	fenwickTree_sum(vector<int> &a) : fenwickTree_sum(a.size()){ //input array is one-indexed
		
		//constructing fenTree using given array
		//bit[k] =  sum(k-p(k)+1, k)
		for(int k = 1; k<n; ++k){
				modify_sum(k,a[k]);
			}			

	}

	int sum(int k){ //return sum(1,k)
		int res = 0;
		while(k>=1){
			res = res + bit[k];
			//p(k) = 2^(last set bit)  
			int pk = k&(-k);
			k -= pk;
		}
		return res;
	}

	void modify_sum(int k, int x){ //Kth element is increased by x

		while(k<n){
			bit[k] +=x;
			int pk = k &(-k);
			k += pk;
		}
		return;

	}

	void print(){
		for(int i =1; i<n;++i){
		cout<<bit[i]<<" ";
	}
	cout<<endl; 
	return;
	}



};



class fenwickTree_min{

	vector<int> bit;
	int n;
public:
	fenwickTree_min(int n){
		this->n = n; //One-Based Indexing
		bit.assign(n, INT_MAX);
	}

	fenwickTree_min(vector<int> &a) : fenwickTree_min(a.size()){ //input array is one-indexed
		
		//constructing fenTree using given array
		//bit[k] =  sum(k-p(k)+1, k)
		for(int k = 1; k<n; ++k){
				modify_min(k,a[k]);
			}	

	}

	int minimum(int k){ //return minimum(1,k)
		int res = INT_MAX;
		while(k>=1){
			res = min(res,bit[k]);
			//p(k) = 2^(last set bit)  
			int pk = k&(-k);
			k -= pk;
		}

		return res;
	}

	void modify_min(int k, int x){ //new value of kth element is x

		while(k<n){
			bit[k] = min(bit[k], x);
			int pk = k &(-k);
			k += pk;
		}
		return;

	}
	void print(){
		for(int i =1; i<n;++i){
		cout<<bit[i]<<" ";
	}
	cout<<endl; 
	return;
	}



};



class fenwickTree_max{

	vector<int> bit;
	int n;
public:
	fenwickTree_max(int n){
		this->n = n; //One-Based Indexing
		bit.assign(n, INT_MIN);
	}

	fenwickTree_max(vector<int> &a) : fenwickTree_max(a.size()){ //input array is one-indexed
		
		//constructing fenTree using given array
		//bit[k] =  sum(k-p(k)+1, k)
		for(int k = 1; k<n; ++k){
				modify_max(k,a[k]);
			}			

	}

	int maximum(int k){ //return minimum(1,k)
		int res = INT_MIN;
		while(k>=1){
			res = max(res,bit[k]);
			//p(k) = 2^(last set bit)  
			int pk = k&(-k);
			k -= pk;
		}

		return res;
	}

	void modify_max(int k, int x){ //new value of kth element is x

		while(k<n){
			bit[k] = max(bit[k], x);
			int pk = k &(-k);
			k += pk;
		}
		return;

	}
	void print(){
		for(int i =1; i<n;++i){
		cout<<bit[i]<<" ";
	}
	cout<<endl; 
	return;
	}



};



//Combined

class fenwickTree{

	vector<int> bit;
	int n;
	int type;
public:
	
	fenwickTree(int n, int type){
		this->n = n; //One-Based Indexing
		this->type = type; //type = 0 => sum || type = 1 => min || type = 2 => max
		
		bit.assign(n, initialValue());
	}

	fenwickTree(vector<int> &a, int type) : fenwickTree(a.size(), type){ //input array is one-indexed
		
		//constructing fenTree using given array
		//bit[k] =  sum(k-p(k)+1, k)
		for(int k = 1; k<n; ++k){
				modify(k,a[k]);
			}	

	}

	int initialValue(){
		if(type==0) return 0;
		else if(type == 1) return INT_MAX;
		else if(type == 2) return INT_MIN;
		else return 0;
	}

	int operation(int a, int b){
		if(type==0) return a+b;
		else if(type == 1) return min(a,b);
		else if(type == 2) return max(a,b);	
		else return 0;
	}

	int query(int k){ //return operation(1,k)
		int res = initialValue();
		while(k>=1){
			res = operation(res,bit[k]);
			int pk = k&(-k); //p(k) = 2^(last set bit)  
			k -= pk;
		}

		return res;
	}

	void modify(int k, int x){ 
	//x is new value of kth element after change, for min & max
 	//x is the changes in the kth element, for sum

		while(k<n){
			bit[k] = operation(bit[k], x);
			int pk = k &(-k);
			k += pk;
		}
		return;

	}

	void print(){
		for(int i =1; i<n;++i){
		cout<<bit[i]<<" ";
	}
	cout<<endl; 
	return;
	}



};





/*****************************************
****************************************
Fenwick Tree for Two Dimensional Arrays
****************************************
****************************************/

//Combined 2D

class fenwickTree2{

	vector<vector<int>> bit;
	int n,m;
	int type;
public:
	
	fenwickTree2(int n, int m, int type){
		this->n = n; //One-Based Indexing
		this->m = m; //One-Based Indexing
		this->type = type; //type = 0 => sum || type = 1 => min || type = 2 => max
		bit.assign(n, vector<int>(m,initialValue()));
	}

	fenwickTree2(vector<vector<int>> &a, int type) : fenwickTree2(a.size(), a[0].size(), type){ //input array is one-indexed
		
		//constructing fenTree using given array
		//bit[k] =  sum(k-p(k)+1, k)
		for(int i = 1; i<n; ++i){
			for(int j = 1; j<n; ++j){
				modify(i, j, a[i][j]);
			}
		}	

	}

	int initialValue(){
		if(type==0) return 0;
		else if(type == 1) return INT_MAX;
		else if(type == 2) return INT_MIN;
	}

	int operation(int a, int b){
		if(type==0) return a+b;
		else if(type == 1) return min(a,b);
		else if(type == 2) return max(a,b);	
	}

	int query(int x, int y){ //return operation sum of (1,x)(1,y)
		int res = initialValue();
		
		for(int i = x; i>=1; i-= i&(-i)){
			for(int j = y; j>=1; j-= j&(-j)){
				res = operation(res, bit[i][j]);
			}
		}
		return res;
	}

	void modify(int x, int y, int change){ 
	//x is new value of kth element after change, for min & max
 	//x is the changes in the kth element, for sum

		for(int i = x; i<n; i += i&(-i)){
			for(int j = y; j<m; j += j&(-j)){
				bit[i][j] = operation(bit[i][j], change);
			}
		}
		return;

	}

	void print(){
		for(int i =1; i<n;++i){
			for(int j =1; j<m;++j){
				cout<<bit[i][j]<<" ";
			}
		cout<<endl; 
		}

	return;
	}



};




/*****************************************
****************************************
Main
****************************************
****************************************/

int main(){

	vector<int> a = {0,1,3,4,8,6,1,4,2};
	fenwickTree_sum f(a);
	f.print();
	fenwickTree_min f1(a);
	f1.print();
	fenwickTree_max f2(a);
	f2.print();
	
	fenwickTree f3(a,0), f4(a,1), f5(a,2);
	f3.print();
	f4.print();
	f5.print();
	cout<<endl;

	vector<vector<int>> a2 = { 
							{0,0,0,0,0,0},	
							{0,1,3,4,8,6},
							{0,1,3,4,8,6},
							{0,1,3,4,8,6},
							{0,1,3,4,8,6},
							{0,1,3,4,8,6},
							{0,1,3,4,8,6}
							
						};
	fenwickTree2 f6(a2,0), f7(a2,1), f8(a2,2);
	f6.print();
	cout<<endl;
	f7.print();
	cout<<endl;
	f8.print();
	return 0;
}