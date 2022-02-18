#include<iostream>

using namespace std;

int main(void) {
	int X, Y, M;	
	int ans=-1;
	cin >> X >> Y >> M;
	for(int i=0; i*X<=M; ++i) {
		int j=(M-i*X)/Y;
		ans=max(ans, i*X+j*Y);
	}
	cout << ans << '\n';
}