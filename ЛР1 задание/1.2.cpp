/*Разработать программу вывода упорядоченного по алфавиту списка студентов, предусмотрев ввод исходной информации о четырех студентах:
фамилия и инициалы, год рождения, год поступления в БГУИР,
оценки за первый семестр по предметам: физика, высшая математика, информатика.*/
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

//ЗАГРУЗКА ДАННЫХ ИЗ ФАЙЛА
extern int loadFromFile()
{
	int k;
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Файл не существует или не может быть открыт!\nСоздать новый файл?\n1- Да\n2- Нет\nВаш выбор: ";
		cin >> k;
		cout << "__________________________________" << endl << endl << endl;
		if (k == 1)
		{
			if (!(mas = (student*)malloc(sizeof(student))))
			{
				cout << "Недостаточно памяти!";
				return -1;
			}
			return 0;
		}
		else return -1;
	}
	else
	{
		fin >> k;

		//Выделение памяти
		if (!(mas = (student*)malloc(k * sizeof(student))))
		{
			cout << "Недостаточно памяти!";
			fin.close();
			return -1;
		}

		//Считывание данных
		for (register int i = 0; i < k; i++)
		{
			fin >> mas[i].fam >> mas[i].im >> mas[i].otch >> mas[i].inc
				>> mas[i].bith >> mas[i].ya
				>> mas[i].marks[0] >> mas[i].marks[1] >> mas[i].marks[2];
		}
		fin.close();
		cout << "Данные успешно загружены из файла.\n";
		cout << "__________________________________" << endl << endl << endl;
		return k;
	}
}


//СОХРАНЕНИЕ ДАННЫХ В ФАЙЛ
extern void saveToFile(int sch)
{
	ofstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "Ошибка сохранения данных в файл!" << endl;
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
	cout << "\nДанные успешно сохранены в файл!\n";
	cout << "Выход...\n";
	cout << "__________________________________" << endl;
}


//ВВОД НОВОЙ ЗАПИСИ
extern int enter_new(int sch)
{
	if (tmp = (student*)realloc(mas, (sch + 1) * sizeof(student))) mas = tmp;
	else
	{
		cout << "Недостаточно памяти!";	
		return sch;
	}

	cout << "\n\nЗапись номер " << sch + 1;
	cout << "\nВведите фамилию студента: ";
	cin >> mas[sch].fam;
	cout << "Введите имя студента: ";
	cin >> mas[sch].im;
	cout << "Введите отчество студента: ";
	cin >> mas[sch].otch;

	mas[sch].inc[0] = mas[sch].fam[0];
	mas[sch].inc[1] = '.';
	mas[sch].inc[2] = mas[sch].im[0];
	mas[sch].inc[3] = '.';
	mas[sch].inc[4] = mas[sch].otch[0];
	mas[sch].inc[5] = '.';
	mas[sch].inc[6] = '\0';

	cout << "Введите год рождения студента: ";
	cin >> mas[sch].bith;
	cout << "Введите год поступления в БГУИР: ";
	cin >> mas[sch].ya;
	cout << "Введите оценку по физике за первый семестр: ";
	cin >> mas[sch].marks[0];
	while (mas[sch].marks[0] <= 0 || mas[sch].marks[0] > 10 || cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка ввода: оценка должна быть положительным целым числом от 1 до 10. Повторный ввод: ";
		cin >> mas[sch].marks[0];
	}
	cout << "Введите оценку по высшей математике за первый семестр: ";
	cin >> mas[sch].marks[1];
	while (mas[sch].marks[1] <= 0 || mas[sch].marks[1] > 10 || cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка ввода: оценка должна быть положительным целым числом от 1 до 10. Повторный ввод: ";
		cin >> mas[sch].marks[1];
	}
	cout << "Введите оценку по информатике за первый семестр: ";
	cin >> mas[sch].marks[2];
	while (mas[sch].marks[2] <= 0 || mas[sch].marks[2] > 10 || cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Ошибка ввода: оценка должна быть положительным целым числом от 1 до 10. Повторный ввод: ";
		cin >> mas[sch].marks[2];
	}
	cout << "Данные успешно введены!\n";
	cout << "__________________________________" << endl << endl << endl;
	return sch + 1;
}


//ВЫВОД ЗАПИСЕЙ 
extern void out(int sch)
{
	register int sw, k;
	if (sch == 0)
		cout << "\n\nНет записей!\n";
	else
	{
		cout << "\n\nВведите:\n";
		cout << "1- если хотите вывести какую-либо запись\n";
		cout << "2- если хотите вывести все записи\n";
		cin >> sw;
		while (sw <= 0 || sw >2 || cin.fail() || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Ошибка ввода: номер действия должен быть положительным целым числом от 1 до 2. Повторный ввод: ";
			cin >> sw;
		}
		if (sw == 1)
		{
			cout << "\nВведите номер записи, которую нужно вывести: ";
			cin >> k;
			while (k > sch || k<=0 || cin.fail() || cin.peek() != '\n')
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Ошибка ввода: номер записи, которую нужно вывести, должен быть положительным целым числом, не привышающим общее число записей. Повторный ввод: ";
				cin >> k;
			}
			cout << endl;
			cout << "Запись номер " << k << endl;
			cout << "ФИО студента: " << mas[k - 1].fam << " " << mas[k - 1].im << " " << mas[k - 1].otch << endl;
			cout << "Инициалы студента: " << mas[k - 1].inc << endl;
			cout << "Год рождения студента: " << mas[k - 1].bith << endl;
			cout << "Год поступления в БГУИР: " << mas[k - 1].ya << endl;
			cout << "Оценка по физике за первый семестр: " << mas[k - 1].marks[0] << endl;
			cout << "Оценка по высшей математике за первый семестр: " << mas[k - 1].marks[1] << endl;
			cout << "Оценка по информатике за первый семестр: " << mas[k - 1].marks[2] << endl;
		}
		if (sw == 2)
		{
			for (register int i = 0; i < sch; i++)
			{
				cout << "\nЗапись номер " << i+1 << endl;
				cout << "ФИО студента: " << mas[i].fam << " " << mas[i].im << " " << mas[i].otch << endl;
				cout << "Инициалы студента: " << mas[i].inc << endl;
				cout << "Год рождения студента: " << mas[i].bith << endl;
				cout << "Год поступления в БГУИР: " << mas[i].ya << endl;
				cout << "Оценка по физике за первый семестр: " << mas[i].marks[0] << endl;
				cout << "Оценка по высшей математике за первый семестр: " << mas[i].marks[1] << endl;
				cout << "Оценка по информатике за первый семестр: " << mas[i].marks[2] << endl;
			}
		}
	}
	cout << "__________________________________" << endl << endl << endl;
}


//CОРТИРОВКА
extern void sort(int sch)
{
	if (sch == 0)
	{
		cout << "\n\nНет запиcей!\n";
	}
	else
	{
		register int sw;
		cout << "\n\nВведите по какому полю осуществлять сортировку:\n";
		cout << "1- по фамилии в алфавитном порядке\n";
		cout << "2- по году рождения в возрастающем порядке\n";
		cout << "3- по году поступления в БГУИР в возрастающем порядке\n";
		cin >> sw;
		while (sw <= 0 || sw > 3 || cin.fail() || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Ошибка ввода: номер действия должен быть положительным целым числом от 1 до 3. Повторный ввод: ";
			cin >> sw;
		}
		switch (sw)
		{
		case 1: sort_fio(sch); break;
		case 2: sort_bith(sch); break;
		case 3: sort_ya(sch); break;
		default: cout << "Неверный выбор\n";
		}
	}
	cout << "__________________________________" << endl << endl << endl;
}

//CОРТИРОВКА по фамилии
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
	cout << "\n\nРезультат:\n";
	for (i = 0; i < sch; i++)
	{
		cout << "\n";
		cout << i + 1 << ". " << mas[i].fam << endl;
	}
}


//СОРТИРОВКА по году рождения
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
	cout << "\n\nРезультат:\n";
	for (i = 0; i < sch; i++)
	{
		cout << "\n";
		cout << i + 1 << ". " << mas[i].fam << "- " << mas[i].bith << endl;
	}
}


//СОРТИРОВКА по году поступления в БГУИР
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
	cout << "\n\nРезультат:\n";
	for (i = 0; i < sch; i++)
	{
		cout << "\n";
		cout << i + 1 << ". " << mas[i].fam << "- " << mas[i].ya << endl;
	}
}


//ИЗМЕНЕНИЕ
extern void change(int sch)
{
	if (sch == 0)
	{
		cout << "\n\nНет запиcей!\n";
	}
	else
	{
		register int c, per;
		cout << "\n\nВведите номер записи для изменения: ";
		cin >> c;
		cout << mas[c - 1].fam << endl;
		do
		{
			cout << "\nВведите: \n";
			cout << "1-для изменения фамилии студента\n";
			cout << "2-для изменения имя студента\n";
			cout << "3-для изменения отчества студента\n";
			cout << "4-для изменения года рождения студента\n";
			cout << "5-для изменения года поступления в БГУИР\n";
			cout << "6-для изменения оценки по физике за первый семестр\n";
			cout << "7-для изменения оценки по высшей математике за первый семестр\n";
			cout << "8-для изменения оценки по информатике за первый семестр\n";
			cout << "9-для прекращения\n";
			cin >> per;
			switch (per)
			{
			case 1:  cout << "\nВведите новую фамилию студента: ";
				cin >> mas[c - 1].fam; break;
			case 2: cout << "\nВведите новое имя студента: ";
				cin >> mas[c - 1].im; break;
			case 3: cout << "\nВведите новое отчество студента: ";
				cin >> mas[c - 1].otch; break;
			case 4: cout << "\nВведите новый год рождения студента: ";
				cin >> mas[c - 1].bith; break;
			case 5: cout << "\nВведите новый год поступления в БГУИР: ";
				cin >> mas[c - 1].ya; break;
			case 6: cout << "\nВведите новую оценку по физике за первый семестр: ";
				cin >> mas[c - 1].marks[0]; break;
			case 7: cout << "\nВведите новую оценку по высшей математике за первый семестр: ";
				cin >> mas[c - 1].marks[1]; break;
			case 8: cout << "\nВведите новую оценку по информатике за первый семестр: ";
				cin >> mas[c - 1].marks[2]; break;
			case 9: cout << "__________________________________" << endl << endl << endl;
				return;
			default: cout << "Неверный выбор\n";
			}
		} while (1);
	}
}


//УДАЛЕНИЕ
extern int del(int sch)
{
	if (sch == 0)
	{
		cout << "\n\nНет запиcей!\n";
	}
	else
	{
		register int d;
		cout << "\n\nВведите номер записи, которую необходимо удалить\n";
		cout << "Если необходимо удалить все записи,нажмите '99'\n";
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
		cout << "Успешно удалено\n";
	}
	cout << "__________________________________" << endl << endl << endl;
	return sch;
}