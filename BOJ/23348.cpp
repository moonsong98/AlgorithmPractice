#include<iostream>

using namespace std;

int w[3], arr[3];

int calc() {
	int ret=0;
	for(int i=0; i<3; ++i) ret += w[i]*arr[i];
	return ret;
}

int main(void) {
	int M=-1, n;
	for(int i=0; i<3; ++i) cin >> w[i];
	cin >> n;
	for(int i=0; i<n; ++i) {
		int s=0;
		for(int k=0; k<3; ++k) {
			for(int j=0; j<3; ++j) cin >> arr[j];
			s+=calc();
		}
		M=max(M, s);
	}
	cout << M << '\n';
}