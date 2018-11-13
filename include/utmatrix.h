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

// Шаблон вектора
template <class ValType>
class TVector
{
protected:
  ValType *pVector;
  int Size;       // размер вектора
  int StartIndex; // индекс первого элемента вектора
public:
  TVector(int s = 10, int si = 0);
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
      out << v.pVector[i] << ' ';
    return out;
  }
};

template <class ValType>
TVector<ValType>::TVector(int s, int si)
{
    if (s >= 0 && s <= MAX_VECTOR_SIZE)
        Size = s;
    else
        throw "OutOfRange";
    if (si >= 0)
        StartIndex = si;
    else
        throw "OutOfRange";

    pVector = new ValType[Size];
    for (int i = 0; i < Size; i++)
    {
        pVector[i] = 0;
    }
} /*-------------------------------------------------------------------------*/

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType> &v)
{
    Size = v.Size;
    StartIndex = v.StartIndex;
    pVector = new ValType[Size];
    for (int i = 0; i < Size; i++)
    {
        pVector[i] = v.pVector[i];
    }
} /*-------------------------------------------------------------------------*/

template <class ValType>
TVector<ValType>::~TVector()
{
    delete[] pVector;
} /*-------------------------------------------------------------------------*/

template <class ValType> // доступ
ValType& TVector<ValType>::operator[](int pos)
{
    if (pos < 0 || pos > StartIndex + Size)
        throw "OUTOFRANGE";
    if (pos < StartIndex) // так как матрица верхнетреугольная, возвращаем ноль, если индекс "левее" (в матрице слева нули)
        throw "OutOfRange(BeforeStartIndex)";
    return pVector[pos - StartIndex];
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector &v) const
{
    if (this == &v) // если сравниваем с самим собой, то по-любому равно
    {
        return 1;
    }

    if (Size == v.Size && StartIndex == v.StartIndex) //если поля класса равны, переходим к сравнению динамических массивов
    {
        for (int i = 0; i < Size; i++)
        {
            if (pVector[i] != v.pVector[i]) // если какой-то элемент вектора не равен, то векторы не равны
            return 0;
        }
        return 1; //проверили все элементы. если всё ок, то равны
    }
    else
        return 0; // если поля не равны, векторы не равны
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector &v) const
{
    return !(*this == v) ; // если не равно (через предыдущий оператор)
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
    if (this != &v)
    {
        if (Size != v.Size)
        {
            delete[] pVector;
            Size = v.Size;
            pVector = new ValType[Size];
        }
        StartIndex = v.StartIndex;
        for (int i = 0; i < Size; i++)
        {
            pVector[i] = v.pVector[i];
        }
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
    TVector<ValType> vec = TVector<ValType>(*this); // копируем вектор
    for (int i = 0; i < Size; i++)
    {
        vec.pVector[i] += val;
    }
    return vec; // возвращаем копию
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
    TVector<ValType> vec = TVector<ValType>(*this); // копируем вектор
    for (int i = 0; i < Size; i++)
    {
        vec.pVector[i] -= val;
    }
    return vec; // возвращаем копию
} /*-------------------------------------------------------------------------*/

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
    TVector<ValType> vec = TVector<ValType>(*this); // копируем вектор
    for (int i = 0; i < Size; i++)
    {
        vec.pVector[i] *= val;
    }
    return vec; // возвращаем копию
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)
{
    if (Size != v.Size)
        throw "NotEqualSizeOfVectors";
    TVector<ValType> vec = TVector<ValType>(*this); // копируем вектор
    for (int i = 0; i < Size; i++)
    {
        vec.pVector[i] = this->pVector[i] + v.pVector[i];
    }
    return vec;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)
{
    if (Size != v.Size)
        throw "NotEqualSizeOfVectors";
    TVector<ValType> vec = TVector<ValType>(*this); // копируем вектор
    for (int i = 0; i < Size; i++)
    {
        vec.pVector[i] = this->pVector[i] - v.pVector[i];
    }
    return vec;
} /*-------------------------------------------------------------------------*/

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
    if (Size != v.Size)
        throw "NotEqualSizeOfVectors";
    ValType ScalarMult = 0;
    for (int i = 0; i < Size; i++)
    {
        ScalarMult += this->pVector[i] * v.pVector[i];
    }
    return ScalarMult;
} /*-------------------------------------------------------------------------*/


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

  // ввод / вывод
  friend istream& operator>>(istream &in, TMatrix &mt)
  {
    for (int i = 0; i < mt.Size; i++)
      in >> mt.pVector[i];
    return in;
  }
  friend ostream & operator<<( ostream &out, const TMatrix &mt)
  {
    for (int i = 0; i < mt.Size; i++)
      out << mt.pVector[i] << endl;
    return out;
  }
};

template <class ValType>
TMatrix<ValType>::TMatrix(int s): TVector<TVector<ValType> >(s) // вектор из s векторов по умолчанию
{
    if (s <= 0 || s > MAX_MATRIX_SIZE)
        throw "IncorrectSize";
    for (int i = 0; i < s; i++)
    {
        this->pVector[i] = TVector<ValType>(s - i, i);
    }
} /*-------------------------------------------------------------------------*/

template <class ValType> // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt):
  TVector<TVector<ValType> >(mt) {}

template <class ValType> // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt):
  TVector<TVector<ValType> >(mt) {}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const
{
	return TVector<TVector<ValType>> :: operator==(mt);
	/*
    if (this == &mt)
        return true;
    if (this->Size != mt.Size)
        return false;
    for (int i = 0; i < this->Size; i++)
    {
        if (this->pVector[i] != mt.pVector[i])
            return false;
    }
    return true; // если всё хорошо
	*/
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
    return !(*this == mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
    if (this != &mt)
    {
        if (this->Size != mt.Size) // если число строк не равно, то заново создаем вектор векторов правильного размера
        {
            delete[] this->pVector; // вектор векторов
            this->Size = mt.Size;
            this->pVector = new TVector<ValType>[this->Size];
            for (int i = 0; i < this->Size; i++)
            {
                this->pVector[i] = TVector<ValType>(this->Size - i, i);
            }
        }
        int n = this->GetSize(); // количество строк в матрице
        for (int i = 0; i < n; i++)
        {
            this->pVector[i] = mt.pVector[i]; // копируем строки матрицы
        }
    }

    return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
    if (this->Size != mt.Size)
        throw "NotEqualSizeOfMatrix";

	return TVector<TVector<ValType>> :: operator+(mt);
    /*
	TMatrix<ValType> matrix = TMatrix<ValType> (*this); // копируем матрицу
    int n = this->GetSize(); // количество строк в матрице
    for (int i = 0; i < n; i++)
    {
        matrix.pVector[i] = matrix.pVector[i] + mt.pVector[i];
    }

    return matrix;
	*/
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
    if (this->Size != mt.Size)
        throw "NotEqualSizeOfMatrix";
	return TVector<TVector<ValType>> :: operator-(mt);
    /*TMatrix<ValType> matrix = TMatrix<ValType> (*this); // копируем матрицу
    int n = this->GetSize(); // количество строк в матрице
    for (int i = 0; i < n; i++)
    {
        matrix.pVector[i] = matrix.pVector[i] - mt.pVector[i];
    }

    return matrix;
	*/
} /*-------------------------------------------------------------------------*/

// TVector О3 Л2 П4 С6
// TMatrix О2 Л2 П3 С3
#endif
