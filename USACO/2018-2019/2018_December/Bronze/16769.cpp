#include<iostream>

using namespace std;

int main(void) {
	int v[3], c[3];
	for(int i=0; i<3; ++i) cin >> c[i] >> v[i];
	for(int i=0; i<33; ++i) {
		for(int j=0; j<3; ++j) {
			int nj=(j+1)%3;
			int vSum=v[nj]+v[j];
			if(vSum<=c[nj]) {
				v[nj]=vSum;
				v[j]=0;
			}
			else {
				v[nj]=c[nj];
				v[j]=vSum-v[nj];
			}
		}
	}
	int vSum=v[0]+v[1];
	if(vSum<=c[1]){
		v[1]=vSum;
		v[0]=0;
	}
	else {
		v[1]=c[1];
		v[0]=vSum-v[1];
	}
	for(int i=0; i<3; ++i) cout << v[i] << '\n';
}