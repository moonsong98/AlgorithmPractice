#include<iostream>

using namespace std;

int pSum[100011];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		cin>>pSum[i];
		if(i>1) pSum[i] += pSum[i-1];
	}
	for(int i=0; i<m; ++i) {
		int a, b;
		cin >> a >> b;
		cout << pSum[b]-pSum[a-1] << '\n';
	}
}