#include<iostream>
#include<string>
#include<vector>

using namespace std;

const int MOD = 1e6;

int add (const int A, const int B) {
	return (A%MOD + B%MOD)%MOD;
}

bool validOne (char c) {
	return '1'<= c && c <= '9';
}

bool validTen (string str) {
	return str[0] == '1' || str[0]=='2' && '0' <= str[1] && str[1] <= '6';	
}

int main(void) {
	string str;
	
	cin >> str;
	vector<int> dp(str.size(), 0);
	int len = str.size();
	if(len > 0)
		dp[0] = validOne(str[0]);
	if(len > 1)
		dp[1] = add(dp[0] & validOne(str[1]),validTen(str.substr(0,2)));
	for(int i=2; i<len; ++i) {
		if(validOne(str[i])) dp[i] = add(dp[i], dp[i-1]); 
		if(validTen(str.substr(i-1, 2))) 
			dp[i] = add(dp[i], dp[i-2]);
	}
	cout << dp[len-1] << '\n';
}