#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	stack<int> s;
	while(n--){
		string str;
		cin>>str;
		if(str=="push"){
			int a;
			cin >> a;
			s.push(a);
		}
		if(str=="pop"){
			if(s.size()==0) cout << -1 << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		if(str=="size")
			cout << s.size() << '\n';
		if(str=="empty")
			cout << s.empty() << '\n';
		if(str=="top") {
			if(s.size()==0) cout << -1 << '\n';
			else cout << s.top() << '\n';
		}
	}
}