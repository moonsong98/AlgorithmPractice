#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void) {
	vector<int> order(26);
	for(int i=0; i<26; ++i) {
		char ch; cin >> ch;
		order[ch-'a']=i;
	}
	string str; cin >> str;
	int ans=1;
	for(int i=0; i+1<str.size(); ++i)
		if(order[str[i]-'a']>=order[str[i+1]-'a']) ++ans;
	cout << ans << '\n';
}