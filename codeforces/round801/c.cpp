#include<bits/stdc++.h>
using namespace std;

int main(void) {
	int t; cin >> t;
	while(t--) {
		int n, m; cin >> n >> m;
		vector<vector<bool>> b(n+1, vector<bool>(m+1, false));
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=m; ++j) {
				int n; cin >> n;
				if(n==1)
					b[i][j]=1;
			}
		if((n+m)%2==0) {
			cout << "No" << '\n';
			continue;
		}
		vector<vector<vector<bool>>> cache(2, vector<vector<bool>>(m+1, vector<bool>(1001, false)));
		cache[1][1][b[1][1]]=true;
		for(int i=2; i<=m; ++i)
			for(int j=0; j<=1000; ++j) {
				if(b[1][i] && j>0)
					cache[1][i][j]=cache[1][i-1][j-1];
				else if(b[1][i]==0)
					cache[1][i][j]=cache[1][i-1][j];
			}
		for(int i=2; i<=n; ++i) {
			for(int j=1; j<=m; ++j) for(int k=0; k<=1000; ++k) cache[i%2][j][k]=false;
			for(int j=0; j<=1000; ++j) {
				if(b[i][1] && j>0)
					cache[i%2][1][j]=cache[(i-1)%2][1][j-1];
				else if(b[i][1]==0)
					cache[i%2][1][j]=cache[(i-1)%2][1][j];
			}
			for(int j=2; j<=m; ++j) {
				for(int k=0; k<=1000; ++k) {
					if(b[i][j] && k>0) {
						cache[i%2][j][k]=(cache[i%2][j-1][k-1]||cache[(i-1)%2][j][k-1]);
					}
					else if(b[i][j]==0) {
						cache[i%2][j][k]=(cache[i%2][j-1][k]||cache[(i-1)%2][j][k]);
					}
				}
			}
		}
		cout << (cache[n%2][m][(n+m)/2]?"Yes":"No") << '\n';
	}
}