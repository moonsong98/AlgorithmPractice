#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<vector<int>> adj[2];
set<int> possibleD[2];
const int INF=987654321;
int N, M;

void search(vector<int>& tmp, int p) {
	if(tmp.back()==N) {
		int sum=0;
		for(int i=0; i+1<tmp.size(); ++i) sum+=adj[p][tmp[i]][tmp[i+1]];
		possibleD[p].insert(sum);
		return;
	}
	for(int j=tmp.back()+1; j<=N; ++j)
		if(adj[p][tmp.back()][j]!=-1) {
			tmp.push_back(j);
			search(tmp,p);
			tmp.pop_back();
		}
}

int main(void) {
	cin >> N >> M;
	
	adj[0]=vector<vector<int>>(N+1, vector<int>(N+1,-1));
	adj[1]=vector<vector<int>>(N+1, vector<int>(N+1,-1));

	for(int i=0; i<M; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		adj[0][a][b]=c;
		adj[1][a][b]=d;
	}
	
	vector<int> tmp(1,1);
	search(tmp, 0);
	tmp=vector<int>(1,1);
	search(tmp, 1);
	int ans=INF;
	for(auto it=possibleD[0].begin(); it!=possibleD[0].end(); ++it)
		if(possibleD[1].count(*it)!=0) ans=min(ans,*it);
	if(ans==INF) cout << "IMPOSSIBLE" << '\n';
	else cout << ans << '\n';
}