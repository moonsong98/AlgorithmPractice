#include<iostream>

using namespace std;

int main(void) {
	int n; cin >> n;
	int len=1; int m=n/10;
	while(m>0) {
		m/=10;
		len*=10;
	}
	long long ans=n;
	m=(n%len)*10+n/len;
	while(n!=m) {
		ans+=m;
		m=(m%len)*10+m/len;
	}
	cout << ans << '\n';
}