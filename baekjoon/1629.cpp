#include<iostream>

using namespace std;
typedef long long ll;


ll mul(ll a, ll b, ll c) {
	if(b==0) return 1ll;
	if(b%2) {
		return ((a%c) * (mul(a,b-1,c)%c))%c;
	}
	ll half=mul(a, b/2, c);
	return ((half%c) * (half%c)) % c;
}

int main(void) {
	ll a, b, c;
	cin>>a>>b>>c;
	cout << mul(a, b, c);
}