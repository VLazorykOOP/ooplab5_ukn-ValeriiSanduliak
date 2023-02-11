#pragma once
#include <iostream>
#include <string>
using namespace std;
class Pair {
public:
	int p1;
	int p2;
	Pair() {
		p1 = 0;
		p2 = 0;
		//cout << "Constructor Pair";
	};
	Pair(int a, int b) {
		p1 = a;
		p2 = b;
	}
	~Pair() { 
		//cout << "Destructor Pair"; 
	};
	friend istream& operator>>(istream& os, Pair& a);
	friend ostream& operator<<(ostream& os, Pair& a);
};
istream& operator>>(istream& is, Pair& a) {
	cout << "Input p1: ";
	is >> a.p1;
	cout << "Input p2: ";
	is >> a.p2;
	if (a.p1 <= 9 && a.p2 <= 9) {
		return is;
	}
	else { 
		cout << "Incorrect value!!!!!!!"<<endl;
	}
}
ostream& operator<<(ostream& os, Pair& a) {
	os << "p1:" << a.p1 << endl;
	os << "p2:" << a.p2 << endl;
	return os;
}
class Fraction : protected Pair {
	int whole_part;    // union oldest part and yongest part
	int small_part;    // .etc
public:
	Fraction() {
		whole_part = 0;
		small_part = 0;
		//cout << "Constructor Fraction";
	};
	~Fraction() {
		//cout << "Destructor Fraction";
	};
	
	friend istream& operator>>(istream& os, Fraction& a);
	friend ostream& operator<<(ostream& os, Fraction& a);
	void Сomparison() {
		Pair first, second;
		Fraction _first, _second;
		cout << "Input oldest part :" << endl; cin >> first;
		cout << "Input younest part :" << endl; cin >> second;
		cout << "Input small part1 :"; cin >> _first;
		cout << "Input small part2 :"; cin >> _second;
		cout << first.p1 << second.p1 << "." << _first.small_part << endl;
		cout << first.p2 << second.p2 << "." << _second.small_part<< endl;

		if (first.p1 > first.p2) {
			whole_part = concat(first.p1, second.p1);
			cout << "first more then second: " << whole_part << "." << _first.small_part << endl;
		}
		else if (first.p1 < first.p2) {
			whole_part = concat(first.p2, second.p2);
			cout << "first less then second: " << whole_part << "." << _first.small_part << endl;
		};
		if (first.p1 == first.p2) {
			if (second.p1 > second.p2) {
				whole_part = concat(first.p1, second.p1);
				cout << "first more then second: " << whole_part << "." << _first.small_part << endl;
			}
			else if (second.p1 < second.p2) {
				whole_part = concat(first.p2, second.p2);
				cout << "first less then second: " << whole_part << "." << _first.small_part << endl;
			}
			else if (second.p1 == second.p2) {
				if (_first.small_part > _second.small_part) {
					whole_part = concat(first.p2, second.p2);
					cout << "first more then second: " << whole_part << "." << _first.small_part << endl;
				}
				else if (_first.small_part < _second.small_part) {
					whole_part = concat(first.p2, second.p2);
					cout << "first less then second: " << whole_part << "." << _second.small_part << endl;
				}
				else if (_first.small_part == _second.small_part) {
					cout << "First == second ";
				}
			}
		}
	};
	int concat(int a, int b)
	{
		string s1 = to_string(a);
		string s2 = to_string(b);
		string s = s1 + s2;
		int c = stoi(s);
		return c;
	}
};
istream& operator>>(istream& is, Fraction& a) {
	is >> a.small_part;
	return is;
}
ostream& operator<<(ostream& os, Fraction& a) {
	//os << "Whole part" << a.whole_part;
	os << "small_part: " << a.small_part << endl;
	return os;
}

void Task1() {
	cout << "Test comparision class Pair"<<endl;
	Fraction test;
	test.Сomparison();
}