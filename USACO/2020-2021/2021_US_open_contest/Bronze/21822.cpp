#include<iostream>
#include<vector>

using namespace std;

int adjCow[4][2][2] = {
	{{-1, 0}, {0, 1}},
	{{-1, 0}, {0, -1}},
	{{1, 0}, {0, -1}},
	{{1, 0}, {0, 1}}
};

int diagGrass[4][2] = {
	{-1, 1},
	{-1, -1},
	{1, -1},
	{1, 1}
};

bool inBound(int n, int m, int y, int x) {
	return 0<=y&&y<n&&0<=x&&x<m;
}

int main(void) {
	int n, m; cin >> n >> m;
	vector<vector<char>> field(n, vector<char>(m));
	vector<vector<int>> grass(n, vector<int>(m,0));
	for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin >> field[i][j];
	for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) if(field[i][j]=='G') {
		if(0<i&&i<n-1) grass[i][j]=grass[i][j]||(field[i-1][j]=='C'&&field[i+1][j]=='C');
		if(0<j&&j<m-1) grass[i][j]=grass[i][j]||(field[i][j-1]=='C'&&field[i][j+1]=='C');
	}
	for(int r=0; r<n; ++r) for(int c=0; c<m; ++c) if(field[r][c]=='G') {
		if(grass[r][c]) continue;
		for(int i=0; i<4; ++i) {
			int cy1=r+adjCow[i][0][0], cy2=r+adjCow[i][1][0], cx1=c+adjCow[i][0][1], cx2=c+adjCow[i][1][1];
			int dy=r+diagGrass[i][0], dx=c+diagGrass[i][1];
			if(inBound(n, m, cy1, cx1) && inBound(n, m, cy2, cx2) && field[cy1][cx1]=='C' && field[cy2][cx2]=='C' && (grass[dy][dx]-2!=(i+2)%4)) {
				grass[r][c]=i+2;
				break;
			}
		}
	}
	
	int ans=0;
	for(int r=0; r<n; ++r) for(int c=0; c<m; ++c) ans+=grass[r][c]>0;
	cout << ans << '\n';
}