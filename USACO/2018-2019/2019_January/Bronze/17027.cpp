#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<vector<int>> swapResult(n+1, vector<int>(3));
	swapResult[0][0]=0;
	swapResult[0][1]=1;
	swapResult[0][2]=2;
	vector<int> guesses(n+1);
	for(int i=1; i<=n; ++i) {
		int u, v; cin >> u >> v >> guesses[i];
		int w=5-(u+v); --u; --v; --guesses[i];
		swapResult[i][w]=swapResult[i-1][w];
		swapResult[i][u]=swapResult[i-1][v];
		swapResult[i][v]=swapResult[i-1][u];
	}
	int nums[3]={0,};
	for(int i=1; i<=n; ++i) 
		nums[swapResult[i][guesses[i]]]++;
	cout << *max_element(nums, nums+3) << '\n';
}
