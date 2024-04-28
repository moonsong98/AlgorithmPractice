#include<iostream>
#include<cstring>

using namespace std;

char board[1001][1001];
int cache[1001][1001];
int horizontal[1001][1001];
int vertical[1001][1001];
int n, m;

int sqr(int num){
	return num*num;
}

int dfs(int y, int x){
	if(y==n||x==m) return 0;
	int& ret=cache[y][x]; 
	if(ret!=-1) return ret;
	if(board[y][x]=='0') return ret=0;
	ret=1;
	if(board[y+1][x+1]==0) return ret;
	int minSideLength=min(horizontal[y][x],vertical[y][x]);
	return ret=min(minSideLength,dfs(y+1,x+1)+1);
}

void countOnes(int n, int m) {
	for(int i=0; i<n; ++i) 
		for(int j=m-1; j>=0; --j){
			if(j==m-1) horizontal[i][j] = board[i][j] == '1';
			else
				horizontal[i][j] = (board[i][j] == '1' ? horizontal[i][j+1] + 1 : 0);
		}
	
	for(int i = 0; i < m; ++i) {
		for(int j = n-1; j >= 0; --j) {
			if(j == n-1) vertical[j][i] = board[j][i] == '1';
			else
				vertical[j][i] = (board[j][i] == '1' ? vertical[j+1][i] + 1 : 0);
		}
	}
}

int main(void) {
	cin.sync_with_stdio(false);
	memset(cache,-1,sizeof(cache));
	cin >> n >> m;
	for(int i = 0; i < n; ++i)	
		for(int j = 0; j < m; ++j)
			cin >> board[i][j];
	
	countOnes(n, m);
	
	int ans = -1;
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			ans=max(ans,sqr(dfs(i,j)));
	cout<<ans<<endl;
}