#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int a[1000*1000+11];
vector<int> b;


int main(void) {
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
		b.push_back(a[i]);
	}
	
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	
	for(int i=0; i<n; ++i){
		cout<<lower_bound(b.begin(), b.end(), a[i])-b.begin() << ' ';
	}
}