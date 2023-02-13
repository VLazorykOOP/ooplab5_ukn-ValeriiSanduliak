#pragma once
#include<iostream>
#include <fstream>
#include<string>
#include<windows.h>
using namespace std;

class Wheel {
protected:
	double radius;
public:
	Wheel() {
		radius = NULL;
		cout << "Defaul wheel costructor\n\n";
	}
	Wheel(double r) {
		radius = r;
	}
	~Wheel() {
		cout << "Destructor wheel\n";
	}
	void setRadius(double r) {
		radius = r;
	}
	void Input() {
		cout << "Input radius for wheel:"; cin >> radius;
	}
	void Output() {
		cout << "Wheel radius :" << radius;
	}
};

class Car {
protected:
	Wheel* wheels;
	string mark;
	long long price;
	int cnt_wheels;
public:
	Car() {
		wheels =nullptr;
		mark = "";
		price = NULL;
		cnt_wheels = NULL;
		cout << "Defaul car costructor";
	}
	Car(int wheels_cnt, string m, long long p,double r){
		cnt_wheels = wheels_cnt;
		wheels = new Wheel[cnt_wheels];
		for (int i = 0; i < cnt_wheels; i++) {
			wheels[i].setRadius(r);
			
		}
		mark = m;
		price = p;
	}
	~Car() {
		cout << "Destructor car";
	}
	int getCntWheels() {
		return cnt_wheels;
	}
	void Input() {
		int cnt_;
		cout <<endl<< "---------------------------"<<endl;
		cout << "Input car info:" << endl;
		cout << "Input mark:"; cin >> mark;
		cout << "Input price:"; cin >> price;
		cout << "Input cnt_wheels: "; cin >> cnt_;
		cnt_wheels = cnt_;
		wheels = new Wheel[cnt_wheels];
		for (int i = 0; i < cnt_wheels; i++) {
			cout << "[" << i+1 << "]";
			   wheels[i].Input();
		}
	}
	void Output() {
		int cnt1_;
		cout << "---------------------------" << endl;
		cout << "Output car info:" << endl;
		cout << "Mark:" << mark << endl;
		cout << "Price:" << price << endl;
		cnt1_ = getCntWheels();
		cout << "count wheels:" << cnt1_;
		for (int i = 0; i < cnt1_; i++) {
			cout << "\n" << "[" << i+1 << "]";
			  wheels[i].Output();
		}
	}
};

class Truck : public Car {
	long long Carrying_capacity;
public:
	Truck() {
		Carrying_capacity = NULL;
		cout << "Defaul Truck costructor";
	}
	Truck(int cnt_wheels, string mark, long long price, long long cary,double radius) :Car(cnt_wheels, mark, price,radius), Carrying_capacity(cary) {
		cout << "Constructor 4 value";
	}
	~Truck() {
		cout << "Destructor truck";
	}
	void Input() {
		Car::Input();
		cout << "Input Carrying_capacity kg: "; cin >> Carrying_capacity;
	}
	void Output() {
		Car::Output();
		cout << endl;
		cout << "Input Carrying_capacity: "; cout << Carrying_capacity<<"kg"<<endl;
		cout << "---------------------------" << endl;
	}
};
void Task2() {
	cout << "Tesk class Truck"<<endl;
	Truck truck;
	truck.Input();
	truck.Output();
	cout << endl;
	Truck truck1(6, "Mersedes", 55234, 2575237,10);
	truck1.Output();
}
