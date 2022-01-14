#include<iostream>
#include<vector>

using namespace std;

long long calc(long long mid, vector<long long>& len) {
	int ret=0;
	for(int i=0; i<len.size(); ++i) 
		ret+=len[i]/mid;
	return ret;
}


int main(void) {
	long long n, k;
	long long low=1, high=-1, ans=-1;
    cin >> k >> n;
	vector<long long> len(k, 0);	
	for(int i=0; i<k; ++i){
		cin >> len[i];
		high=max(high,len[i]);
	}
	
	while(low<=high) {
		long long mid=low+(high-low)/2;
		if(calc(mid, len)>=n) {
			ans=mid;
			low=mid+1;	
		}
		else high=mid-1;
	}
	cout << ans << '\n';
}
