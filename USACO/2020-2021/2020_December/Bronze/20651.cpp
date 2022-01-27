#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n, ans=0; cin >> n;
	vector<int> p(n+1); for(int i=1; i<=n; ++i) cin >> p[i];
	for(int i=1; i<=n; ++i) {
		int sum=0;
		bool petalsSeen[1001]={false,};
		for(int j=i; j<=n; ++j) {
			petalsSeen[p[j]]=true;
			sum+=p[j];
			if(sum%(j-i+1)==0 && petalsSeen[sum/(j-i+1)]) ++ans;
		}
	}
	cout << ans << '\n';
}