#include<bits/stdc++.h>
using namespace std;

int main(void) {
	int N, cnt=0;
	cin >> N;
	vector<int> v;
	for(int i=0; i<N; ++i) {
		int a;
		cin >> a;
		v.push_back(-a);
	}
	sort(v.begin(), v.end());
	for(int i=0; i<N; ++i)
		if(-v[i]>=cnt) ++cnt;
	cout << cnt << '\n';
}