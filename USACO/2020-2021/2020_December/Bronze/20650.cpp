#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	int nums[7]; for(int i=0; i<7; ++i) cin >> nums[i];	
	sort(nums, nums+7, greater<int>());
	int ans[3]={nums[5], nums[1]-nums[2]+nums[5], nums[2]-nums[5]};
	for(int n: ans) cout << n << ' ';
}