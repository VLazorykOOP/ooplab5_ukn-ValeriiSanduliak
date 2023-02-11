// OOPLab5T.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
using namespace std;
// Ваші файли загловки 
//
//#include "Lab5Exmaple.h"
#include"Task1.h"

int main()
{
    std::cout << " Lab #5  !\n";
    char ch = '5';
    do {
        cout << "Chose task 1-3:" << endl;
        cout << " >>> ";
        ch = cin.get();

        cin.get();

        switch (ch) {
        case '1': Task1();  break;
       // case '2': task2();  break;
        //case '3': task3();  break;
        case '4': return 0;
        }
        cout << " Press any key and enter\n";
        ch = cin.get();
    } while (ch != '5');

    return 0;

}
