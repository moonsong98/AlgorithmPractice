#include<iostream>
#include<queue>

using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for(int i=1; i<=n; ++i) q.push(i);
	
	cout << "<";
	while(q.size()>1) {
		for(int i=0; i+1<k; ++i) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << ">" << '\n';
}