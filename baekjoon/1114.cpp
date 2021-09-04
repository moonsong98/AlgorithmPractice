#include<iostream>
#include<queue>
#include<vector>
#include<cstdlib>

using namespace std;
typedef long long ll;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ll l, c, k;
	cin >> l >> k >> c;
	
	priority_queue<pair<ll,pair<ll,ll>>> pq;
	vector<ll> pos(k);
	for(int i=0; i<k; ++i) cin >> pos[i];
	
	ll ans[2]={-1, -1};
	pq.push({l, {0, l}});	
	
	while(pq.size()<c+1) {
		ll x1=pq.top().second.first, x2=pq.top().second.second;
		// cout << "x1: " << x1 << " x2: " << x2 << '\n';
		pq.pop();
		int left=-1, right=-1;
		int ll=0, rr=k-1;
		while(ll<=rr) {
			int mid=ll+(rr-ll)/2;
			if(x1 < pos[mid] && pos[mid] < x2) {
				left=mid;
				rr=mid-1;
			} else ll=mid+1;
		}
		rr=k-1;
		while(ll<=rr) {
			int mid=ll+(rr-ll)/2;
			// cout << mid << '\n';
			if(x1 < pos[mid] && pos[mid] < x2) {
				right=mid;
				ll=mid+1;
			} else rr=mid-1;
		}
		// cout << left << ' ' << right << '\n';
		int p=-1; //cutting pos
		ll=left, rr=right;
		while(ll<=rr) {
			int mid=ll+(rr-ll)/2;
			if(mid==0) {
				p=0;
				break;
			}
			int diff=abs((x2-pos[mid])-(pos[mid]-x1));
			int diffCmp=abs((x2-pos[mid-1])-(pos[mid-1]-x1));
			if(diff<diffCmp) {
				p=mid;
				ll=mid+1;
			} else rr=mid-1;
		}
		if(p == -1) break;
		pq.push({x2-pos[p], {pos[p], x2}});
		pq.push({pos[p]-x1, {x1, pos[p]}});
		if(ans[1]==-1) ans[1]=pos[p];
	}
	ans[0]=pq.top().first;
	cout << ans[0] << ' '<< ans[1] << '\n';
}