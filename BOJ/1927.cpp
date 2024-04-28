#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	priority_queue<int, vector<int>, greater<int> >pq;
	int n, a;
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a;
		if(a>0) pq.push(a);
		else {
			cout << (pq.size() == 0 ? 0 : pq.top()) << '\n';
			if(pq.size()>0) pq.pop();
		}
	}
}