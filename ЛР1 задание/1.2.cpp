/*����������� ��������� ������ �������������� �� �������� ������ ���������, ������������ ���� �������� ���������� � ������� ���������:
������� � ��������, ��� ��������, ��� ����������� � �����,
������ �� ������ ������� �� ���������: ������, ������ ����������, �����������.*/
#include <iostream>      
#include <stdio.h>                      
#include <string.h>
#include <fstream>
#include <windows.h>
#include "1.1.h"
#define path "dataBase.txt"
using namespace std;

struct student
{
	char fam[20], im[20], otch[20];
	char inc[7];
	int bith;
	int ya;
	int marks[3];
};

static student* mas, *tmp, t, delet;

//�������� ������ �� �����
extern int loadFromFile()
{
	int k;
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "���� �� ���������� ��� �� ����� ���� ������!\n������� ����� ����?\n1- ��\n2- ���\n��� �����: ";
		cin >> k;
		cout << "__________________________________" << endl << endl << endl;
		if (k == 1)
		{
			if (!(mas = (student*)malloc(sizeof(student))))
			{
				cout << "������������ ������!";
				return -1;
			}
			return 0;
		}
		else return -1;
	}
	else
	{
		fin >> k;

		//��������� ������
		if (!(mas = (student*)malloc(k * sizeof(student))))
		{
			cout << "������������ ������!";
			fin.close();
			return -1;
		}

		//���������� ������
		for (register int i = 0; i < k; i++)
		{
			fin >> mas[i].fam >> mas[i].im >> mas[i].otch >> mas[i].inc
				>> mas[i].bith >> mas[i].ya
				>> mas[i].marks[0] >> mas[i].marks[1] >> mas[i].marks[2];
		}
		fin.close();
		cout << "������ ������� ��������� �� �����.\n";
		cout << "__________________________________" << endl << endl << endl;
		return k;
	}
}


//���������� ������ � ����
extern void saveToFile(int sch)
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "������ ���������� ������ � ����!" << endl;
		return;
	}
	else
	{
		fout << sch << "\n";
		for (register int i = 0; i < sch; i++)
		{
			fout<< mas[i].fam << " " << mas[i].im << " " << mas[i].otch << " " << mas[i].inc << " "
				<< mas[i].bith << " " << mas[i].ya << " "
				<< mas[i].marks[0] << " " << mas[i].marks[1] << " " << mas[i].marks[2] << "\n";
		}
	}
	fout.close();
	cout << "\n������ ������� ��������� � ����!\n";
	cout << "�����...\n";
	cout << "__________________________________" << endl;
}


//���� ����� ������
extern int enter_new(int sch)
{
	if (tmp = (student*)realloc(mas, (sch + 1) * sizeof(student))) mas = tmp;
	else
	{
		cout << "������������ ������!";	
		return sch;
	}

	cout << "\n\n������ ����� " << sch + 1;
	cout << "\n������� ������� ��������: ";
	cin >> mas[sch].fam;
	cout << "������� ��� ��������: ";
	cin >> mas[sch].im;
	cout << "������� �������� ��������: ";
	cin >> mas[sch].otch;

	mas[sch].inc[0] = mas[sch].fam[0];
	mas[sch].inc[1] = '.';
	mas[sch].inc[2] = mas[sch].im[0];
	mas[sch].inc[3] = '.';
	mas[sch].inc[4] = mas[sch].otch[0];
	mas[sch].inc[5] = '.';
	mas[sch].inc[6] = '\0';

	cout << "������� ��� �������� ��������: ";
	cin >> mas[sch].bith;
	cout << "������� ��� ����������� � �����: ";
	cin >> mas[sch].ya;
	cout << "������� ������ �� ������ �� ������ �������: ";
	cin >> mas[sch].marks[0];
	while (mas[sch].marks[0] <= 0 || mas[sch].marks[0] > 10 || cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "������ �����: ������ ������ ���� ������������� ����� ������ �� 1 �� 10. ��������� ����: ";
		cin >> mas[sch].marks[0];
	}
	cout << "������� ������ �� ������ ���������� �� ������ �������: ";
	cin >> mas[sch].marks[1];
	while (mas[sch].marks[1] <= 0 || mas[sch].marks[1] > 10 || cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "������ �����: ������ ������ ���� ������������� ����� ������ �� 1 �� 10. ��������� ����: ";
		cin >> mas[sch].marks[1];
	}
	cout << "������� ������ �� ����������� �� ������ �������: ";
	cin >> mas[sch].marks[2];
	while (mas[sch].marks[2] <= 0 || mas[sch].marks[2] > 10 || cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "������ �����: ������ ������ ���� ������������� ����� ������ �� 1 �� 10. ��������� ����: ";
		cin >> mas[sch].marks[2];
	}
	cout << "������ ������� �������!\n";
	cout << "__________________________________" << endl << endl << endl;
	return sch + 1;
}


//����� ������� 
extern void out(int sch)
{
	register int sw, k;
	if (sch == 0)
		cout << "\n\n��� �������!\n";
	else
	{
		cout << "\n\n�������:\n";
		cout << "1- ���� ������ ������� �����-���� ������\n";
		cout << "2- ���� ������ ������� ��� ������\n";
		cin >> sw;
		while (sw <= 0 || sw >2 || cin.fail() || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "������ �����: ����� �������� ������ ���� ������������� ����� ������ �� 1 �� 2. ��������� ����: ";
			cin >> sw;
		}
		if (sw == 1)
		{
			cout << "\n������� ����� ������, ������� ����� �������: ";
			cin >> k;
			while (k > sch || k<=0 || cin.fail() || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "������ �����: ����� ������, ������� ����� �������, ������ ���� ������������� ����� ������, �� ����������� ����� ����� �������. ��������� ����: ";
				cin >> k;
			}
			cout << endl;
			cout << "������ ����� " << k << endl;
			cout << "��� ��������: " << mas[k - 1].fam << " " << mas[k - 1].im << " " << mas[k - 1].otch << endl;
			cout << "�������� ��������: " << mas[k - 1].inc << endl;
			cout << "��� �������� ��������: " << mas[k - 1].bith << endl;
			cout << "��� ����������� � �����: " << mas[k - 1].ya << endl;
			cout << "������ �� ������ �� ������ �������: " << mas[k - 1].marks[0] << endl;
			cout << "������ �� ������ ���������� �� ������ �������: " << mas[k - 1].marks[1] << endl;
			cout << "������ �� ����������� �� ������ �������: " << mas[k - 1].marks[2] << endl;
		}
		if (sw == 2)
		{
			for (register int i = 0; i < sch; i++)
			{
				cout << "\n������ ����� " << i+1 << endl;
				cout << "��� ��������: " << mas[i].fam << " " << mas[i].im << " " << mas[i].otch << endl;
				cout << "�������� ��������: " << mas[i].inc << endl;
				cout << "��� �������� ��������: " << mas[i].bith << endl;
				cout << "��� ����������� � �����: " << mas[i].ya << endl;
				cout << "������ �� ������ �� ������ �������: " << mas[i].marks[0] << endl;
				cout << "������ �� ������ ���������� �� ������ �������: " << mas[i].marks[1] << endl;
				cout << "������ �� ����������� �� ������ �������: " << mas[i].marks[2] << endl;
			}
		}
	}
	cout << "__________________________________" << endl << endl << endl;
}


//C���������
extern void sort(int sch)
{
	if (sch == 0)
	{
		cout << "\n\n��� ����c��!\n";
	}
	else
	{
		register int sw;
		cout << "\n\n������� �� ������ ���� ������������ ����������:\n";
		cout << "1- �� ������� � ���������� �������\n";
		cout << "2- �� ���� �������� � ������������ �������\n";
		cout << "3- �� ���� ����������� � ����� � ������������ �������\n";
		cin >> sw;
		while (sw <= 0 || sw > 3 || cin.fail() || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "������ �����: ����� �������� ������ ���� ������������� ����� ������ �� 1 �� 3. ��������� ����: ";
			cin >> sw;
		}
		switch (sw)
		{
		case 1: sort_fio(sch); break;
		case 2: sort_bith(sch); break;
		case 3: sort_ya(sch); break;
		default: cout << "�������� �����\n";
		}
	}
	cout << "__________________________________" << endl << endl << endl;
}

//C��������� �� �������
extern void sort_fio(int sch)
{
	register int i, j;
	for (i = 0; i < sch - 1; i++)
		for (j = i + 1; j < sch; j++)
			if (strcmp(mas[i].fam, mas[j].fam) > 0)
			{
				t = mas[i];
				mas[i] = mas[j];
				mas[j] = t;
			}
	cout << "\n\n���������:\n";
	for (i = 0; i < sch; i++)
	{
		cout << "\n";
		cout << i + 1 << ". " << mas[i].fam << endl;
	}
}


//���������� �� ���� ��������
extern void sort_bith(int sch)
{
	register int i, j;
	for (i = 0; i < sch - 1; i++)
		for (j = i + 1; j < sch; j++)
			if (mas[i].bith > mas[j].bith)
			{
				t = mas[i];
				mas[i] = mas[j];
				mas[j] = t;
			}
	cout << "\n\n���������:\n";
	for (i = 0; i < sch; i++)
	{
		cout << "\n";
		cout << i + 1 << ". " << mas[i].fam << "- " << mas[i].bith << endl;
	}
}


//���������� �� ���� ����������� � �����
extern void sort_ya(int sch)
{
	register int i, j;
	for (i = 0; i < sch - 1; i++)
		for (j = i + 1; j < sch; j++)
			if (mas[i].ya > mas[j].ya)
			{
				t = mas[i];
				mas[i] = mas[j];
				mas[j] = t;
			}
	cout << "\n\n���������:\n";
	for (i = 0; i < sch; i++)
	{
		cout << "\n";
		cout << i + 1 << ". " << mas[i].fam << "- " << mas[i].ya << endl;
	}
}


//���������
extern void change(int sch)
{
	if (sch == 0)
	{
		cout << "\n\n��� ����c��!\n";
	}
	else
	{
		register int c, per;
		cout << "\n\n������� ����� ������ ��� ���������: ";
		cin >> c;
		cout << mas[c - 1].fam << endl;
		do
		{
			cout << "\n�������: \n";
			cout << "1-��� ��������� ������� ��������\n";
			cout << "2-��� ��������� ��� ��������\n";
			cout << "3-��� ��������� �������� ��������\n";
			cout << "4-��� ��������� ���� �������� ��������\n";
			cout << "5-��� ��������� ���� ����������� � �����\n";
			cout << "6-��� ��������� ������ �� ������ �� ������ �������\n";
			cout << "7-��� ��������� ������ �� ������ ���������� �� ������ �������\n";
			cout << "8-��� ��������� ������ �� ����������� �� ������ �������\n";
			cout << "9-��� �����������\n";
			cin >> per;
			switch (per)
			{
			case 1:  cout << "\n������� ����� ������� ��������: ";
				cin >> mas[c - 1].fam; break;
			case 2: cout << "\n������� ����� ��� ��������: ";
				cin >> mas[c - 1].im; break;
			case 3: cout << "\n������� ����� �������� ��������: ";
				cin >> mas[c - 1].otch; break;
			case 4: cout << "\n������� ����� ��� �������� ��������: ";
				cin >> mas[c - 1].bith; break;
			case 5: cout << "\n������� ����� ��� ����������� � �����: ";
				cin >> mas[c - 1].ya; break;
			case 6: cout << "\n������� ����� ������ �� ������ �� ������ �������: ";
				cin >> mas[c - 1].marks[0]; break;
			case 7: cout << "\n������� ����� ������ �� ������ ���������� �� ������ �������: ";
				cin >> mas[c - 1].marks[1]; break;
			case 8: cout << "\n������� ����� ������ �� ����������� �� ������ �������: ";
				cin >> mas[c - 1].marks[2]; break;
			case 9: cout << "__________________________________" << endl << endl << endl;
				return;
			default: cout << "�������� �����\n";
			}
		} while (1);
	}
}


//��������
extern int del(int sch)
{
	if (sch == 0)
	{
		cout << "\n\n��� ����c��!\n";
	}
	else
	{
		register int d;
		cout << "\n\n������� ����� ������, ������� ���������� �������\n";
		cout << "���� ���������� ������� ��� ������,������� '99'\n";
		cin >> d;
		if (d != 99)
		{
			for (register int i = (d - 1); i < sch; i++)
				mas[i] = mas[i + 1];
			sch = sch - 1;
		}
		if (d == 99)
		{
			for (register int i = 0; i < sch; i++)
				mas[i] = delet;
			sch = 0;
		}
		cout << "������� �������\n";
	}
	cout << "__________________________________" << endl << endl << endl;
	return sch;
}