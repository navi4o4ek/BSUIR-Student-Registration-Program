#include <iostream>      
#include <stdio.h>
#include <fstream>
#include <windows.h>
#include "1.1.h"
using namespace std;

int menu();

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int sch;

	sch = loadFromFile();
	if (sch == -1)
		return 0;


    while (1)
    {
        switch (menu())
        {
        case 1: sch = enter_new(sch); break;
        case 2: out(sch); break;
        case 3: sort(sch); break;
        case 4: change(sch); break;
        case 5: sch = del(sch); break;
        case 6: saveToFile(sch); return 0;
        }
    }
}


//МЕНЮ
int menu()
{
    register int er;
    cout << "Введите:\n";
    cout << "1- для ввода новой записи\n";
    cout << "2- для вывода записи(ей)\n";
    cout << "3- для сортировки записей\n";
    cout << "4- для изменения записи\n";
    cout << "5- для удаления записи(ей)\n";
    cout << "6- для выхода\n";
    cin >> er;
    while (er <= 0 || er>6 || cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка ввода: номер действия должен быть положительным целым числом от 1 до 6. Повторный ввод: ";
        cin >> er;
    }
    return er;
}