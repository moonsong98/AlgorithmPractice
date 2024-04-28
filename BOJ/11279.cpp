#include<iostream>
#include<queue>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	priority_queue<int> pq;
	int n;
	cin >> n;
	while(n--){
		int a; cin >> a;
		if(!a) {
			cout << (pq.size() ? pq.top() : 0) << '\n';
			if(pq.size()) pq.pop();
		}
		else pq.push(a);
	}
}