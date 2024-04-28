#include<iostream>
#include<algorithm>

using namespace std;

int weight[51], height[51], numBigger[51], r[51];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	for(int i=0; i<n; ++i) cin>>weight[i]>>height[i];
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			if(i==j) continue;
			if(weight[j]>weight[i] && height[j]>height[i]) numBigger[i]++;
		}
	}
	
	for(int i=0; i<n; ++i)
		cout << numBigger[i]+1 <<' ';
	cout<<'\n';
}