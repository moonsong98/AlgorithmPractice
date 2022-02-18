#include<iostream>
#include<vector>
#include<map>

using namespace std;

map<char, int> c2i={{'B',0},{'E',1},{'S',2},{'I',3},{'G',4},{'O',5},{'M',6}};
int cnt[7][2];

int main(void) {
	int n; cin >> n;
	for(int i=0; i<n; ++i) {
		char ch; int num;
		cin >> ch >> num;
		num%2?cnt[c2i[ch]][1]++:cnt[c2i[ch]][0]++;
	}
	int total=1, odd=cnt[6][1];
	for(int i=0; i<7; ++i) total*=(cnt[i][0]+cnt[i][1]);
	odd*=(cnt[0][1]*cnt[3][0]+cnt[0][0]*cnt[3][1]);
	odd*=((cnt[1][1]*cnt[2][0]+cnt[1][0]*cnt[2][1])*(cnt[4][0]*cnt[5][0]+cnt[4][1]*cnt[5][1])+(cnt[1][0]*cnt[2][0]+cnt[1][1]*cnt[2][1])*(cnt[4][1]*cnt[5][0]+cnt[4][0]*cnt[5][1]));
	cout << total-odd << '\n';
}