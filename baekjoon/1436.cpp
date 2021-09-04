#include<iostream>
#include<string>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	int count=0;
	int nextNum=666;
	while(true){
		if(to_string(nextNum).find("666")!=-1) ++count;
		if(count==n) break;
		++nextNum;
	}
	cout<<nextNum<<'\n';
}