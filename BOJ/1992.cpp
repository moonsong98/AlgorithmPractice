#include<iostream>
#include<string>

using namespace std;

string b[65];

char val(int y, int x, int size) {
	char first=b[y][x];
	for(int i=0; i<size; ++i) for(int j=0; j<size; ++j) if(b[y+i][x+j]!=first) return '2';
	return first;
}

void check(int y, int x, int size) {
	if(size==1) {
		cout << b[y][x];
		return;
	}
	char part[4];
	part[0]=val(y,x,size/2);
	part[1]=val(y,x+size/2,size/2);
	part[2]=val(y+size/2,x,size/2);
	part[3]=val(y+size/2,x+size/2, size/2);
	/*
	cout << "y: " << y << " x: " << x << " size: " << size << '\n';
	for(int i=0; i<4; ++i) {
		cout << "part " << i << ": "<< part[i] << '\n';
	}
	*/
	bool same=true;
	for(int i=0; i+1<4; ++i)
		if(part[i] != part[i+1] || part[i]=='2' || part[i+1]=='2') same=false;
	if(same) cout << b[y][x];
	else {
		cout << '(';
		if(part[0]=='2') check(y, x, size/2);
		else cout << b[y][x];
		if(part[1]=='2') check(y, x+size/2, size/2);
		else cout << b[y][x+size/2];
		if(part[2]=='2') check(y+size/2, x, size/2);
		else cout << b[y+size/2][x];
		if(part[3]=='2') check(y+size/2, x+size/2, size/2);
		else cout << b[y+size/2][x+size/2];
		cout << ')';
	}
}

int main(void) {
	int n;
	cin >> n;
	for(int i=0; i<n; ++i) cin >> b[i];
	check(0,0,n);
}