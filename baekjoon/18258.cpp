#include<iostream>
#include<string>
#include<queue>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	queue<int> q;
	cin >> n;
	int back=-1;
	while(n--){
		string str;
		cin >> str;
		if(str=="push") {
			int a;
			cin >> a;
			q.push(a);
			back=a;
		}
		if(str=="front") {
			if(q.empty()) cout << -1 << '\n';
			else cout << q.front() << '\n';
		}
		if(str=="size") cout << q.size() << '\n';
		if(str=="empty") cout << q.empty() << '\n';
		if(str=="pop") {
			if(q.empty()) cout << -1 << '\n';
			else{
				cout << q.front() << '\n';
				q.pop();
				if(q.empty()) back=-1;
			}
		}
		if(str=="back") cout << back << '\n';
	}
}