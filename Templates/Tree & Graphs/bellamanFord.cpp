
bool bellaman_ford(int s){
 
	int u,v,w, max_itr = 0;
	bool is_changed = 0;
	dis.clear();
	dis.resize(n+1, inf);
	dis[s] = 0;
 
	while(1){
		is_changed = 0;
		for(int i=0;i<m;++i){
			u = edges[i][0];
			v = edges[i][1];
			w = edges[i][2];
			if(dis[v] > dis[u]+w){
				dis[v] = dis[u]+w;
				is_changed  = 1;
			}
			
		}
		max_itr++;
 
		if(!is_changed ||  max_itr == n) break;
	}
 
 
	//detect cycle
	is_changed  = 0;
 
	for(int i=0;i<m;++i){
			u = edges[i][0];
			v = edges[i][1];
			w = edges[i][2];
			if(dis[u]!=inf  && dis[v] > dis[u]+w){
				dis[v] = dis[u]+w;
				//insert vertices whose distance is changed into set
				st.insert(v);
				is_changed  = 1;
				}
 
	}
	return is_changed;
}