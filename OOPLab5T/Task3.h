#pragma once
#include <iostream>
#include <string>
using namespace std;
class Window {
protected:
	double width;
	double height;
	double size_frame;
public:
	Window():width(0),height(0),size_frame(0){}
	Window(double width_, double height_,double size_frame_) : width(width_),height(height_),size_frame(size_frame_){}
	Window(const Window& n) 
	{
		width = n.width;
		height = n.height;
		size_frame = n.size_frame;
		cout << " Constructor Copy Window(const Window& n)" << endl;
	}
	Window(Window&& n) 
	{
		width = n.width;
		height = n.height;
		size_frame = n.size_frame;
		cout << " Constructor Move Window(Window&& n) \n";
	}
	Window& operator=(const Window& s) 
	{
		width = s.width;
		height = s.height;
		size_frame = s.size_frame;
		cout << " operator=(const Window& s) Copy \n";
		return *this;
	}
	Window& operator=(Window&& s) 
	{
		width = s.width;
		height = s.height;
		size_frame = s.size_frame;
		cout << " operator=( Window&& s) Move \n";
		return *this;
	}
	~Window()
	{
		cout << "Destructor Window" << endl;
	}
	friend istream& operator>>(istream& in, Window& a) 
	{
		cout << "Input width:";
		in >> a.width;
		cout << "Input height:";
		in >> a.height;
		cout << "Input size_frame:";
		in >> a.size_frame;
		return in;
	}
	friend ostream& operator<<(ostream& out, Window& a)
	{
		out << "Width: " << a.width << endl;
		out << "Height: " << a.height << endl;
		out << "Size_Frame: " << a.size_frame << endl;
		return out;
	}

	void Input() 
	{
		cout << "Input width:";
		cin >> width;
		cout << "Input height:";
		cin >> height;
		cout << "Input size_frame:";
		cin >> size_frame;
	}
	void Output()
	{	
		cout << " Width: " << width << endl;
		cout << " Height: " << height << endl;
		cout << " Size_Frame: " << size_frame << endl;
	}
};
class TitledWindow : public Window {
private:
	string title;
public:
	TitledWindow() :Window(), title("") {}
	TitledWindow(double width_,double height_,double size_frame_,string title_):Window(width_,height_,size_frame_),title(title_){}
	TitledWindow(const TitledWindow& s) : Window(s) 
	{
		title = s.title;
		cout << " Constructor Copy TitledWindow(const TitledWindow &s) \n";
	}
	TitledWindow(TitledWindow &&s) 
	{
		width = s.width;
		height = s.height;
		size_frame = s.size_frame;
		title = s.title;
		cout << "Constructor Copy TitledWindow(TitledWindow &&s) \n";
	}
	~TitledWindow() 
	{
		cout << "\tDestructor TitledWidnow\n";
	}
	TitledWindow& operator=(const TitledWindow& s)
	{
		this->Window::operator=(s);
		title = s.title;
		cout << "TitledWindow& operator =(const TitledWindow &s) \n";
		return *this;
	}
	TitledWindow& operator=(TitledWindow &&s)
	{
		width = s.width;
		height = s.height;
		size_frame = s.size_frame;
		title = s.title;
		cout << "TitledWindow& operator =(TitledWindow &&s) \n";
		return *this;
	}
	friend istream& operator>>(istream& in, TitledWindow& a)
	{
		cout << "----------------------" << endl;
		cout << "|  Input Info Window |" << endl;
		cout << "----------------------" << endl;
		cout << "Input width:";
		in >> a.width;
		cout << "Input height:";
		in >> a.height;
		cout << "Input size_frame:";
		in >> a.size_frame;
	    cout << "Input title: ";
		in >> a.title;
		cout << "----------------------" << endl;
		return in;
	}
	friend ostream& operator<<(ostream& out, TitledWindow& a)
	{
		out << "----------------------" << endl;
		out << "|    Info Window     |" << endl;
		out << "----------------------" << endl;
		out << " Width: " << a.width << endl;
		out << " Height: " << a.height<< endl;
		out << " Size_Frame: " << a.size_frame << endl;
		out << " Title: " << a.title << endl;
		out << "----------------------" << endl;
		return out;
	}
	void Input() 
	{
		cout << "----------------------" << endl;
		cout << "|  Input Info Window |" << endl;
		cout << "----------------------" << endl;
		Window::Input();
		cout << "Input title: ";
		cin >> title;
		cout << "----------------------" << endl;
	}
	void Output()
	{
		cout << "----------------------" << endl;
		cout << "|    Info Window     |" << endl;
		cout << "----------------------" << endl;
		Window::Output();
		cout << " Title: " << title << endl;
		cout << "----------------------" << endl;;
	}

};


void Task3() 
{
	cout << "Test class : " << endl;
	TitledWindow tw_1;
	cout << "\nTest constructor 4 param:" << endl;
	TitledWindow tw_2(20.3, 40.8, 12, "UKR");
	tw_2.Output();
	cout << "\nTest constructor copy:" << endl;
	TitledWindow tw_3(tw_2);
	cout << tw_3;
	cout << "\nTest operator =" << endl;
	tw_1 = tw_3;
	cout << tw_1;
	cout << "\nTest  move:" << endl;
	TitledWindow tw_4;
	tw_4 = (TitledWindow)tw_1;
	cout << tw_4;
	cout << "\n Test function Input() ,Output():" << endl;
	TitledWindow t1;
	t1.Input();
	t1.Output();
	cout << "\nTest cin,cout " << endl;
	TitledWindow tw2;
	cin >> tw2;
	cout << tw2;
	cout << "End test!!!!!!"<<endl;
}