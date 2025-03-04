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


//����
int menu()
{
    register int er;
    cout << "�������:\n";
    cout << "1- ��� ����� ����� ������\n";
    cout << "2- ��� ������ ������(��)\n";
    cout << "3- ��� ���������� �������\n";
    cout << "4- ��� ��������� ������\n";
    cout << "5- ��� �������� ������(��)\n";
    cout << "6- ��� ������\n";
    cin >> er;
    while (er <= 0 || er>6 || cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "������ �����: ����� �������� ������ ���� ������������� ����� ������ �� 1 �� 6. ��������� ����: ";
        cin >> er;
    }
    return er;
}