#pragma once
#include <iostream>
#include <string>
using namespace std;
class Pair {
public:
	int p1;
	int p2;
	Pair(): p1(0),p2(0){}
	Pair(int first,int second):p1(first),p2(second){}
	~Pair()
	{
		cout << "Dectructor Pair\n";
	}
	void Input() 
	{
		cout << "Input oldest_part(p1):";
		cin >> p1;
		while(p1<0||p1>9)
		{
			cout << "Bad value p1 :" << p1 << endl;
			cout << "Input oldest part(0<p1<9):";
			cin >> p1;
		}
		cout << "Input youngest_part(p2):";
		cin >> p2;
	}
	void Output()
	{
		cout << "Output p1 p2: " << p1 << p2 << endl;
	}
	bool operator>(const Pair& s) const {
		return (p1 > s.p1) || (p1 == s.p1 && p2 > s.p2);
	}
	bool operator<(const Pair& s) const {
		return (p1 < s.p1) || (p1 == s.p1 && p2 < s.p2);
	}
	bool operator==(const Pair& s) const {
		return p1 == s.p1 && p2 == s.p2;
	}
};
class Fraction :public Pair {
private:
	int whole;
	int small;
public:
	Fraction():Pair(),whole(0),small(0){}
	Fraction(const Pair& s, int small_p) :whole(concat(s.p1,s.p2)), small(small_p){}
	~Fraction()
	{
		cout << "Destructor Fraction\n";
	}
	void Input() 
	{
		Pair::Input();
		whole = concat(p1, p2);
		cout << "whole_part: " << whole << endl;
		cout << "Input small part: ";
		cin >> small;
	}
	void Output()
	{
		cout << "The number : " << whole << "." << small << endl;
	}
	int concat(int a, int b)
	{
		string s1 = to_string(a);
		string s2 = to_string(b);
		string s = s1 + s2;
		int c = stoi(s);
		return c;
	}
	bool operator>(const Fraction& f) const {
		return (whole > f.whole) || (whole == f.whole && small > f.small);
    }
    bool operator<(const Fraction& f) const {
		return (whole < f.whole) || (whole == f.whole && small < f.small);
    }

    bool operator==(const Fraction& f) const {
		return whole == f.whole && small == f.small;
    }
};
void Task1() {
	cout << "Test class"<<endl;
	Pair p1(2, 4);
	Pair p2(2, 4);
	p1.Output();
	p2.Output();
	if (p1 > p2) 
	{
		cout << "p1 > p2" << endl;
	}
	else if (p1 < p2) 
	{
		cout << "p1 < p2" << endl;
	}
	else if(p1==p2)
	{
		cout << "p1 == p2" << endl;
	}
	cout << "----------------\n";
	Fraction f1(p1, 5);
	Fraction f2(p2, 4);
	f1.Output();
	f2.Output();
	if (f1 > f2) 
	{
		cout << "f1 > f2" << endl;
	}
	else if (f1 < f2)
	{
		cout << "f1 < f2" << endl;
	}
	else if(f1==f2) 
	{
		cout << "f1 == f2" << endl;
	}
	cout << "----------------\n";
	cout << "Test Input" << endl;
	cout << "----------------\n";
	Fraction first, second;
	cout << "Input Fraction first: "<<endl;
	first.Input();
	cout << "----------------\n";
	cout << "Input Fraction second: " << endl;
	second.Input();
	cout << "----------------\n";
	cout << "Test Output" << endl;
	cout << "----------------\n";
	cout << "Output Fraction first: " << endl;
	first.Output();
	cout << "----------------\n";
	cout << "Output Fraction second: " << endl;
	second.Output();
	cout << "----------------\n";
	cout << "Test Comparison first and second :" << endl;
	cout << "----------------\n";
	if (first > second) 
	{
		cout << "first > second" << endl;
	}
	else if (first < second)
	{
		cout << "first < second" << endl;
	}
	else if (first == second)
	{
		cout << "first == second" << endl;
	}
	cout << "----------------\n";
}