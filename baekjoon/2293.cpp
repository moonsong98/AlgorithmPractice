#include<iostream>

using namespace std;

int cache[10001];
int coins[101];

int main(void) {
	cin.sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	
	for(int i = 0; i < n; ++i)
		cin >> coins[i];
	
	cache[0] = 1;
	for(int i = 0; i < n; ++i)
		for(int j = coins[i]; j <= k; ++j)
			if(j - coins[i] >= 0)
				cache[j] += cache[j-coins[i]];
	
	cout << cache[k] << endl;
}
/*
#include<iostream>
#include<algorithm>

using namespace std;

int cache[10001][101];
int coins[101];
int n, k;

bool comp(int i, int j) {
	return i > j;
}

int calc(int left, int coin) {
	if(coin == n) return 0;
	int& ret = cache[left][coin];	
	if(ret != -1) return ret;
	if(left == 0) return ret = 1;
	
	ret = 0;
	for(int i = 0; coins[coin] * i <= left; ++i)
		ret += calc(left-coins[coin]*i, coin+1);
	return ret;
}

int main(void) {
	cin >> n >> k;
	
	for(int i = 0; i <= 10000; ++i)
		for(int j = 0; j <= 100; ++j)
			cache[i][j] = -1;
	
	for(int i = 0; i < n; ++i)	
		cin >> coins[i];

	sort(coins, coins+n, comp);
	
	cout << calc(k, 0);
}
*/