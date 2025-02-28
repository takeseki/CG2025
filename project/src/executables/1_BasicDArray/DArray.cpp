// implementation of class DArray
#include "DArray.h"
#include<iostream>
// default constructor
DArray::DArray() {
    Init();
}





// set an array with default values
DArray::DArray(int nSize, double dValue) {
    Init();
    SetSize(nSize);
    for(int i=0;i<nSize;i++){
        SetAt(i,dValue);
    }
}






DArray::DArray(const DArray& arr) {
    m_nSize=arr.m_nSize;;
    m_pData=new double[m_nSize];
    for(int i=0;i<m_nSize;i++){
        m_pData[i]=arr.m_pData[i];
    }

}






// deconstructor
DArray::~DArray() {
    Free();
}






// display the elements of the array
void DArray::Print() const {
    std::cout<<"size="<<m_nSize<<": ";
    for(int i=0;i<m_nSize;i++){
        std::cout<<m_pData[i]<<" ";
    }
    std::cout<<std::endl;
}





// initilize the array
void DArray::Init() {
  m_pData=nullptr;
  m_nSize=0;
}






// free the array
void DArray::Free() {
    delete[] m_pData;
    m_pData=nullptr;
    m_nSize=0;
}






// get the size of the array
int DArray::GetSize() const {
    return m_nSize; // you should return a correct value
}







// set the size of the array
void DArray::SetSize(int nSize) {
    if(nSize<0){
        nSize=0;
    }
    double* pNewData=new double[nSize];
    int copysize=std::min(m_nSize,nSize);
    for(int i=0;i<copysize;i++){
        pNewData[i]=m_pData[i];
    }
    if(m_nSize<nSize){
        for(int i=m_nSize;i<nSize;i++){
            pNewData[i]=0;
        }
    }
    delete[] m_pData;
    m_pData=pNewData;
    m_nSize=nSize;
}





// get an element at an index
const double& DArray::GetAt(int nIndex) const {
    return m_pData[nIndex]; // you should return a correct value
}







// set the value of an element 
void DArray::SetAt(int nIndex, double dValue) {
    if(nIndex>=0&&nIndex<m_nSize){
        m_pData[nIndex]=dValue;
    }
}



double& DArray::operator[](int nIndex) {
    return m_pData[nIndex];
}


// overload operator '[]'
const double& DArray::operator[](int nIndex) const {
    
    return m_pData[nIndex]; // you should return a correct value
}






// add a new element at the end of the array
void DArray::PushBack(double dValue) {
    SetSize(m_nSize+1);
    m_pData[m_nSize-1]=dValue;
}





// delete an element at some index
void DArray::DeleteAt(int nIndex) {
    if(nIndex>=0&&nIndex<m_nSize){
        for(int i=nIndex;i<m_nSize-1;i++){
            m_pData[i]=m_pData[i+1];
        }
        SetSize(m_nSize-1);
    }
}






// insert a new element at some index
void DArray::InsertAt(int nIndex, double dValue) {
    if(nIndex>=0&&nIndex<=m_nSize){
        SetSize(m_nSize+1);
        for(int i=m_nSize-1;i>nIndex;i--){
            m_pData[i]=m_pData[i-1];
        }
        m_pData[nIndex]=dValue;
    }
}







// overload operator '='
DArray& DArray::operator = (const DArray& arr) {
    delete[] m_pData;

    m_nSize = arr.m_nSize;
    m_pData = new double[m_nSize];

    for (int i = 0; i < m_nSize; i++)
        m_pData[i] = arr[i];

    return *this;
}