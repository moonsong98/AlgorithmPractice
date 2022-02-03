#include<iostream>

using namespace std;

int main(void) {
	char board[3][3];
	for(int i=0; i<3; ++i) for(int j=0; j<3; ++j) cin >> board[i][j];
	bool isSingleWin[26]={false};
	bool isTeamWin[26][26]={false};
	int numOne=0, numTwo=0;
	for(int i=0; i<3; ++i) {
		int a=board[i][0], b=board[i][1], c=board[i][2], d=board[0][i], e=board[1][i], f=board[2][i];
		if(a==b && b==c && !isSingleWin[a-'A']) {
			isSingleWin[a-'A']=true;
			++numOne;
		}
		if(d==e && e==f && !isSingleWin[d-'A']){
			isSingleWin[d-'A']=true;
			++numOne;
		}
		if(a==b&&b!=c&&!isTeamWin[a-'A'][c-'A']&&!isTeamWin[c-'A'][a-'A']) {
			isTeamWin[a-'A'][c-'A']=isTeamWin[c-'A'][a-'A']=true;
			++numTwo;
		}
		if(b==c&&c!=a&&!isTeamWin[a-'A'][b-'A']&&!isTeamWin[b-'A'][a-'A']){
			isTeamWin[a-'A'][b-'A']=isTeamWin[b-'A'][a-'A']=true;
			++numTwo;
		}
		if(a==c&&b!=c&&!isTeamWin[b-'A'][c-'A']&&!isTeamWin[c-'A'][b-'A']){
			isTeamWin[b-'A'][c-'A']=isTeamWin[c-'A'][b-'A']=true;
			++numTwo;
		} 
		if(d==e&&e!=f&&!isTeamWin[d-'A'][f-'A']&&!isTeamWin[d-'A'][f-'A']){
			isTeamWin[d-'A'][f-'A']=isTeamWin[d-'A'][f-'A']=true;
			++numTwo;
		} 
		if(e==f&&f!=d&&!isTeamWin[d-'A'][e-'A']&&!isTeamWin[e-'A'][d-'A']){
			isTeamWin[d-'A'][e-'A']=isTeamWin[e-'A'][d-'A']=true;
			++numTwo;
		} 
		if(d==f&&e!=f&&!isTeamWin[e-'A'][f-'A']&&!isTeamWin[f-'A'][e-'A']){
			isTeamWin[e-'A'][f-'A']=isTeamWin[f-'A'][e-'A']=true;
			++numTwo;
		} 
	}
	int a=board[0][0], b=board[1][1], c=board[2][2], d=board[0][2], e=board[1][1], f=board[2][0];
	if(a==b && b==c && !isSingleWin[a-'A']) {
		isSingleWin[a-'A']=true;
		++numOne;
	}
	if(d==e && e==f && !isSingleWin[d-'A']){
		isSingleWin[d-'A']=true;
		++numOne;
	}
	if(a==b&&b!=c&&!isTeamWin[a-'A'][c-'A']&&!isTeamWin[c-'A'][a-'A']) {
		isTeamWin[a-'A'][c-'A']=isTeamWin[c-'A'][a-'A']=true;
		++numTwo;
	}
	if(b==c&&c!=a&&!isTeamWin[a-'A'][b-'A']&&!isTeamWin[b-'A'][a-'A']){
		isTeamWin[a-'A'][b-'A']=isTeamWin[b-'A'][a-'A']=true;
		++numTwo;
	}
	if(a==c&&b!=c&&!isTeamWin[b-'A'][c-'A']&&!isTeamWin[c-'A'][b-'A']){
		isTeamWin[b-'A'][c-'A']=isTeamWin[c-'A'][b-'A']=true;
		++numTwo;
	} 
	if(d==e&&e!=f&&!isTeamWin[d-'A'][f-'A']&&!isTeamWin[d-'A'][f-'A']){
		isTeamWin[d-'A'][f-'A']=isTeamWin[d-'A'][f-'A']=true;
		++numTwo;
	} 
	if(e==f&&f!=d&&!isTeamWin[d-'A'][e-'A']&&!isTeamWin[e-'A'][d-'A']){
		isTeamWin[d-'A'][e-'A']=isTeamWin[e-'A'][d-'A']=true;
		++numTwo;
	} 
	if(d==f&&e!=f&&!isTeamWin[e-'A'][f-'A']&&!isTeamWin[f-'A'][e-'A']){
		isTeamWin[e-'A'][f-'A']=isTeamWin[f-'A'][e-'A']=true;
		++numTwo;
	} 
	cout << numOne << '\n' << numTwo << '\n';
}