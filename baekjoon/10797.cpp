#include<iostream>

using namespace std;

int main(void) {
	int n, ans=0;
	cin >> n;
	for(int i=0; i<5; ++i) {
		int a;
		cin >> a;
		if(a==n) ++ans;
	}
	cout << ans << '\n';
}