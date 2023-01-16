#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, ans = 0; cin >> n >> m;
    int l = 0, r = 0;
    vector<int> h(n);
    for(int &a: h) {
        cin >> a;
        r = max(r, a);
    }
    while(l <= r) {
        int mid = l + (r-l)/2;
        ll sum = 0;
        for(int a: h) 
            sum += (ll)max(0, a - mid);
        if(sum >= m) {
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    cout << ans << '\n';
}
/*
#include<iostream>
#include<vector>

using namespace std;

vector<long long> trees;

long long calc(long long mid) {
	long long ret=0;
	for(int i=0; i<trees.size(); ++i)
		if(trees[i]>mid)
			ret+=(trees[i]-mid);
	return ret;
}

int main(void){
	long long n,m,low=0,high=-1,ans=-1;
	cin>>n>>m;
	trees=vector<long long>(n);
	for(int i=0; i<n; ++i){
		cin >> trees[i];
		high=max(high,trees[i]);
	}
	while(low<=high) {
		long long mid=low+(high-low)/2;
		long long c=calc(mid);
		if(c>=m) {
			ans=mid;
			low=mid+1;
		} else high=mid-1;
	}
	cout << ans << '\n';
}
*/
