#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

vector<vector<char>> b;
vector<set<string>> ul, dr;
int N;
set<string> ans;

void dfs(string& cand, int y, int x, bool isUl) {
	if(y+x==N-1) {
		if(isUl) ul[y].insert(cand);
		else dr[y].insert(cand);
		return;
	}
	if(cand.size()<N) {
		if(isUl) {
			if(y+1<N) {
				cand.push_back(b[y+1][x]);
				dfs(cand,y+1,x,isUl);
				cand.pop_back();
			}
			if(x+1<N) {
				cand.push_back(b[y][x+1]);
				dfs(cand,y,x+1,isUl);
				cand.pop_back();
			}
		}
		else {
			if(y-1>=0) {
				cand.push_back(b[y-1][x]);
				dfs(cand,y-1,x,isUl);
				cand.pop_back();
			}
			if(x-1>=0) {
				cand.push_back(b[y][x-1]);
				dfs(cand,y,x-1,isUl);
				cand.pop_back();
			}
		}
	}
}

int main(void) {
	cin >> N;
	b=vector<vector<char>>(N, vector<char>(N));
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) cin >> b[i][j];
	ul=vector<set<string>>(N);
	dr=vector<set<string>>(N);
	string cand=string(1,b[0][0]);
	dfs(cand,0,0,true);
	cand=string(1,b[N-1][N-1]);
	dfs(cand,N-1,N-1,false);
	for(int i=0; i<N; ++i) {
		for(auto it=ul[i].begin(); it!=ul[i].end(); ++it)
			if(dr[i].count(*it)!=0) ans.insert(*it);
	}
	cout << ans.size() << '\n';
}