#include<iostream>
#include<vector>

using namespace std;

int parent[51];
vector<int> children[51];
int leaves[51];

void dfs(int node) {
	if(!children[node].size()) leaves[node] = 1;
	else {
		for(int i = 0; i < children[node].size(); ++i) {
			dfs(children[node][i]);
			leaves[node] += leaves[children[node][i]];
		}
	}
}

int main(void) {
	int n;
	int root, deleteNode;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> parent[i];
		if(parent[i] == -1)	
			root = i;
		else
			children[parent[i]].push_back(i);
	}
	dfs(root);
	
	cin >> deleteNode;
	if(deleteNode == root)
		cout << 0 << endl;
	else
		cout << leaves[root] - leaves[deleteNode] + (children[parent[deleteNode]].size() == 1 ? 1 : 0) << endl;
}