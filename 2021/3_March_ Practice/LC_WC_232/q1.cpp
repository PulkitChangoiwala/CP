bool areAlmostEqual(string s1, string s2) {
	int n1 = s1.length();
	int n2 = se.length();        
	if(n1!=n2) return 0;
	vector<int> v;
	for(int i=0;i<n1;++i){
		if(s1[i]!=s2[i]) v.push_back(i);
	}
	if(v.size()>2) return 0; 
	if(s1[v[0]] == s2[v[1]] && s1[v[1]]==s2[v[0]]) return 1;
	else return 0;
}