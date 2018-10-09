// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// utmatrix.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
//
// Верхнетреугольная матрица - реализация на основе шаблона вектора

#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include <iostream>
#include <algorithm>
#include <cmath>

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
    for (int i = 0; i < v.StartIndex; ++i)
      out << "0 ";
    for (int i = 0; i < v.Size; i++)
      out << v.pVector[i] << ' ';
    return out;
  }
};

template <class ValType>
TVector<ValType>::TVector(int s, int si)
{
  if (s <= 0 || s > MAX_VECTOR_SIZE || si < 0)
    throw(-1);

  Size = s;
  StartIndex = si;

  pVector = new ValType[Size];
} /*-------------------------------------------------------------------------*/

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType> &v)
{
  Size = v.Size;
  StartIndex = v.StartIndex;

  pVector = new ValType[Size];

  copy(v.pVector, v.pVector + Size, pVector);
} /*-------------------------------------------------------------------------*/

template <class ValType>
TVector<ValType>::~TVector()
{
  delete[] pVector;
} /*-------------------------------------------------------------------------*/

template <class ValType> // доступ
ValType& TVector<ValType>::operator[](int pos)
{
  int rPos = pos - StartIndex;
  
  if (rPos < 0 || rPos >= Size)
    throw(-2);

  return pVector[rPos];
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector &v) const
{
  if (this == &v)
    return true;

  if (Size != v.Size || StartIndex != v.StartIndex)
    return false;
  
  if (mismatch(pVector, pVector + Size, v.pVector).first != pVector + Size)
    return false;
  
  return true;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector &v) const
{
  return !operator==(v);
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
  if (this != &v)
  {
    if (Size != v.Size)
    {
      Size = v.Size;
      delete[] pVector;
      pVector = new ValType[Size];
    }

    StartIndex = v.StartIndex;

    copy(v.pVector, v.pVector + Size, pVector);
  }

  return *this;
} /*-------------------------------------------------------------------------*/


template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
  TVector<ValType> ret(*this);
  ValType *pr = ret.pVector, *end = ret.pVector + ret.Size;

  while (pr != end)
    *pr++ = *pr + val;

  return ret;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
  TVector<ValType> ret(*this);
  ValType *pr = ret.pVector, *end = ret.pVector + ret.Size;

  while (pr != end)
    *pr++ = *pr - val;

  return ret;
} /*-------------------------------------------------------------------------*/

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
  TVector<ValType> ret(*this);
  ValType *pr = ret.pVector, *end = ret.pVector + ret.Size;

  while (pr != end)
    *pr++ = *pr * val;

  return ret;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)
{
  if (Size != v.Size || StartIndex != v.StartIndex)
    throw(-2);

  TVector<ValType> ret(Size, StartIndex);
  ValType *p1 = pVector, *p2 = v.pVector, *pr = ret.pVector, *end = ret.pVector + ret.Size;

  while (pr != end)
    *pr++ = *p1++ + *p2++;

  return ret;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)
{
  if (Size != v.Size || StartIndex != v.StartIndex)
    throw(-2);

  TVector<ValType> ret(Size, StartIndex);
  ValType *p1 = pVector, *p2 = v.pVector, *pr = ret.pVector, *end = ret.pVector + ret.Size;

  while (pr != end)
    *pr++ = *p1++ - *p2++;

  return ret;
} /*-------------------------------------------------------------------------*/

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
  if (Size != v.Size || StartIndex != v.StartIndex)
    throw(-2);

  ValType ret = 0;
  ValType *p1 = pVector, *p2 = v.pVector, *end1 = pVector + Size;

  while (p1 != end1)
    ret = ret + *p1++ * *p2++;

  return ret;
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
TMatrix<ValType>::TMatrix(int s): TVector<TVector<ValType> >(s)
{
  if (s > MAX_MATRIX_SIZE)
    throw(-1);

  for (int i = 0; i < this->Size; ++i)
    this->pVector[i] = TVector<ValType>(this->Size - i, i);
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
  if (this == &mt)
    return true;

  if (this->Size != mt.Size)
    return false;

  if (mismatch(this->pVector, this->pVector + this->Size, mt.pVector).first != this->pVector + this->Size)
    return false;

  return true;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
  return !operator==(mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
  if (this != &mt)
  {
    if (this->Size != mt.Size)
    {
      this->Size = mt.Size;
      delete[] this->pVector;
      this->pVector = new TVector<ValType>[this->Size];
    }

    copy(mt.pVector, mt.pVector + mt.Size, this->pVector);
  }

  return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
  if (this->Size != mt.Size)
    throw(-2);

  TMatrix<ValType> ret(this->Size);
  TVector<ValType> *p1 = this->pVector, *p2 = mt.pVector, *pr = ret.pVector, *end = ret.pVector + ret.Size;

  while (pr != end)
    *pr++ = *p1++ + *p2++;

  return ret;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
  if (this->Size != mt.Size)
    throw(-2);

  TMatrix<ValType> ret(this->Size);
  TVector<ValType> *p1 = this->pVector, *p2 = mt.pVector, *pr = ret.pVector, *end = ret.pVector + ret.Size;

  while (pr != end)
    *pr++ = *p1++ - *p2++;

  return ret;
} /*-------------------------------------------------------------------------*/

// TVector О3 Л2 П4 С6
// TMatrix О2 Л2 П3 С3
#endif
