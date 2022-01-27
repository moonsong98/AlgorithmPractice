#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int N, K; cin >> K >> N;
	vector<int> rank(N+1);
	vector<vector<int>> comp(N, vector<int>(N));
	for(int i=1; i<=N; ++i) {
		int a; cin >> a; rank[a]=i;
		
	}
	for(int i=1; i<=N; ++i) for(int j=i+1; j<=N; ++j) comp[i][j]=rank[i]<rank[j];
	for(int k=1; k<K; ++k) {
		for(int i=1; i<=N; ++i) {
			int a; cin >> a; rank[a]=i;
		}
		for(int i=1; i<=N; ++i) for(int j=i+1; j<=N; ++j) comp[i][j]=(comp[i][j]==rank[i]<rank[j]?comp[i][j]:-1);
	}
	int ans=0;
	for(int i=1; i<=N; ++i) for(int j=i+1; j<=N; ++j) ans+=comp[i][j]!=-1;
	cout << ans << '\n';
}