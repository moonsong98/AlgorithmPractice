#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

string years[]={"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
vector<string> cowNames;
vector<int> bornYear;

int getYear(string s) {
	for(int i=0; i<12; ++i) if(s==years[i]) return i;
}

int getCowId(string s) {
	for(int i=0; i<cowNames.size(); ++i) if(s==cowNames[i]) return i;
}

int main(void) {
	int n; cin >> n;
	
	cowNames.push_back("Bessie");
	bornYear.push_back(0);
	for(int i=0; i<n; ++i) {
		string newCow, existCow, compStr, yearStr, useless;
		cin >> newCow >> useless >> useless >> compStr >> yearStr >> useless >> useless >> existCow;
		int year=getYear(yearStr), cowId=getCowId(existCow), comp=compStr.size()<=4, existCowBornYear=(bornYear[cowId]%12+12)%12;
		cowNames.push_back(newCow);
		if(comp)
			year>existCowBornYear?bornYear.push_back(bornYear[cowId]+year-existCowBornYear):bornYear.push_back(bornYear[cowId]+12-existCowBornYear+year);
		else
			year<existCowBornYear?bornYear.push_back(bornYear[cowId]-existCowBornYear+year):bornYear.push_back(bornYear[cowId]-12+year-existCowBornYear);
		// 12년 빼고 차이 만큼 앞으로 더하기 ex) Dragon에서 Rooster까지 갈 때는 12년 전 Dragon으로 간 후 Rooster과 Dragon 차이만큼 더해주기
			
	}
	cout << abs(bornYear[getCowId("Elsie")]) << '\n';
}