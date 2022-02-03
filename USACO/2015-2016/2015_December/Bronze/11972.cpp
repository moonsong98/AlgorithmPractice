#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int N,M,D,S,p,m,t,ans=0;
	cin >> N >> M >> D >> S;
	vector<vector<int>> firstDrink(N+1, vector<int>(M+1,-1));
	vector<int> cntCand(M+1, 0);
	vector<bool> isCand(M+1, 0);
	for(int i=0; i<D; ++i) {
		cin >> p >> m >> t;
		firstDrink[p][m]==-1 && (firstDrink[p][m]=t);
	}
	for(int i=0; i<S; ++i) {
		cin >> p >> t;
		for(int j=1; j<=M; ++j) if(firstDrink[p][j]!=-1 && firstDrink[p][j] < t) ++cntCand[j];
	}
	for(int i=1; i<=M; ++i) if(cntCand[i]==S) isCand[i]=true;
	for(int i=1; i<=M; ++i) if(isCand[i]) {
		int cnt=0;
		for(int a=1; a<=N; ++a) if(firstDrink[a][i]!=-1) ++cnt;
		ans=max(ans, cnt);
	}
	cout << ans << '\n';
}