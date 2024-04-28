#include<iostream>
#include<vector>
#include<utility>

using namespace std;

vector<vector<int>> b;
vector<vector<vector<long long>>> dp;
int dir[3][2]={{0,1},{1,0}, {1,1}};
int n;

void debug() {
	for(int i=0; i<3; ++i) {
		cout << "state: " << i << '\n';
		for(int j=0; j<n; ++j) {
			for(int k=0; k<n; ++k)
				cout << dp[j][k][i] << ' ';
			cout << '\n';
		}
	}
}

bool valid(int y, int x, int state) {
	if(!(0<=y&&y<n&&0<=x&&x<n)) return false;
	if(state!=2) return !b[y][x];
	else return !(y<=0 || x<=0 ||b[y][x] || b[y-1][x] || b[y][x-1]);
}

long long solution(int y, int x, int state) {
	if(y==n-1&&x==n-1) return 1;
	
	long long& ret=dp[y][x][state];
	if(ret!=-1) return ret;
	
	ret=0;
	for(int i=0; i<3; ++i) {
		if(state!=2 && state+i==1) continue;
		int nextY=y+dir[i][0], nextX=x+dir[i][1];
		if(valid(nextY, nextX, i)){
			ret += solution(nextY, nextX, i);
		}
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);	
	cin >> n;
	b=vector<vector<int>>(n,vector<int>(n));
	dp=vector<vector<vector<long long>>> (n, vector<vector<long long>>(n, vector<long long>(3, -1)));
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cin >> b[i][j];
	cout << solution(0,1,0) << '\n';
	// debug();
}