#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n, m; cin >> n >> m;
	vector<vector<bool>> chosenWith(n+1, vector<bool>(n+1, false));
	for(int i=0; i<m; ++i) {
		int a, b;
		cin >> a >> b;
		if(a>b) chosenWith[a][b]=true;
		else chosenWith[b][a]=true;
	}
	vector<int> pastures(n+1, -1);
	for(int i=1; i<=n; ++i) {
		vector<bool> taken(5, false);
		for(int j=1; j<i; ++j) if(chosenWith[i][j] && pastures[j]!=-1) taken[pastures[j]]=true;
		for(int j=1; j<=4; ++j) if(!taken[j]) {
			pastures[i]=j;
			break;
		}
	}
	for(int i=1; i<=n; ++i) cout << pastures[i];
	cout << '\n';
}