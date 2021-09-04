#include<iostream>
#include<cmath>

using namespace std;

int main(void) {
	long long hp[2], atk[2], p, s;
	cin >> hp[0] >> atk[0] >> hp[1] >> atk[1] >> p >> s;
	if(hp[1]/atk[0] && 1 <= hp[1]%atk[0] && hp[1]%atk[0] <= p) hp[1] += s;
	else if(hp[1]/atk[0] && !((hp[1]-p)%atk[0])) hp[1]+=s;
	double cnt0=ceil((double)hp[0]/atk[1]), cnt1=ceil((double)hp[1]/atk[0]);
	cout << (cnt0 >= cnt1 ? "Victory!" : "gg") << '\n'; 
}