#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	vector<int> nums(3);
	vector<int> s(2);
	for(int i=0; i<3; ++i) cin >> nums[i];
	sort(nums.begin(), nums.end());
	for(int i=0; i<2; ++i) s[i]=nums[i+1]-nums[i];
	sort(s.begin(), s.end());
	if(s[0]==1&&s[1]==1) cout << 0 << '\n' << 0 << '\n';
	else if(s[0]==1&&s[1]>1) cout << 2 << '\n' << s[1]-1 << '\n';
	else if(s[0]==2) cout << 1 << '\n' << s[1]-1 << '\n';
	else cout << 2 << '\n' << s[1]-1 << '\n';
}