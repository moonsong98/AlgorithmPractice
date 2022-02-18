#include<iostream>
#include<string>

using namespace std;

typedef long long ll;

ll calc(string s, ll a) {
	ll ret=0;
	for(int i=0; i<3; ++i) {
		ll mul=1;
		for(int j=i; j<2; ++j) mul*=a;
		ret+=mul*(s[i]-'0');
	}
	return ret;
}

int main(void) {
	int t; cin >> t;
	while(t--) {
		string a, b; cin >> a >> b;
		bool swapped=false;
		if(a<b) {
			string t=a; a=b; b=t;
			swapped=true;
		}
		for(int i=10; i<=15000; ++i) {
			int done=false;
			int l=i, r=15000;
			ll ci=calc(a,i);
			while(l<=r) {
				int mid=l+(r-l)/2;
				ll cm=calc(b,mid);
				if(ci==cm) {
					if(swapped) cout << mid << ' ' << i << '\n';
					else cout << i << ' ' << mid << '\n';
					done=true;
					break;
				}
				if(ci<cm) r=mid-1; 
				else l=mid+1;
			}
			if(done) break;
		}
	}
}