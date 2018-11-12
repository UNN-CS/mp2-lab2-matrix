// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include <cstdlib>
#include "utmatrix.h"
using namespace std;
//---------------------------------------------------------------------------

void main()
{
	try
	{
		TMatrix<int> a(5), b(5), c(5), d(5);
		int i, j, size, num;

		setlocale(LC_ALL, "Russian");
		cout << "Тестирование программ поддержки представления треугольных матриц" << endl;
		cout << "Введите размер матриц A и B:" << endl;
		cin >> size;
		TMatrix<int> A(size), B(size), Temp(size);
		cout << "Введите 0, если хотите ввести матрицы вручную, или 1 для автоматического заполнения." << endl;
		cin >> num;
		if (num == 0)
		{
			cout << "Введите матрицу А:" << endl;
			cin >> A;
			cout << "Введите матрицу B" << endl;
			cin >> B;
		}
		else
		{
			for (i = 0; i < size; i++)
				for (j = i; j < size; j++ )
				{
					A[i][j] = rand() % 11;
					B[i][j] = rand() % 11;
				}
			cout << "Матрица А:" << endl;
			cout << A << endl;
			cout << "Матрица В:" << endl;
			cout << B << endl;
		}
		cout << "A = B ?" << endl;
		if (A == B)
			cout << "Да." << endl;
		else
			cout << "Нет." << endl;
		cout << "A + B = ?" << endl;
		Temp = (A + B);
		cout << Temp << endl;
		cout << "A - B = ?" << endl;
		Temp = A - B;
		cout << Temp << endl;
	}
	catch(const string *err)
	{
		cout << err << endl;
	}
}
//---------------------------------------------------------------------------