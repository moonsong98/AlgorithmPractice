#include<iostream>
#include<cstring>

using namespace std;

long long cache[30][30];

long long bino(int n, int k) {
	if(k==0 || k==n) return 1;
	long long& ret = cache[n][k];
	if(ret != -1) return ret;
	return ret=bino(n-1,k-1) + bino(n-1,k);
}

int main(void) {
	memset(cache, -1, sizeof(cache));
	int n, k;
	cin >> n >> k;
	cout << bino(n-1, k-1) << '\n';
}