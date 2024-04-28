#include<iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	int arr[101];
	cin >> n;
	for(int i=0; i<n; ++i) cin >> arr[i];
	
	for(int i=1; i<n; ++i){
		int a=arr[0], b=arr[i];
		if(a<b){
			int t;
			t=a;a=b;b=t;
		}
		while(b>0){
			int r=a%b;
			a=b;b=r;
		}
		cout << arr[0]/a << "/" <<arr[i]/a<<'\n';
	}
}