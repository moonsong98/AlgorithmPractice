#include<iostream>
#include<vector>
#include<utility>
#include<cstdlib>
#include<algorithm>

using namespace std;

int n;
vector<pair<int,int> > points;
vector<vector<int> > dp;

int dist(int u, int v, int startPoint) {
	int y1, x1, y2, x2;
	if(u==0) {
		if(startPoint) {
			y1=n; x1=n;
		}
		else {
			y1=1; x1=1;
		}
	}
	else {
		y1=points[u-1].first;
		x1=points[u-1].second;
	}
	y2=points[v-1].first;
	x2=points[v-1].second;
	return abs(y2-y1) + abs(x2-x1);
}

int main(void) {
	int numPoints; cin >> n >> numPoints;
	points=vector<pair<int,int> >();
	dp=vector<vector<int> >(numPoints+1, vector<int>(numPoints+1, 0));
	for(int i=0; i<numPoints; ++i) {
		int y, x; cin >> y >> x;
		points.push_back({y, x});
	}
	for(int i=1; i<=numPoints; ++i) {
		for(int j=0; j<i; ++j) {
			if(j+1==i && j>0) {
				dp[i][j]=dp[j][i]=987654321;
				for(int k=0; k<j; ++k) dp[i][j]=min(dp[i][j], dp[k][j]+dist(k,i,0));
				for(int k=0; k<j; ++k) dp[j][i]=min(dp[j][i], dp[j][k]+dist(k,i,1));
			}
			else {
				dp[i][j]=dp[i-1][j]+dist(i-1,i,0);
				dp[j][i]=dp[j][i-1]+dist(i-1,i,1);
			}
		}
	}
	int ans=987654321, y, x;
	vector<int> path;
	for(int i=0; i<numPoints; ++i)  {
		if(ans>dp[i][numPoints]) {
			ans=dp[i][numPoints];
			y=i; x=numPoints;
		}
		if(ans>dp[numPoints][i]) {
			ans=dp[numPoints][i];
			y=numPoints; x=i;
		}
	}
	cout << ans << '\n';
	while(y > 0 || x > 0) {
		if(y>x) {
			if(y>x+1 || x==0) {
				path.push_back(1);
				y--;
			}
			else {
				for(int i=0; i<x; ++i) 
					if(dp[i][x]+dist(i,y,0)==dp[y][x]) {
						path.push_back(1);
						y=i;
						break;
					}
			}
		}
		else {
			if(x>y+1 || y == 0) {
				path.push_back(2);
				x--;
			}
			else {
				for(int i=0; i<y; ++i) 
					if(dp[y][i]+dist(i,x,1)==dp[y][x]) {
						path.push_back(2);
						x=i;
						break;
					}
			}
		}
	}
	reverse(path.begin(), path.end());
	for(int p: path) cout << p << '\n';
}