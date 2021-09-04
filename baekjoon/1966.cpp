#include<iostream>
#include<queue>
#include<utility>

using namespace std;

int main(void) {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		queue<pair<int, int>> q;
		int cnt[10]={0,};
		cin >> n >> m;
		for(int i=0; i<n; ++i) {
			int p;
			cin >> p;
			q.push({i, p});
			cnt[p]++;
		}
		int nextP=9;
		int count = 0;
		while(true) {
			for(nextP; cnt[nextP]==0; --nextP);
			if(q.front().first==m && q.front().second==nextP) {
				++count;
				cout << count << '\n';
				break;
			}
			if(q.front().second < nextP) {
				q.push(q.front());
				q.pop();
			}
			else {
				++count;
				cnt[q.front().second]--;
				q.pop();
			}
		}
	}
}