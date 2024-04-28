#include<iostream>

using namespace std;

string two[8] = {
	"000",
	"001",
	"010",
	"011",
	"100",
	"101",
	"110",
	"111"
};

int main(void) {
	string n, ans;
	cin >> n;
	for(char c: n) ans+=two[c-'0'];
	ans=string(ans.rbegin(), ans.rend());
	while(ans.size()>1&&ans.back()=='0') ans.pop_back();
	ans=string(ans.rbegin(), ans.rend());
	cout << ans << '\n';
}