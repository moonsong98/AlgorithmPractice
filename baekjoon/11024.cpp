#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s;
		int sum = 0;
		getline(cin, s);
		string num = "";
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
			{
				sum += stoi(num);
				num = "";
			}
			else
			{
				num += s[i];
			}
		}
		if (num != "") sum += stoi(num);
		cout << sum << '\n';

	}
	return 0;
}