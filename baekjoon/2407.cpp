#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

string dp[101][101];

string bigIntAdd(string a, string b) {
	string ret;
	int sum=0;
	while(!a.empty()||!b.empty()||sum) {
		if(!a.empty()) {
			sum+=a.back()-'0';
			a.pop_back();
		}
		if(!b.empty()) {
			sum+=b.back()-'0';
			b.pop_back();
		}
		ret.push_back((sum%10)+'0');
		sum/=10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

string comb(int n, int m) {
	if(n==m || m == 0) return "1";
	string &ret=dp[n][m];
	if(ret!="") return ret;
	return ret=bigIntAdd(comb(n-1,m),comb(n-1,m-1));
}

int main(void) {
	int n, m;
	cin >> n >> m;
	cout << comb(n,m) << '\n';
}