#include<iostream>
#include<vector>
#include<map>

using namespace std;

map<char, int> c2i={
	{'P', 0},
	{'H', 1},
	{'S', 2}
};

int main(void) {
	int N, ans=0;
	cin >> N;
	vector<vector<int>> pSum(N+1, vector<int>(3,0));
	for(int i=1; i<=N; ++i) {
		for(int j=0; j<3; ++j) pSum[i]=pSum[i-1];
		char ch;
		cin >> ch;
		pSum[i][c2i[ch]]++;
	}
	for(int i=1; i<=N; ++i) {
		int a=-1, b=-1;
		for(int j=0; j<3; ++j) {
			a=max(a, pSum[i-1][j]);
			b=max(b, pSum[N][j]-pSum[i-1][j]);
		}
		ans=max(ans, a+b);
	}
	cout << ans << '\n';
}