#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(void) {
	while(true) {
		int n, a=0, b=0, na=0, nb=0, numZeros=0; cin >> n;
		if(!n) break;
		vector<int> nums; 
		for(int i=0; i<n; ++i) {
			int num; cin >> num;
			if(num>0) nums.push_back(num);
			else ++numZeros;
		}
		sort(nums.begin(), nums.end(), greater<int>());
		for(int i=0; i+2<nums.size(); ++i) {
			if(a<=b) {
				int t=1;
				for(int j=0; j<na; ++j) t*=10;
				a+=t*nums[i];
				++na;
			}
			else {
				int t=1;
				for(int j=0; j<nb; ++j) t*=10;
				b+=t*nums[i];
				++nb;	
			}
		}
		na+=numZeros/2; nb+=numZeros/2;
		if(numZeros&1) 
			a<b?++na:++nb;
		for(int i=nums.size()-2; i<nums.size(); ++i) {
			if(a<=b) {
				int t=1;
				for(int j=0; j<na; ++j) t*=10;
				a+=t*nums[i];
				++na;
			}
			else {
				int t=1;
				for(int j=0; j<nb; ++j) t*=10;
				b+=t*nums[i];
				++nb;	
			}
		}
		cout << a+b << '\n';
	}
}