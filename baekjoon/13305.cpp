#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n;
	vector<int> length(n-1, 0);
	vector<int> cost(n,0);
	for(int i=0; i+1<n; ++i) cin >> length[i];
	for(int i=0; i<n; ++i) cin >> cost[i];
	
	int sum=0;
	int currentCost=length[0];
	int currentLength=length[0];
	for(int i=1; i+1<n; ++i) {
		if(cost[i]<currentCost) {
			currentCost=cost[i];
			sum+=currentCost*currentLength;
			currentLength=0;
		}
		currentLength+=length[i];
	}
	sum+=currentCost*currentLength;
	cout<<sum<<'\n';
}