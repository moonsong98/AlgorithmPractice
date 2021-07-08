#include<iostream>
#include<string>

using namespace std;

string flip(string::iterator &itr) {
	char c = *(itr++);
	if(c!='x') return string(1, c);
	string str1 = flip(itr);
	string str2 = flip(itr);
	string str3 = flip(itr);
	string str4 = flip(itr);
	return string("x") + str3 + str4 + str1 + str2;
}

void solve() {
	string str;
	cin >> str;
	string::iterator itr = str.begin();
	cout << flip(itr) << endl;
}

int main(void) {
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) solve();
}