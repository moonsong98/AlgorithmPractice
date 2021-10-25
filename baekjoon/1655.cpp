#include<iostream>
#include<queue>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	priority_queue<int, vector<int>, greater<int>> pqFront;
	priority_queue<int, vector<int>, less<int>> pqBack;
	
	int n;
	cin >> n;
	
	for(int i=1; i<=n; ++i) {
		int a;
		cin >> a;
		if(i==1 || pqBack.top() >= a) {
			pqBack.push(a);
			if(pqBack.size() > pqFront.size()+1) {
				pqFront.push(pqBack.top());
				pqBack.pop();
			}
		}
		else {
			pqFront.push(a);
			if(pqFront.size() > pqBack.size()) {
				pqBack.push(pqFront.top());
				pqFront.pop();
			}
		}
		cout << pqBack.top() << '\n';
	}
}