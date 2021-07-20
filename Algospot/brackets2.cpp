#include<iostream>
#include<string>
#include<stack>

using namespace std;

void solve() {
	string open = "({[";
	string close = ")}]";
	string str;	
	stack<char> remaining;
	bool ans = true;
	cin >> str;
	
	for(int i = 0; i < str.size(); ++i) {	
		if(open.find(str[i]) != -1)
			remaining.push(str[i]);
		else if (remaining.empty() || open.find(remaining.top()) != close.find(str[i])) {
			ans = false;
			break;	
		}
		else
			remaining.pop();
	}
	ans &= remaining.empty();
	cout << (ans ? "YES" : "NO") << endl;
}

int main(void) {
	int t;
	cin >> t;
	while(t--) solve();
}