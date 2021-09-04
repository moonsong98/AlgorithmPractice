#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
	int n;
	int arr[51];
	cin >> n;
	for(int i=0; i<n; ++i) cin >> arr[i];
	if(n==1) cout << arr[0]*arr[0] << '\n';
	else {
		sort(arr, arr+n);
		cout << arr[0]*arr[n-1] << '\n';
	}
} 