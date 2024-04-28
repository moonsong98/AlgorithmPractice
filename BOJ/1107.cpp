#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<bool> button(10, true);
int ans=987654321, s=1, n;

int vecToInt(vector<int>& num) {
	int ret=0, mul=1;
	for(int i=num.size()-1; i>=0; --i) {
		ret+=(num[i]*mul);
		mul*=10;
	}
	return ret;
}

void solve(vector<int>& num) {
	if(num.size()>s) return;
	if(num.size()>0) ans=min(ans, int(num.size())+abs(n-vecToInt(num)));
	for(int i=0; i<10; ++i) {
		if(num.size()==0 && i==0) continue;
		if(button[i]) {
			num.push_back(i);
			solve(num);
			num.pop_back();
		}
	}
}

int main(void) {
	int m; cin >> n >> m;
	ans=abs(n-100);
	for(int i=0; i<m; ++i) {
		int a; cin >> a; button[a]=false;
	}
	if(button[0]) ans=min(ans, n+1);
	int a=1;
	while(a<n) {
		++s; a*=10;
	}
	vector<int> num;
	solve(num);
	cout << ans << '\n';
}