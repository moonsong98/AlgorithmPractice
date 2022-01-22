#include<iostream>

using namespace std;

int adjCowsNums[1001][1001];
bool isCow[1001][1001];
int dy[]={-1,0,1,0}, dx[]={0,1,0,-1};

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, cnt=0; cin >> n;
	for(int i=0; i<n; ++i) {
		int y, x; cin >> y >> x;
		isCow[y][x]=true;
		if(adjCowsNums[y][x]==3) cnt++;
		for(int k=0; k<4; ++k) {
			int ny=y+dy[k], nx=x+dx[k];
			if(0<=ny&&ny<=1000&&0<=nx&&nx<=1000) {
				if(adjCowsNums[ny][nx]==3&&isCow[ny][nx]) --cnt;
				adjCowsNums[ny][nx]++;
				if(adjCowsNums[ny][nx]==3&&isCow[ny][nx]) ++cnt;
			}
		}	
		cout << cnt << '\n';	
	}
}