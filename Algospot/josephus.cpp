#include<iostream>
#include<queue>

using namespace std;

int main(void) {
	queue<int> q;
	int t;
	cin >> t;
	while(t--) {
		int N, K;
		cin >> N >> K;
		for(int i=2; i<=N; ++i)
			q.push(i);
		while(q.size()>2) {
			for(int i=0; i<K-1; ++i) {
				q.push(q.front());
				q.pop();
			}
			q.pop();
		}
		int a, b;
		a=q.front(); q.pop();
		b=q.front(); q.pop();
		if(a<b)
			cout << a << ' ' << b << '\n';
		else
			cout << b << ' ' << a << '\n';
	}
	
}