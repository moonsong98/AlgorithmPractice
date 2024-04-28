#include<iostream>
#include<utility>

using namespace std;
pair<int, int> adj[26];

void print(int node, int mode) {
	if(mode == 0) cout << (char)(node + 'A');
	if(adj[node].first != -1) print(adj[node].first, mode);
	if(mode == 1) cout << (char)(node + 'A');
	if(adj[node].second != -1) print(adj[node].second, mode);
	if(mode == 2) cout << (char)(node + 'A');
}

int main(void) {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		char a;
		char l, r;
		cin >> a >> l >> r;
		l = (l == '.' ? -1 : l - 'A');
		r = (r == '.' ? -1 : r - 'A');
		adj[a-'A'] = {l, r};
	}
	for(int i = 0; i < 3; ++i){
		print(0, i);
		cout << endl;
	}
}