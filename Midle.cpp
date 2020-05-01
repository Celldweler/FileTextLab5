#include "Stdafx.h"
/*
Дан файл f, компоненты которого являются 
действительными числами. Найти последнюю компоненту
файла
*/
using namespace std;
void midle()
{
	system("cls");
	std::cout << "\n\t\tMidle task level: ";
	std::fstream f_out_in;
	f_out_in.open("f.txt", ios::out | ios::in | ios::trunc);
	for (double i = 0.9; i < (2+rand()%100); i+=1.9)
	{
		f_out_in << i << " ";
	}
	f_out_in.seekp(0, ios::beg);
	double var;
	cout << "\nЧисла хранящиеся в файле <<f.txt>>: \n\t";
	while (f_out_in >> var)
	{
		cout << var << " ";
		
	}
	cout << "\nПоследняя компонента файла: " << var;
			f_out_in.close();
	cout << "\nНажмите произвольную клавишу для завершения програмы\n";
	getchar();
	cin.ignore(cin.rdbuf()->in_avail());
}