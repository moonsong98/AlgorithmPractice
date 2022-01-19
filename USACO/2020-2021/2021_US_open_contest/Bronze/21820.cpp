#include<iostream>
#include<vector>

using namespace std;

int d[500001];

int main(void) {
	int N, L;
	cin >> N >> L;
	for(int i=0; i<N; ++i) {
		int a; cin >> a; d[a]++;
	}
	int left=N, h=-1;
	for(int i=0; i<=N; ++i) {
		int norm=left+min(d[i-1], L);
		h=max(h, min(norm, i));
		left-=d[i];	
	}
	cout << h << '\n';
}