#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n, m;
	int ans=-987654321;
	cin >> n >> m;
	
	vector<vector<int>> pSum(n+1, vector<int>(m+1));
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
		cin >>pSum[i][j];
		pSum[i][j]+=pSum[i][j-1];
	}
	
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
		pSum[i][j]+=pSum[i-1][j];
	}
	
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) for(int p=0; p<i; ++p) for(int q=0; q<j; ++q)
		ans=max(pSum[i][j]-pSum[p][j]-pSum[i][q]+pSum[p][q], ans);
	
	cout << ans << '\n';
}