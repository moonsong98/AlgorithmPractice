#include<iostream>
#include<vector>
#include<stack>

using namespace std;
typedef long long ll;

int main(void) {
	while(true) {
		int n;
		cin >> n;
		if(n==0) return 0;
		vector<ll> blocks(n);
		stack<ll> s;
		ll ans=0;
		for(int i=0; i<n; ++i) {
			cin >> blocks[i];
			
		}
	}
}
/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;

vector<ll> blocks;

ll solve(int left, int right) {
	if(left==right) return blocks[left];
	ll mid=left+(right-left)/2;
	ll leftAns=solve(left, mid);
	ll rightAns=solve(mid+1, right);
	ll l=mid, r=mid+1, minH=min(blocks[l], blocks[r]), midAns=minH*2;
	while(l>left || r<right) {
		if(r==right) {
			minH=min(blocks[--l],minH);
			midAns=max(midAns, (r-l+1)*minH);
		}
		else if(l==left) {
			minH=min(blocks[++r],minH);
			midAns=max(midAns, (r-l+1)*minH);
			
		}
		else {
			if(blocks[l-1]>=blocks[r+1]) {
				minH=min(blocks[--l],minH);
				midAns=max(midAns, (r-l+1)*minH);
			}
			else {
				minH=min(blocks[++r],minH);
				midAns=max(midAns, (r-l+1)*minH);
			}
		}
	}
	// cout << "left: " << left << " right: " << right << " leftAns: " << leftAns <<" rightAns: " << rightAns << " midAns: " << midAns << '\n';
	return max({leftAns, rightAns, midAns});
}

int main(void) {
	int n;
	while(true) {
		cin >> n;
		if(n==0) break;
		blocks=vector<ll>(n);
		for(int i=0; i<n; ++i) cin >> blocks[i];
		cout << solve(0, n-1) << '\n';
	}
}
*/