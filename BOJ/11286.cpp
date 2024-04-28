#include<iostream>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	int n;
	cin >> n;
	while(n--){
		int a; cin >> a;
		if(a==0) {
			cout << (pq.size()>0?pq.top().first*pq.top().second : 0) << '\n';
			if(pq.size()>0)pq.pop();
		}
		else a > 0 ? pq.push({a,1}) : pq.push({-a,-1});
	}
}