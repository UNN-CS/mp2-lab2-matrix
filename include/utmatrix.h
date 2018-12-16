// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// utmatrix.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
//
// Верхнетреугольная матрица - реализация на основе шаблона вектора

#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include <iostream>

using namespace std;
const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

enum exception { BADSIZE = 1, BADINDEX};


// Шаблон вектора
template <class ValType>
class TVector
{
protected:
	// размер вектора
	int StartIndex; // индекс первого элемента вектора
public:
	TVector(int s = 1, int si = 0);
	TVector(const TVector &v);                // конструктор копирования
	~TVector();
	int GetSize()      { return Size;       } // размер вектора
	int GetStartIndex(){ return StartIndex; } // индекс первого элемента
	ValType& operator[](int pos);             // доступ
	bool operator==(const TVector &v) const;  // сравнение
	bool operator!=(const TVector &v) const;  // сравнение
	TVector& operator=(const TVector &v);     // присваивание

	// скалярные операции
	TVector  operator+(const ValType &val);   // прибавить скаляр
	TVector  operator-(const ValType &val);   // вычесть скаляр
	TVector  operator*(const ValType &val);   // умножить на скаляр

	// векторные операции
	TVector  operator+(const TVector &v);     // сложение
	TVector  operator-(const TVector &v);     // вычитание
	ValType  operator*(const TVector &v);     // скалярное произведение

	// ввод-вывод
	friend istream& operator>>(istream &in, TVector &v)
	{
		for (int i = 0; i < v.Size; i++)
			in >> v.pVector[i];
		return in;
	}
	friend ostream& operator<<(ostream &out, const TVector &v)
	{
		for (int i = 0; i < v.Size; i++)
			out << v.pVector[i]  << ' ';
		return out;
	}

	ValType *pVector;
	int Size;
};

template <class ValType>
TVector<ValType>::TVector(int s, int si)
{

	if (s <= 0 || s > MAX_VECTOR_SIZE)
		throw BADSIZE;
	if (0 > si || si >= s)
		throw BADINDEX;
	Size = s;
	StartIndex = si;
	pVector = new ValType[s];
	for (int i = 0; i < Size; i++)
		this->pVector[i] = ValType();
}


template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType> &v)
{

	if (v.Size <= 0 || v.Size > MAX_VECTOR_SIZE)
		throw BADSIZE;
	if (0 > v.StartIndex || v.StartIndex >= v.Size)
		throw BADINDEX;
	this->Size = v.Size;
	this->StartIndex = v.StartIndex;
	pVector = new ValType[this->Size];
	for (int i = 0; i <this-> Size; i++)
		this->	pVector[i] = v.pVector[i];
}

template <class ValType>
TVector<ValType>::~TVector()
{
	delete []pVector;
}

template <class ValType> // доступ
ValType& TVector<ValType>::operator[](int pos)
{
	//if (pos-StartIndex >= Size || pos-StartIndex < 0)
	//	throw BADINDEX;
	return this->pVector[pos];
}

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector &v) const
{
	if (this->Size != v.Size)
		throw BADINDEX;
	bool s = true;
	for (int i = 0; i < Size; i++)
	{
		s = this->pVector[i] == v.pVector[i];
		if (!s)
			break;
	}
	return s;
}

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector &v) const
{
	return !this->operator==(v);
}

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
	if (v.Size <= 0 || v.Size > MAX_VECTOR_SIZE)
		throw BADSIZE;
	if (0 > v.StartIndex || v.StartIndex >= v.Size)
		throw BADINDEX;

	this->Size = v.Size;
	this->StartIndex = v.StartIndex;
	this->pVector = new ValType[this->Size];
	for (int i = 0; i < this->Size; i++)
		this->pVector[i] = v.pVector[i];
	return *this;
}

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
	TVector <ValType> a(*this);
	for (int i = 0; i < this->Size; i++)
	{
		a.pVector[i] += val;
	}
	return a;
}

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
	TVector <ValType> a(*this);
	for (int i = 0; i < this->Size; i++)
	{
		a.pVector[i] -= val;
	}
	return a;
}

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
	TVector <ValType> a(*this);
	for (int i = 0; i <this->Size; i++)
	{
		a.pVector[i] *= val;
	}
	return a;
}

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)
{
	if (this->Size != v.Size)
		throw BADSIZE;
	TVector<ValType> sum (*this);
	for (int i = 0; i < sum.Size; i++)
	{
		sum.pVector[i] = sum.pVector[i]+ v.pVector[i];
	}
	return sum;
}

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)
{
	if (this->Size != v.Size)
		throw BADSIZE;
	TVector<ValType> temp(*this);
	for (int i = 0; i < temp.Size; i++)
	{
		temp.pVector[i] -= v.pVector[i];
	}
	return temp;
}

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
	if (this->Size != v.Size)
		throw BADSIZE;
	TVector<ValType> multiple(*this);
	for (int i = 0; i < multiple.Size; i++)
	{
		multiple.pVector[i] *= v.pVector[i];
	}
	return multiple;
}


// Верхнетреугольная матрица
template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix &mt);                    // копирование
	TMatrix(const TVector<TVector<ValType> > &mt); // преобразование типа
	bool operator==(const TMatrix &mt) const;      // сравнение
	bool operator!=(const TMatrix &mt) const;      // сравнение
	TMatrix& operator= (const TMatrix &mt);        // присваивание
	TMatrix  operator+ (const TMatrix &mt);        // сложение
	TMatrix  operator- (const TMatrix &mt);        // вычитание
	TMatrix inventory();
	TMatrix  operator/(const TMatrix &m);
	TMatrix operator*(const TMatrix &m);

	// ввод / вывод
	friend istream& operator>>(istream &in, TMatrix &mt)
	{
		for (int i = 0; mt.Size > i; i++)
			in >> mt.pVector[i];
		return in;
	}
	friend ostream & operator<<( ostream &out, const TMatrix &mt)
	{
		for (int i = 0; i < mt.Size; i++)
			out << mt.pVector[i] << endl;
		return out;
	}
	double sumNotEven()
	{
		double ret = 0;
		for (int i = 0; i < Size; i++)
		{
			for (int x = i; x < Size; x++)
			{
				ret += pVector[i][x] % 2 == 0 ? 0 : pVector[i][x];
			}
		}

		return ret;
	}
};

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator*(const TMatrix<ValType> &m)
{
	TMatrix<ValType> temp(Size);

	for (size_t i = 0; i < this->Size; i++)
		for (size_t j = 0; j <Size; j++)
		{
			for (size_t k = 0; k < Size; k++)
				temp[i][j]= temp[i][j]+ (this->pVector[i][k] * m.pVector[k][j]);
		}
	return temp;
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::inventory()
{
	TMatrix<ValType> temp(*this);
	TMatrix<ValType> temp1(Size);
	for (size_t i = 0; i < Size; i++)
	{
		temp1[i][i]=1;
	}
	//прямой ход методом Гаусса
	double a, b;
	for (size_t i = 0; i < Size; i++)
	{
		a = temp[i][i];
		for (size_t j = i + 1; j < Size; j++)
		{
			b = temp[j][i];
			for (size_t k = 0; k < Size; k++)
			{
				temp[j][k]= temp[i][k] * b - temp[j][k] * a;
				temp1[j][k]= temp1[i][k] * b - temp1[j][k] * a;
			}
		}
	}
	//обратный ход нахождения элементов обратной матрицы
	double sum;
	for (size_t i = 0; i < Size; i++)
	{
		for (int j = Size - 1; j >= 0; j--)
		{
			sum = 0;
			for (size_t k = Size - 1; k > j; k--)
				sum += temp[j][k] * temp1[k][i];

			if (temp[j][j] == 0)
				throw 7;

			temp1[j][i]= (temp1[j][i] - sum) / temp[j][j];
		}
	}
	return temp1;
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator/(const TMatrix &m)
{
	TMatrix<ValType> temp(m);
	ValType y = ValType();
	for (int i = 0; i < Size -1; i++)
	{
		y = temp[i][i] * temp[i + 1][i + 1];
	}
	if (y == 0)
		throw 5;
	temp = temp.inventory();
	TMatrix<ValType> temp1(*this);
	return temp1*temp;
}

template <class ValType>
TMatrix<ValType>::TMatrix(int s)
{
	if (s <= 0 || s > MAX_MATRIX_SIZE)
		throw BADSIZE;
	this->Size = s;
	this->StartIndex = 0;
	{
		this->pVector = new TVector <ValType>[s];
	}
	for (int i = 0; i <this-> s; i++)
	{
		this->pVector[i] = TVector<ValType>(s, i);
	}
}

template <class ValType> // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt):TVector<TVector<ValType>>(mt.Size)
{
	if (mt.Size <= 0 || mt.Size > MAX_MATRIX_SIZE)
		throw BADSIZE;
	this->Size = mt.Size;
	this->StartIndex = 0;
	pVector = new TVector <ValType>[this->Size];
	for (int i = 0; i < this->Size; i++)
	{
		this->pVector[i] = TVector<ValType>(mt.pVector[i]); ;
	}
}

template <class ValType> // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt):TVector<ValType>(mt)
{
	if (mt.Size <= 0 || mt.Size > MAX_MATRIX_SIZE)
		throw BADSIZE;
	this->Size = mt.Size;
	this->StartIndex = 0;
	for (int i = 0; i < mt.Size; i++)
	{
		if (mt.Size != mt.pVector[i].Size)
			throw BADSIZE;
	}

	this->pVector = new TVector <ValType>[this->Size];
	for (int i = 0; i < this->Size; i++)
	{
		this->pVector[i] = mt.pVector[i];
	}
}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const
{
	if (mt.Size != Size)
		throw false;

	bool flag = true;
	for (int i = 0; i < this->Size; i++)
	{
		flag = this->pVector[i] == mt.pVector[i];
		if (!flag)
			return false;
	}
	return true;
}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
	return !this->operator==(mt);
}

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
//	delete pVector;
	Size = mt.Size;
	this->pVector = new TVector <ValType>[Size];
	for (int i = 0; i < this->Size; i++)
	{
		this->pVector[i] = mt.pVector[i];
	}
	return *this;
}

template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
	if (mt.Size != this->Size)
		throw BADSIZE;

	TMatrix<ValType> temp(*this);

	for (int i = 0; i < this->Size; i++)
	{
		temp.pVector[i] = temp.pVector[i]+ mt.pVector[i];
	}
	return temp;
}

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
	if (mt.Size != this->Size)
		throw BADSIZE;

	TMatrix<ValType> temp(*this);

	for (int i = 0; i < this->Size; i++)
	{
		temp.pVector[i] - mt.pVector[i];
	}

	return temp;

}

#endif
