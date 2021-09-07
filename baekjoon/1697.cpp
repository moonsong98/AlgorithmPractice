#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	vector<int> visited(100000, false);
	queue<pair<int, int>> q;
	visited[n]=true;
	q.push({n,0});
	while(!q.empty()) {
		int cur=q.front().first, dist=q.front().second; q.pop();
		if(cur==k) {
			cout << dist << '\n';
			return 0;
		}
		if(0<=cur+1&&cur+1<=100000&&!visited[cur+1]) {
			visited[cur+1]=true;
			q.push({cur+1,dist+1});
		}
		if(0<=cur-1&&cur-1<=100000&&!visited[cur-1]) {
			visited[cur-1]=true;
			q.push({cur-1,dist+1});
		}
		if(0<=cur*2&&cur*2<=100000&&!visited[cur*2]) {
			visited[cur*2]=true;
			q.push({cur*2,dist+1});
		}
	}
}