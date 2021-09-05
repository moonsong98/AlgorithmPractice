#include<iostream>

using namespace std;

int dist(int a, int b){
	int ret=a-b;
	return ret>0?ret:-ret;
}

bool between(int a, int b, int c) {
	bool ret=false;
	if(a<c && c<b) ret=true;
	else if(a>c && c>b) ret=true;
	return ret;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;	
	while(t--){
		int cord[3][2];
		int answer=0;
		for(int i=0; i<3; ++i)
			cin>>cord[i][0]>>cord[i][1];
		
		if(cord[0][0]==cord[1][0]&&cord[0][0]==cord[2][0]&&between(cord[0][1],cord[1][1],cord[2][1]))
				answer+=2+dist(cord[0][1],cord[1][1]);
		else if(cord[0][1]==cord[1][1]&&cord[0][1]==cord[2][1]&&between(cord[0][0],cord[1][0],cord[2][0]))
				answer+=2+dist(cord[0][0],cord[1][0]);
		else
			answer+=dist(cord[0][0], cord[1][0])+dist(cord[0][1],cord[1][1]);
		
		cout << answer << '\n';
	}
}