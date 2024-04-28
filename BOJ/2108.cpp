#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(void) {
	int N;
	cin >> N;
	vector<int> nums;
	double sum=0;
	for(int i=0; i<N; ++i){
		int n;
		cin >> n;
		nums.push_back(n);
		sum+=n;
	}
	sort(nums.begin(), nums.end());
	nums.push_back((int)1e10);
	int cnt=-1;
	int cntCur=0;
	int curNum=1e9;
	vector<int> cand;
	for(int n: nums) {
		if(curNum!=n) {
			if(cnt==cntCur) cand.push_back(curNum);
			else if(cnt<cntCur){
				cand.clear();
				cand.push_back(curNum);
				cnt=cntCur;
			}
			curNum=n;
			cntCur=1;
		}
		else ++cntCur;
	}
	int mostFrequent=cand.size()==1?cand[0]:cand[1];
	nums.pop_back();
	cout << floor(sum/N+0.5) << '\n';
	cout << nums[N/2] << '\n';
	cout << mostFrequent << '\n';
	cout << nums[N-1]-nums[0] << '\n';
}