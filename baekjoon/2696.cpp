#include<iostream>
#include<queue>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		priority_queue<int, vector<int>, greater<int>> l; //Top is the least
		priority_queue<int, vector<int>, less<int>> s; // Top is the largest
		int n; cin >> n;
		cout << (n+1)/2 << '\n';
		for(int i=0; i<n; ++i) {
			int a; cin >> a;
			if(l.size()==0) l.push(a);
			else a<l.top()?s.push(a):l.push(a);
			if(l.size()==s.size()+2) {
				s.push(l.top());
				l.pop();
			}
			else if(s.size()>l.size()) {
				l.push(s.top());
				s.pop();
			}
			if(i%2==0) cout << l.top() << ' ';
		}
		cout << '\n';
	}
}