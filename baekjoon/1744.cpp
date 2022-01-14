#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	int n; cin >> n;
	bool zero=false;
	vector<int> p, m;
	int ans=0;
	for(int i=0; i<n; ++i) {
		int a; cin >> a;
		if(a>1) p.push_back(a);
		if(a==1) ans++;
		if(a==0) zero=true;
		if(a<0) m.push_back(a);
	}
	sort(p.begin(), p.end(), greater<int>());
	sort(m.begin(), m.end(), less<int>());
	for(int i=0; i<p.size(); i+=2) {
		if(i+1<p.size()) ans+=p[i]*p[i+1];
		else ans += p[i];
	}
	for(int i=0; i<m.size(); i+=2) {
		if(i+1<m.size()) ans+=m[i]*m[i+1];
		else if(!zero) ans+=m[i];
	}
	cout << ans << '\n';
}