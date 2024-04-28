#include<iostream>
#include<deque>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t;
	deque<int> q;
	cin >> t;
	while(t--) {
		string str;
		cin>>str;
		if(str=="push") {
			int n;
			cin >> n;
			q.push_back(n);
		}
		else if(str=="pop") {
			if(q.empty()) cout << -1 << '\n';
			else {
				int qf=q.front();
				cout << qf << '\n';
				q.pop_front();
			}
		}
		else if(str=="size") cout << q.size() << '\n';
		else if(str=="empty") cout << q.empty() << '\n';
		else if(str=="front") {
			if(q.empty()) cout << -1 << '\n';
			else {
				int qf=q.front();
				cout << qf << '\n';
			}
		}
		else if(str=="back") {
			if(q.empty()) cout << -1 << '\n';
			else {
				int qf=q.back();
				cout << qf << '\n';
			}
			
		}
	}
}