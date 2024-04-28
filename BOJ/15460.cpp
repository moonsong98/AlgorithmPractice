#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	int n; cin >> n;
	vector<ll> scores(n); for(int i=0; i<n; ++i) cin >> scores[i];
	vector<ll> smallest(n); vector<int> pSum(n,0); pSum[n-1] = smallest[n-1]=scores[n-1];
	for(int i=n-2; i>=1; --i) {
		pSum[i]=pSum[i+1]+scores[i];
		smallest[i]=(scores[i]<=smallest[i+1]?scores[i]:smallest[i+1]);
	}
	int maxIndex=n-2;
	for(int i=n-3; i>=1; --i)
		if((pSum[i]-smallest[i])*(n-maxIndex-1) >= (pSum[maxIndex]-smallest[maxIndex])*(n-i-1)) maxIndex=i;
	
	for(int i=1; i<=n-2; ++i) 
		if((pSum[i]-smallest[i])*(n-maxIndex-1) == (pSum[maxIndex]-smallest[maxIndex])*(n-i-1)) cout << i << '\n';
}