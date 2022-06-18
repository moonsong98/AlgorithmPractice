#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ll n, q, sum=0; cin >> n >> q;
	vector<ll> v(n);
	vector<int> index(n, -1);
	ll allChanged=-1, newValue=-1;
	
	
	for(ll &a: v) {
		cin >> a;
		sum+=a;
	}
	for(int i=0; i<q; ++i) {
		ll c, a, b;
		cin >> c;
		if(c==1) {
			cin >> a >> b;
			if(allChanged<=index[a-1])
				sum+=b-v[a-1];
			else
				sum+=b-newValue;
			v[a-1]=b;	
			index[a-1]=i;
		}
		else {
			cin >> newValue;
			allChanged=i;
			sum=n*newValue;
		}
		cout << sum << '\n';
	}
}