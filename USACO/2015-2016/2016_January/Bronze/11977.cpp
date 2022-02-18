#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	int N; cin >> N;
	vector<int> nums(N); for(int i=0; i<N; ++i) cin >> nums[i];
	sort(nums.begin(), nums.end());
	
	int ans=0;
	for(int i=0; i<N; ++i) {
		int l, r, cnt=0;
		l=r=i;
		for(int t=1;;++t) {
			int tmp=l-1;
			while(tmp>=0 && nums[l]-nums[tmp]<=t)
				--tmp;
			if(tmp+1==l) {
				cnt+=(i-l); 
				break;
			}
			l=tmp+1;
		}
		for(int t=1;;++t) {
			int tmp=r+1;
			while(tmp<N && nums[tmp]-nums[r]<=t)
				++tmp;
			if(tmp-1==r) {
				cnt+=(r-i);
				break;
			}
			r=tmp-1;
		}
		ans=max(ans,cnt+1);	
	}
	cout << ans << '\n';
}