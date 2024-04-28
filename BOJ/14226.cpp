#include<iostream>
#include<queue>
#include<utility>

using namespace std;

int main(void) {
	int s;
	cin >> s;
	
	priority_queue<pair<int,int>> pq;
	pq.push({0,1});	
	while(!pq.empty()) {
		int cost=-pq.top().first, cur=pq.top().second;
		pq.pop();
		if(cur==s) {
			cout << cost << '\n';
			break;
		}
		if(cur-1 >= 2) pq.push({-cost-1, cur-1});
		for(int i=2; cur*i <= 1000; ++i)  {
			pq.push({-cost-i, cur*i});
		}
	}
}