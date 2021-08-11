int n,m;
v(v(int)) adj;
int start, End;
v(int) color;
v(int) parent;
 
void detect_cycle(int s){
	
	if(End) return;
	color[s] = 1; //grey
	for(auto v : adj[s]){
		if(v!=parent[s] && color[v] == 1 ){
			End = 1;
			v(int) cycle;
			cycle.pb(v);

			int start = v;
			v = s;
			while(v!=start){
				cycle.pb(v);
				v = parent[v];

			}
			cycle.pb(v);
			cout<<cycle.size()<<endl;
			fr(i,0,cycle.size()){
				cout<<cycle[i]<<" ";
			}
			return;

		}
		if(color[v] == 0) {
			parent[v] = s;
			detect_cycle(v);
			if(End) return;
		}

	}
	color[s] = 2;

return;

}