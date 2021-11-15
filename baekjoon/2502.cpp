#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;

int main(void) {
	const int MAX=30;
	vector<ll> fibo(MAX+1, 0); fibo[0]=0; fibo[1]=1;
	for(int i=2; i<=MAX; ++i) fibo[i]=fibo[i-1]+fibo[i-2];
	int d, k; cin >> d >> k;
	int a=d==1?1:fibo[d-2], b=fibo[d-1];
	for(int i=0; i*a <=k; ++i)
		if((k-i*a)%b==0) {
			cout << i << '\n' << (k-i*a)/b << '\n';
			return 0;
		}
}