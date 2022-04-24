#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

const long long MOD=998244353ll;
int n; 
string str;

pair<long long, string> calc(int x) {
	if(2*x>=sz(str))
		return {1, string(1, str[x])};
	auto l=calc(2*x), r=calc(2*x+1);
	int cmp=l.second.compare(r.second);
	if(cmp<0) {
		auto tmp=l;
		l=r;
		r=tmp;
	}
	pair<long long, string> ret;
	ret.first=l.first*r.first*(cmp==0?1:2)%MOD;
	ret.second=string(1, str[x])+l.second+r.second;
	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	str=string((1<<n), ' ');
	for(int i=1; i<(1<<n); ++i) cin >> str[i];
	cout << calc(1).first << '\n';
}