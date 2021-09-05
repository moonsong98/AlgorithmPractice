#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> words[26][26];
int indegree[26], outdegree[26], adj[26][26];
int numWords;
vector<int> ans;


void init() {
	ans=vector<int>();
	for(int i=0; i<26; ++i) {
		indegree[i]=outdegree[i]=0;
		for(int j=0; j<26; ++j) {
			words[i][j]=vector<string>();
			adj[i][j]=0;
		}
	}
}

void makeGraph() {
	cout << "hihi" << '\n';
	cin >> numWords;
	cout << numWords << '\n';
	for(int i=0; i<numWords; ++i) {
		cout << i << '\n';
		string str;
		cin >> str;
		int u=str[0]-'a', v=str[str.size()-1]-'a';
		indegree[u]++;outdegree[v]++;adj[u][v]++;numWords++;words[u][v].push_back(str);
	}
}

void dfs(int here) {
	for(int there=0; there<26; ++there) 
		while(adj[here][there]>0) {
			adj[here][there]--;
			numWords--;
			dfs(there);
		}
	ans.push_back(here);
}

void debug() {
	cout << "$$$$$$$$$$$$$$$ REACHED HERE $$$$$$$$$$$$$$$$" << '\n';
}

void solution() {
	debug();
	init();
	debug();
	makeGraph();
	/*
	debug();
	int start=-1, end=-1;
	bool impossible=false;
	for(int i=0; i<26; ++i){
		int diff=indegree[i]-outdegree[i];
		switch(diff) {
			case 0: break;
			case 1:
				if(start!=-1) impossible=true;
				start=i;
				break;
			case -1:
				if(end!=-1) impossible=true;
				end=i;
				break;
			default:
				impossible=true;
				break;
		}
		if(impossible){
			cout << "IMPOSSIBLE" << '\n';
			return;
		} 
	}
	if(start==-1 && end!=-1 || start!=-1 && end==-1){
		cout << "IMPOSSIBLE" << '\n';
		return;
	} 
	if(start != -1) {
		for(int i=0; i<26; ++i) 
			if(indegree[i] > 0) {
				dfs(i);
				break;
			}
	} else {
		dfs(start);
	}
	
	if(numWords>0) {
		cout << "IMPOSSIBLE" << '\n';
		return;
	} 
		
	for(int i=0; i+1<ans.size(); ++i) {
		int u=ans[i], v=ans[i+1];
		cout << words[u][v].back() << ' ';
		words[u][v].pop_back();
	}
	cout << '\n';
	*/
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	while(t--) solution();
}