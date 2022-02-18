#include<iostream>
#include<queue>
#include<utility>
#include<set>

using namespace std;

int main(void) {
	int c, n;
	multiset<int> chicken;
	priority_queue<pair<int,int>> pqCows;
	cin >> c >> n;
	for(int i=0; i<c; ++i) {
		int a;
		cin >> a;
		chicken.insert(a);
	}
	for(int i=0; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		pqCows.push({-b, -a});
	}
	int ans=0;
	while(!pqCows.empty()){
		int a=-pqCows.top().second, b=-pqCows.top().first;
		pqCows.pop();
		auto it=chicken.lower_bound(a);
		if(it!=chicken.end() && *it <= b) {
			++ans;
			chicken.erase(it);
		}
	}
	cout << ans << '\n';
}