#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<vector<int>> pal;
vector<int> dp;
string str;
int len;
const int INF=1e9;

void calcPal(int i, int j) {
	if(pal[i][j]) return;
	pal[i][j]=1;
	if(i-1>=0 && j+1<len && str[i-1]==str[j+1]) calcPal(i-1, j+1);
}

int main(void) {
	cin >> str; len=str.size();
	pal=vector<vector<int>>(len, vector<int>(len,0));
	dp=vector<int>(len, INF);
	for(int i=0; i<len; ++i) {
		calcPal(i,i);
		if(i<len-1 && str[i]==str[i+1]) calcPal(i,i+1);
	}
	dp[0]=1;
	for(int i=1; i<len; ++i) 
		for(int j=i; j>=0; --j) 
			if(pal[j][i]) {
				int val=(j==0 ? 1 : 1+dp[j-1]);
				dp[i]=min(dp[i],val);
			}
	
	cout << dp[len-1] << '\n';
}