#include<iostream>
#include<vector>

using namespace std;

const int MAX=987654321;
const int MIN=-1;

int main(void) {
	int N; cin >> N;
	vector<vector<int>> board(N, vector<int>(N));
	vector<int> inComing(10, 0);
	vector<vector<int>> cords(10,vector<int>(4)); //x_min, x_max, y_min, y_max
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) {
		char ch; cin >> ch;
		board[i][j]=ch-'0';
	}
	for(int n=1; n<=9; ++n) {
		cords[n][0]=cords[n][2]=MAX;
		cords[n][1]=cords[n][3]=MIN;
		for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) {
			if(board[i][j]==n) {
				cords[n][0]=min(cords[n][0],j);
				cords[n][1]=max(cords[n][1],j);
				cords[n][2]=min(cords[n][2],i);
				cords[n][3]=max(cords[n][3],i);
			}
		}
	}
	for(int n=1; n<=9; ++n) {
		if(cords[n][0]==MAX) continue;
		for(int i=cords[n][2]; i<=cords[n][3]; ++i) {
			for(int j=cords[n][0]; j<=cords[n][1]; ++j) {
				if(board[i][j]!=n) inComing[board[i][j]]++;
			}
		}
	}
	
	int ans=0;
	for(int n=1; n<=9; ++n) 
		if(cords[n][0] != MAX && inComing[n]==0) ++ans;
	cout << ans << '\n';
}
