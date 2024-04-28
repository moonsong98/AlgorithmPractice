#include<iostream>

using namespace std;

int main(void) {
	int n; cin >> n;
	for(int i=0; i<n; ++i) cout << '*';
	for(int i=0; i<1+2*(n-2); ++i) cout << ' ';
	for(int i=0; i<n; ++i) cout << '*';
	cout <<'\n';
	
	for(int i=0; i<n-2; ++i) {
		for(int j=0; j<=i; ++j) cout << ' ';
		cout << '*';
		for(int j=0; j<n-2; ++j) cout << ' ';
		cout << '*';
		for(int j=0; j<1+2*(n-3-i); ++j) cout << ' ';
		cout << '*';
		for(int j=0; j<n-2; ++j) cout << ' ';
		cout << '*';
		cout <<'\n';
	}
	
	for(int i=0; i<n-1; ++i) cout << ' ';
	cout << '*';
	for(int i=0; i<n-2; ++i) cout << ' ';
	cout << '*';
	for(int i=0; i<n-2; ++i) cout << ' ';
	cout << '*';
	cout <<'\n';
	
	for(int i=0; i<n-2; ++i) {
		for(int j=0; j<n-2-i; ++j) cout << ' ';
		cout << '*';
		for(int j=0; j<n-2; ++j) cout << ' ';
		cout << '*';
		for(int j=0; j<1+2*i; ++j) cout << ' ';
		cout << '*';
		for(int j=0; j<n-2; ++j) cout << ' ';
		cout << '*';
		cout <<'\n';
	}
		
	for(int i=0; i<n; ++i) cout << '*';
	for(int i=0; i<1+2*(n-2); ++i) cout << ' ';
	for(int i=0; i<n; ++i) cout << '*';
}