#include<iostream>

using namespace std;

int cache[31];

int tile(int n) {
	if(n % 2) return 0;
	if(n == 0) return 1;
	int& ret = cache[n];
	if(ret != -1) return ret;
	
	ret = tile(n-2) * 3;
	
	for(int i = n-4; i >= 0; i-=2)
		ret += tile(i)*2;
	
	return ret;
}

int main(void) {
	int n;
	cin >> n;
	for(int i = 0; i <= 30; ++i) cache[i] = -1;
	cout << tile(n) << endl;
}
