#pragma once
#include <cstdio>
#include <cstdlib>

#include <typeinfo>
#include <cstring>
#include <iostream>
#include <cassert>

template <class DataType>
// interfaces of Dynamic Array class DArray
class DArray {
public:
    DArray(); // default constructor
    DArray(int nSize, DataType dValue = 0); // set an array with default values
    DArray(const DArray& arr); // copy constructor
    ~DArray(); // deconstructor

    void Print() const; // print the elements of the array

    int GetSize() const; // get the size of the array
    void SetSize(int nSize); // set the size of the array

    const DataType& GetAt(int nIndex) const; // get an element at an index
    void SetAt(int nIndex, DataType dValue); // set the value of an element

    DataType& operator[](int nIndex); // overload operator '[]'
	const DataType& operator[](int nIndex) const; // overload operator '[]'

    void PushBack(DataType dValue); // add a new element at the end of the array
    void DeleteAt(int nIndex); // delete an element at some index
    void InsertAt(int nIndex,DataType dValue); // insert a new element at some index

    DArray& operator = (const DArray& arr); //overload operator '='

private:
    DataType* m_pData; // the pointer to the array memory
    int m_nSize; // the size of the array
    int m_nMax;

private:
    void Init(); // initilize the array
    void Free(); // free the array
    void Reserve(int nSize); // allocate enough memory
};






template <class DataType>

// default constructor
DArray<DataType>::DArray() {
    Init();
}

template <class DataType>
// set an array with default values
DArray<DataType>::DArray(int nSize, DataType dValue)
{
    m_pData=new DataType[nSize];
    m_nSize=nSize;
    m_nMax=nSize;
    for (int i = 0; i < nSize; i++)
        m_pData[i] = dValue;
}

template <class DataType>
DArray<DataType>::DArray(const DArray& arr)
{
    m_pData=new DataType[arr.m_nSize];
    m_nSize=arr.m_nSize;
    m_nMax=arr.m_nSize;
    for (int i = 0; i < m_nSize; i++)
        m_pData[i] = arr.m_pData[i];
}


template <class DataType>
DArray<DataType>::~DArray() {
    Free();
}

// display the elements of the array


template <class DataType>
void DArray<DataType>::Print() const {
    std::cout << "size=" << m_nSize << ": ";
    for(int i=0;i<m_nSize;i++){
        std::cout<<m_pData[i]<<" ";
    }
    std::cout<<std::endl;
}

// initilize the array


template <class DataType>
void DArray<DataType>::Init() {
    m_pData = nullptr;
    m_nSize = 0;
    m_nMax = 0;
}

// free the array


template <class DataType>
void DArray<DataType>::Free() {
    delete[] m_pData;
    m_pData = nullptr;

    m_nSize = 0;
    m_nMax = 0;
}

// get the size of the array


template <class DataType>
int DArray<DataType>::GetSize() const {
    return m_nSize;
}



template <class DataType>
void DArray<DataType>::Reserve(int nSize) {
    if(nSize<=m_nMax){
        return;
    }
    
    while (m_nMax<nSize)
    {
    m_nMax=m_nMax==0 ? 1 : m_nMax*2;
    }
    
    DataType* pData = new DataType[m_nMax];
    for (int i = 0; i < m_nSize; ++i) {
        pData[i] = m_pData[i];
    }

    delete[] m_pData;
    m_pData = pData;
}

// set the size of the array



template <class DataType>
void DArray<DataType>::SetSize(int nSize) {
    if (m_nSize == nSize)
        return;
    
    Reserve(nSize);

    for (int i = m_nSize; i < nSize; i++){
        m_pData[i] = static_cast<DataType>(0);
    }

    m_nSize = nSize;
}

// get an element at an index
template <class DataType>
const DataType& DArray<DataType>::GetAt(int nIndex) const {
    assert(nIndex >= 0 && nIndex < m_nSize);
    return m_pData[nIndex];
    
}

// set the value of an element


template <class DataType>
void DArray<DataType>::SetAt(int nIndex, DataType dValue) {
    assert(nIndex >= 0 && nIndex < m_nSize)
    m_pData[nIndex] = dValue;
}



// add a new element at the end of the array

template<class DataType>
const DataType& DArray<DataType>::operator[](int nIndex) const {
	assert(nIndex >= 0 && nIndex < m_nSize);
	return m_pData[nIndex];
}



template <class DataType>
void DArray<DataType>::PushBack( DataType dValue) {
    Reserve(m_nSize + 1);
    m_pData[m_nSize] = dValue;
    m_nSize++;
}

// delete an element at some index

template <class DataType>
void DArray<DataType>::DeleteAt(int nIndex) {
    assert(nIndex >= 0 && nIndex<m_nSize);
    for(int i = nIndex + 1; i < m_nSize; i++){
        m_pData[i - 1] = m_pData[i];
    }
    m_nSize--;
    
}

// insert a new element at some index

template <class DataType>
void DArray<DataType>::InsertAt(int nIndex, DataType dValue) {
    assert(nIndex >=0 && nIndex<=m_nSize);
     Reserve(m_nSize + 1);
    for(int i = m_nSize; i > nIndex; i--){
        m_pData[i] = m_pData[i - 1];
    }
    m_pData[nIndex]=dValue;
    m_nSize++;
    } // nIndex == m_nSize is legal



// overload operator '='


template<class DataType>
DArray< DataType>& DArray< DataType>::operator = (const DArray& arr) {
	if (this == &arr)
		return *this;

	delete[] m_pData;

	m_nSize = arr.m_nSize;
	m_nMax = arr.m_nMax;

	m_pData = new  DataType[m_nMax];

	for (int i = 0; i < m_nSize; i++)
		m_pData[i] = arr[i];

	return *this;
}