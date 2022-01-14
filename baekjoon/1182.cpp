#include<iostream>
#include<vector>

using namespace std;

int n, s, ans=0;
vector<int> nums;

void calc(vector<bool>& chosen) {
	int sum=0;
	for(int i=0; i<n; ++i) if(chosen[i]) sum+=nums[i];
	if(sum==s) ans++;
}

void find(vector<bool>& chosen) {
	int startIndex=-1;
	for(int i=0; i<n; ++i) if(!chosen[i])
		startIndex=i;
	if(startIndex==-1) return;
	cout << startIndex << '\n';
	for(int i=startIndex; i<n; ++i) {
		chosen[i]=true;
		calc(chosen);
		find(chosen);
		chosen[i]=false;
	}
}

int main(void) {
	cin >> n >> s;
	nums=vector<int>(n); for(int i=0; i<n; ++i) cin >> nums[i];
	vector<bool> chosen(n, false);
	find(chosen);
	cout << ans << '\n';
}