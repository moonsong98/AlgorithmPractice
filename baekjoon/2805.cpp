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