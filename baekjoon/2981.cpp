#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	long long seq[100], diff[100];
	vector<long long> ans;
	int n;
	
	cin >> n;
	for(int i=0; i<n; ++i) cin>>seq[i];
	for(int i=0; i+1<n; ++i) diff[i]=(seq[i]>seq[i+1]?seq[i]-seq[i+1]:seq[i+1]-seq[i]);
	for(int i=0; i+2<n; ++i){
		int a=diff[i], b=diff[i+1];
		while(b>0){
			int r=a%b; a=b; b=r;
		}
		diff[i+1]=a;
	}
	int num=diff[n-2];
	for(int i=1; i*i<=num; ++i)
		if(num%i==0) {
			ans.push_back(i);
			ans.push_back(num/i);
		}
	
	sort(ans.begin(), ans.end());
	for(int i=1; i<ans.size(); ++i)
		if(ans[i-1]!=ans[i]) cout << ans[i] << ' ';
	cout << '\n';
}