
//Adjancey Matrix
class Euler_Tour_{
	//euler tour is euler path which is cycle
	//euler path is a path in graph, which traverse through all edges only once
	int n,m;
	int v1,v2,first;
	vector<vector<int>> graph;
	vector<int> euler_path; //contains euler cycle if euler cycle exists
	vector<int> degree;
public:
	
	Euler_Tour_(int n, int m){
		this->n = n;
		this->m = m;
		this->v1 = -1;
		this->v2 = -1;
		this->first = 1;
		graph.resize(n+1, vector<int>(n+1,0));
		degree.resize(n+1,0);
	}

	void add_edge(int a, int b){
		graph[a][b]++;
	}

	void set_degree(){
		for(int i=1;i<=n;++i){
			for(int j=1; j<=n;++j){
				degree[i] += graph[i][j];
			}
		}
	}
	
	bool is_euler_cycle(){
		return v1 == -1;
	}
	bool is_eulerian(){
		//for(int i=1; i<=n; ++i){ if((degree[i])&1) return false;}
		//check all if all are zero
		while(first<=n && !degree[first]) first++;
		if(first == n+1) return false;
		return true;
	}

	bool is_euler_path(){
		int flag = true;
		for(int i=1; i<=n; ++i){ 
			if((degree[i])&1) {
				if(v1==-1) v1 = i;
				else if(v2 == -1) v2 = i;
				else {flag = false; break; }
			}
		}
		if(v1!=-1) { //Make eulerian path a eulerian cycle.
			graph[v1][v2]++;
			graph[v2][v1]++;
		}
		return flag;
	}

	bool euler_tour(){
		set_degree();
		if(!is_eulerian()) return false;
		if(!is_euler_path()) return false;

		//Now we have a euler circle. 
		stack<int> st;
		st.push(first);
		//Find Euler Cycle
		while(!st.empty()){
			int i, v = st.top();
			for(i=1; i<=n; ++i){
				if(graph[v][i]) 
					break;
			}
			if(i==n+1) {
				st.pop();
				euler_path.push_back(v);
			}
			else {
				--graph[v][i];
				--graph[i][v];
				st.push(i);
			}
			
		}

		//Storing Euler Path, if Euler cycle does not exist

		if(v1 != -1){
			vector<int> temp;
			for(int i=1; i+1<=n; ++i){
				//detect edge v1-v2
				if((euler_path[i]==v1 && euler_path[i+1]==v2) || (euler_path[i]==v2 && euler_path[i+1]==v1)){
					for(int j=i+1; j<=n; ++j) temp.push_back(euler_path[j]);
					for(int j=2; j<=i;++j) temp.push_back(euler_path[j]);
				}
			}
			euler_path.clear();
			euler_path = temp;
		}

		//Check if any edge is remaining
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n;++j){
				if(graph[i][j])
					return false;
			}
		}

		return true;

	}

	void print(){
		for(auto v : euler_path){
			cout<<v<<" ";
		}
		cout<<endl;
	}
};




//Adjancey List
class Euler_Tour{
	//euler tour is euler path which is cycle
	//euler path is a path in graph, which traverse through all edges only once
	int n,m;
	int v1,v2,first;
	vector<set<int>> graph;
	vector<int> euler_path; //contains euler cycle if euler cycle exists
	vector<int> degree;
public:
	
	Euler_Tour(int n, int m){
		this->n = n;
		this->m = m;
		this->v1 = -1;
		this->v2 = -1;
		this->first = 1;
		graph.resize(n+1);
		degree.resize(n+1,0);
	}

	void add_edge(int a, int b){
		graph[a].insert(b);
	}

	void set_degree(){
		for(int i=1;i<=n;++i){ degree[i] = graph[i].size();}
	}
	
	bool is_euler_cycle(){
		return v1 == -1;
	}
	void dfs(int s, vector<bool> & vis){
		vis[s] = true;
		for(auto v : graph[s]) if(!vis[v]) dfs(v, vis);
	}
	bool is_connected(){
		vector<bool> vis(n+1);
		dfs(1, vis);
		for(int i=1; i<=n;++i){
			if(!vis[i] && graph[i].size()) return false;
		}
		return true;
	}
	bool is_eulerian(){
		for(int i=1; i<=n; ++i){ if((degree[i])&1) return false;}
	}

	bool is_euler_path(){
		int flag = is_connected();
		if(!flag) return flag;

		//check all if all are zero
		while(first<=n && !degree[first]) first++;
		if(first == n+1) return false;
		
		
		for(int i=1; i<=n; ++i){ 
			if((degree[i])&1) {
				if(v1==-1) v1 = i;
				else if(v2 == -1) v2 = i;
				else {flag = false; break; }
			}
		}
		if(v1!=-1) { //Make eulerian path a eulerian cycle.
			graph[v1].insert(v2);
			graph[v2].insert(v1);
		}
		return flag;
	}

	bool euler_tour(){
		set_degree();
		if(!is_euler_path()) return false;

		//Now we have a euler circle. 
		stack<int> st;
		st.push(first);
		//Find Euler Cycle
		while(!st.empty()){
			int v = st.top();
			int i;
			if(graph[v].size()==0) {
				st.pop();
				euler_path.push_back(v);
			}
			else {
				i = *(graph[v].begin());
				graph[v].erase(i);
				graph[i].erase(v);
				st.push(i);
			}
			
		}

		//Storing Euler Path, if Euler cycle does not exist

		if(v1 != -1){
			vector<int> temp;
			for(int i=1; i+1<=n; ++i){
				//detect edge v1-v2
				if((euler_path[i]==v1 && euler_path[i+1]==v2) || (euler_path[i]==v2 && euler_path[i+1]==v1)){
					for(int j=i+1; j<=n; ++j) temp.push_back(euler_path[j]);
					for(int j=2; j<=i;++j) temp.push_back(euler_path[j]);
				}
			}
			euler_path.clear();
			euler_path = temp;
		}

		return true;

	}

	void print(){
		for(auto v : euler_path){
			cout<<v<<" ";
		}
		cout<<endl;
	}
};
