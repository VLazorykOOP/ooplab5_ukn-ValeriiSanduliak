#pragma once
#include<iostream>
#include <fstream>
#include<string>
using namespace std;

class Wheel {
protected:
	double radius;
public:
	Wheel() {
		radius = NULL;
		cout << "Defaul wheel costructor";
	}
	Wheel(double r) {
		radius = r;
	}
	~Wheel() {
		cout << "Destructor wheel";
	}
	void setRadius(double r) {
		radius = r;
	}
	void Input() {
		cout << "Input radius for wheel "; cin >> radius;
	}
	friend ostream& operator<<(ostream& os, Wheel& a);
	friend istream& operator>>(istream& os, Wheel& a);
};
ostream& operator<<(ostream& os, Wheel& a) {
	os <<"Wheel radius :"<< a.radius << endl;
	return os;
}
istream& operator>>(istream& is, Wheel& a) {
	cout << "Input wheel radius";
	is >> a.radius;
	return is;
}
class Car {
protected:
	Wheel wheels;
	string mark;
	double price;
public:
	Car() {
		wheels =NULL;
		mark = nullptr;
		price = NULL;
		cout << "Defaul car costructor";
	}
	Car(double wheels_cnt, string mak, double p) {
		wheels = wheels_cnt;
		mark = mak;
		price = p;
		cout << wheels;
	}
	~Car() {
		cout << "Destructor car";
	}
};
class Truck : public Car {
	double Carrying_capacity;
public:
	Truck() {
		Carrying_capacity = NULL;
		cout << "Defaul Truck costructor";
	}
	~Truck() {
		cout << "Destructor truck";
	}
};