#include<iostream>
#include<vector>

using namespace std;

vector<vector<bool>> isUsed;
int n;
int ans=0;

void solution(int row) {
	if(row==n) {
		++ans; return;
	}
	
	for(int col=0; col<n; ++col) {
		if(!isUsed[0][col] && !isUsed[1][col+row] && !isUsed[2][row-col+n]) {
			isUsed[0][col]=isUsed[1][col+row]=isUsed[2][row-col+n]=true;
			solution(row+1);
			isUsed[0][col]=isUsed[1][col+row]=isUsed[2][row-col+n]=false;
		}
	}
}

int main(void) {
	cin >> n;
	isUsed=vector<vector<bool>>(3);
	isUsed[0]=vector<bool>(n, false);
	isUsed[1]=vector<bool>(n*2-1, false);
	isUsed[2]=vector<bool>(n*2-1, false);
	solution(0);
	cout << ans << '\n';
}