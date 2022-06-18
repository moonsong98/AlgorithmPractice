#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		string str; cin >> str;
		ll sum=0;
		for(int i=0; i<(int)str.size(); ++i)
			sum+=(ll)(str[i]-'a'+1);
		ll a=0, b=0;
		if((int)str.size()%2==0) 
			cout << "Alice " << sum << '\n';
		else {
			a=max(sum-(str[0]-'a'+1), sum-(str[(int)str.size()-1]-'a'+1));
			b=sum-a;
			if(a>b) cout << "Alice " << a-b << '\n';
			else cout << "Bob " << b-a << '\n';
		}
	}
}