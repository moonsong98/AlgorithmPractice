#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	vector<ll> pSum(n+1, 0); 
	vector<ll> lowest(n+1, 0); // i번째 수가 사라진 이후 가장 작은 수
	for(int i=1; i<=n; ++i) {
		cin >> seq[i];
		seq[i] += seq[i-1];
	}
	for(int i=n-1; i>=1; --i) {
		int v=seq[i+1]-seq[i];
		lowest[i]=min(lowest[i+1], v);
	} 
	for(int i=1; i<=n; ++i) {
		
	}
}