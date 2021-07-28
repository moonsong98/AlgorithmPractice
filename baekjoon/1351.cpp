#include<iostream>
#include<map>

using namespace std;

long long n, p, q;
map<long long, long long> cache;

long long solve(long long i) {
	if(i == 0) return 1;
	if(cache[i]) return cache[i];
	return cache[i] = solve(i/p) + solve(i/q);
}

int main(void) {
	cin >> n >> p >> q;
	cout << solve(n) << endl;
}