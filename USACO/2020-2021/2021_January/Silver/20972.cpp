#include<bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> pts;

//0:ul 1:ur 2:ll 3: lr
int getMax(vector<vector<bool>> &taken, int y, int x) {
	int placed=0, ret=0, ny=(x==N-1?y+1:y), nx=(x==N-1?0:x+1);
	if(taken[y][x]) placed+=1;
	if(taken[y][x+1]) placed+=2;
	if(taken[y+1][x]) placed+=4;
	if(taken[y+1][x+1]) placed+=8;
	
	if(y==N-1&&x==N-1) {
		if(placed==3||placed==5||placed==6||placed==9||placed==10||placed==12) return 0;
		if(placed==1) return max({pts[y][x+1], pts[y+1][x], pts[y+1][x+1]});
		if(placed==2) return max({pts[y][x], pts[y+1][x], pts[y+1][x+1]});
		if(placed==4) return max({pts[y][x], pts[y][x+1], pts[y+1][x+1]});
		if(placed==8) return max({pts[y][x], pts[y][x+1], pts[y+1][x]});
		return max({pts[y][x]+max({pts[y][x+1], pts[y+1][x], pts[y+1][x+1]}), pts[y][x+1]+max(pts[y+1][x], pts[y+1][x+1]), pts[y+1][x]+pts[y+1][x+1]});
	}
	if(placed==3||placed==5||placed==6||placed==9||placed==10||placed==12)
		return getMax(taken, ny, nx);
	
	if(placed==0) {
		taken[y][x]=taken[y+1][x]=true;
		ret=max(ret, pts[y][x]+pts[y+1][x]+getMax(taken, ny, nx));
		taken[y][x]=taken[y+1][x]=false;
		taken[y][x]=taken[y][x+1]=true;
		ret=max(ret, pts[y][x]+pts[y][x+1]+getMax(taken, ny, nx));
		taken[y][x]=taken[y][x+1]=false;
		taken[y][x]=taken[y+1][x+1]=true;
		ret=max(ret, pts[y][x]+pts[y+1][x+1]+getMax(taken, ny, nx));
		taken[y][x]=taken[y+1][x+1]=false;
		taken[y][x+1]=taken[y+1][x]=true;
		ret=max(ret, pts[y][x+1]+pts[y+1][x]+getMax(taken, ny, nx));
		taken[y][x+1]=taken[y+1][x]=false;
		taken[y][x+1]=taken[y+1][x+1]=true;
		ret=max(ret, pts[y][x+1]+pts[y+1][x+1]+getMax(taken, ny, nx));
		taken[y][x+1]=taken[y+1][x+1]=false;
		taken[y+1][x]=taken[y+1][x+1]=true;
		ret=max(ret, pts[y+1][x]+pts[y+1][x+1]+getMax(taken, ny, nx));
		taken[y+1][x]=taken[y+1][x+1]=false;
	}
	if(placed==1||placed==2||placed==4) {
		taken[y+1][x+1]=true;
		ret=max(ret, pts[y+1][x+1]+getMax(taken, ny, nx));
		taken[y+1][x+1]=false;
	}
	if(placed==1||placed==2||placed==8) {
		taken[y+1][x]=true;
		ret=max(ret, pts[y+1][x]+getMax(taken, ny, nx));
		taken[y+1][x]=false;
	}
	if(placed==1||placed==4||placed==8) {
		taken[y][x+1]=true;
		ret=max(ret, pts[y][x+1]+getMax(taken, ny, nx));
		taken[y][x+1]=false;
	}
	if(placed==2||placed==4||placed==8) {
		taken[y][x]=true;
		ret=max(ret, pts[y][x]+getMax(taken, ny, nx));
		taken[y][x]=false;
	}
	return ret;
}

int main(void) {
	cin >> N;
	pts=vector<vector<int>>(N, vector<int>(N));
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) cin >> pts[i][j];
	vector<vector<bool>> taken(N, vector<bool>(N, false));
	
	int ans=0;
	taken[y][x]=taken[y+1][x]=true;
	ans=max(ans, pts[y][x]+pts[y+1][x]+getMax(taken, 0, 1));
	taken[y][x]=taken[y+1][x]=false;
	taken[y][x]=taken[y][x+1]=true;
	taken[y][x]=taken[y][x+1]=false;
	ans=max(ans, pts[y][x]+pts[y+1][x]+getMax(taken, 0, 1));
	taken[y][x]=taken[y+1][x+1]=true;
	ans=max(ans, pts[y][x]+pts[y+1][x+1]+getMax(taken, 0, 1));
	taken[y][x]=taken[y+1][x+1]=false;
	taken[y][x+1]=taken[y+1][x]=true;
	ans=max(ans, pts[y][x+1]+pts[y+1][x]+getMax(taken, 0, 1));
	taken[y][x+1]=taken[y+1][x]=false;
	taken[y][x+1]=taken[y+1][x+1]=true;
	ans=max(ans, pts[y][x+1]+pts[y+1][x+1]+getMax(taken, 0, 1));
	taken[y][x+1]=taken[y+1][x+1]=false;
	taken[y+1][x]=taken[y+1][x+1]=true;
	ans=max(ans, pts[y+1][x]+pts[y+1][x+1]+getMax(taken, 0, 1));
	taken[y+1][x]=taken[y+1][x+1]=false;
	cout << ans << '\n';
}