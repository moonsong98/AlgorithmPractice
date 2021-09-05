#include<iostream>
#include<vector>

using namespace std;

int upperBound(vector<int>& nums, int target){
	int left=0, right=nums.size();
	while(left < right){
		cout<<left<<right<<endl;
		int mid=(left+right)/2;
		if(nums[mid]<=target) left=mid;
		else right=mid;
	}
	return nums[left];
}

int main(void) {
	vector<int> nums={1,3,5,7,9};
	cout<<upperBound(nums,2);
}