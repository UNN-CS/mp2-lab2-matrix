// ����, ���, ���� "������ ����������������-2", �++, ���
//
// utmatrix.h - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (21.04.2015)
//
// ����������������� ������� - ���������� �� ������ ������� �������

#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// ������ �������
template <class ValType>
class TVector
{
protected:
	ValType *pVector;
	int size;       // ������ �������
	int startIndex; // ������ ������� �������� �������
public:
	TVector(int s = 10, int si = 0);
	TVector(const TVector &v);                // ����������� �����������
	~TVector();
	int GetSize() { return size; } // ������ �������
	int GetStartIndex() { return startIndex; } // ������ ������� ��������
	ValType& operator[](int pos);             // ������
	bool operator==(const TVector &v) const;  // ���������
	bool operator!=(const TVector &v) const;  // ���������
	TVector& operator=(const TVector &v);     // ������������

											  // ��������� ��������
	TVector  operator+(const ValType &val);   // ��������� ������
	TVector  operator-(const ValType &val);   // ������� ������
	TVector  operator*(const ValType &val);   // �������� �� ������

											  // ��������� ��������
	TVector  operator+(const TVector &v);     // ��������
	TVector  operator-(const TVector &v);     // ���������
	ValType  operator*(const TVector &v);     // ��������� ������������

											  // ����-�����
	friend istream& operator >> (istream &in, TVector &v)
	{
		for (int i = 0; i < v.size; i++)
			in >> v.pVector[i];
		return in;
	}
	friend ostream& operator<<(ostream &out, const TVector &v)
	{
		for (int i = 0; i < v.size; i++)
			out << v.pVector[i] << ' ';
		return out;
	}
};

template <class ValType>
TVector<ValType>::TVector(int s, int si)
{
	if ((s > MAX_VECTOR_SIZE) || (s < 0) || (si < 0)) throw - 1;
	size = s;
	pVector = new ValType[size];
	for (int i = 0; i < size; i++)
		pVector[i] = 0;
	startIndex = si;
}
template <class ValType> //����������� �����������
TVector<ValType>::TVector(const TVector<ValType> &v)
{
	size = v.size;
	startIndex = v.startIndex;
	pVector = new ValType[size];
	for (int i = 0; i < size; i++)
	{
		pVector[i] = v.pVector[i];
	}
}

template <class ValType>
TVector<ValType>::~TVector()
{
	delete[]pVector;
}

template <class ValType> // ������
ValType& TVector<ValType>::operator[](int pos)
{
	if ((pos - startIndex < 0) || (pos - startIndex > size)) throw - 1;
	return pVector[pos - startIndex];
}
template <class ValType> // ���������
bool TVector<ValType>::operator==(const TVector &v) const
{
	if ((size != v.size) || (startIndex != v.startIndex)) return false;
	for (int i = 0; i < size; i++)
		if (pVector[i] != v.pVector[i]) return false;
	return true;
}
template <class ValType> // ���������
bool TVector<ValType>::operator!=(const TVector &v) const
{
	return !(*this == v);
}

template <class ValType> // ������������
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
	if (this != &v)
	{
		delete[] pVector;
		size = v.size;
		startIndex = v.startIndex;
		pVector = new ValType[size];
		for (int i = 0; i < size; i++)
		{
			pVector[i] = v.pVector[i];
		}
	}
	return *this;
}

template <class ValType> // ��������� ������
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
	TVector<ValType> tmp(size, startIndex);
	tmp = *this;
	for (int i = 0; i < size; i++)
		tmp.pVector[i] += val;
	return tmp;
}

template <class ValType> // ������� ������
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
	TVector<ValType> tmp(size, startIndex);
	tmp = *this;
	for (int i = 0; i < size; i++)
		tmp.pVector[i] -= val;
	return tmp;
}
template <class ValType> // �������� �� ������
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
	TVector<ValType> tmp(size, startIndex);
	tmp = *this;
	for (int i = 0; i < size; i++)
		tmp.pVector[i] *= val;
	return tmp;
}

template <class ValType> // ��������
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)
{
	if ((size != v.size)||(startIndex != v.startIndex)) throw - 1;
	TVector<ValType> tmp(size, startIndex);
	tmp = *this;
	for (int i = 0; i < size; i++)
		tmp.pVector[i] += v.pVector[i];
	return tmp;
}

template <class ValType> // ���������
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)
{
	if ((size != v.size) || (startIndex != v.startIndex)) throw - 1;
	TVector<ValType> tmp(size, startIndex);
	tmp = *this;
	for (int i = 0; i < size; i++)
		tmp.pVector[i] -= v.pVector[i];
	return tmp;
}

template <class ValType> // ��������� ������������
ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
	ValType tmp = 0;
	if (size != v.size) throw - 1;
	for (int i = 0; i < size; i++)
		tmp += pVector[i] * v.pVector[i];
	return tmp;
}


// ����������������� �������
template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix &mt);                    // �����������
	TMatrix(const TVector<TVector<ValType> > &mt); // �������������� ����
	bool operator==(const TMatrix &mt) const;      // ���������
	bool operator!=(const TMatrix &mt) const;      // ���������
	TMatrix& operator= (const TMatrix &mt);        // ������������
	TMatrix  operator+ (const TMatrix &mt);        // ��������
	TMatrix  operator- (const TMatrix &mt);        // ���������

												   // ���� / �����
	friend istream& operator >> (istream &in, TMatrix &mt)
	{
		for (int i = 0; i < mt.size; i++)
			in >> mt.pVector[i];
		return in;
	}
	friend ostream & operator<<(ostream &out, const TMatrix &mt)
	{
		for (int i = 0; i < mt.size; i++)
			out << mt.pVector[i] << endl;
		return out;
	}
};

template <class ValType>
TMatrix<ValType>::TMatrix(int s) : TVector< TVector<ValType> > (s)
{	
	if ((s > MAX_MATRIX_SIZE)||(s <= 0)) throw -1;
	for (int i = 0; i < s; i++)
		this->pVector[i] = TVector<ValType>(s - i, i);
}
template <class ValType> // ����������� �����������
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt) :
	TVector<TVector<ValType> >(mt)
{
	for (int i = 0; i < this->size; i++)
		this->pVector[i] = TVector<ValType>(mt.pVector[i]);;
}

template <class ValType> // ����������� �������������� ����
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt) :TVector<TVector<ValType> >(mt)
{}

template <class ValType> // ���������
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const
{
	return TVector<TVector<ValType> >::operator==(mt);
}

template <class ValType> // ���������
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
	return !(*this == mt);
}

template <class ValType> // ������������
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
	if (this != &mt)
	{
		this->size = mt.size;
		delete[] this->pVector;
		this->pVector = new TVector<ValType>[this->size];
		for (int i = 0; i < this->size; i++)
			this->pVector[i] = mt.pVector[i];
	}
	return *this;
}

template <class ValType> // ��������
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
	if (this->size != mt.size) throw -1;
	TMatrix<ValType> tmp(this->size);
	for (int i = 0; i < this->size; i++)
		tmp[i] = this->pVector[i] + mt.pVector[i];
	return tmp;
}

template <class ValType> // ���������
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
	if (this->size != mt.size) throw - 1;
	TMatrix<ValType> tmp(this->size);
	for (int i = 0; i < this->size; i++)
		tmp[i] = this->pVector[i] - mt.pVector[i];
	return tmp;
}

// TVector �3 �2 �4 �6
// TMatrix �2 �2 �3 �3
#endif