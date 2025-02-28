#include "PolynomialList.h"
#include <iostream>
#include <fstream>
#include <assert.h>
#include <cmath>
#include <algorithm>
#define EPSILON 1.0e-10    
using namespace std;

PolynomialList::PolynomialList(const PolynomialList& other) {
    m_Polynomial = other.m_Polynomial;
}

PolynomialList::PolynomialList(const string& file) {
    ReadFromFile(file);
}

PolynomialList::PolynomialList(const double* cof, const int* deg, int n) {
   for(int i=0;i<n;i++){
    AddOneTerm(Term(deg[i],cof[i]));
   }
}

PolynomialList::PolynomialList(const vector<int>& deg, const vector<double>& cof) {
    for(int i=0;i<deg.size();i++){
        AddOneTerm(Term(deg[i],cof[i]));
    }
}

double PolynomialList::coff(int i) const {
    for(const Term& k:m_Polynomial){
        if(k.deg<i)
        break;
        if(k.deg==i)
        return k.cof;
    }
    return 0.; // you should return a correct value
}

double& PolynomialList::coff(int i) {
    return AddOneTerm(Term(i,0)).cof;
      
    }//？

void PolynomialList::compress() {
    auto it= m_Polynomial.begin();
    while(it!=  m_Polynomial.end()){
     if(fabs((*it).cof)<EPSILON)
      it=m_Polynomial.erase(it);
     else
      it++;
    }
 }
PolynomialList PolynomialList::operator+(const PolynomialList& right) const {
    PolynomialList sum(*this);
    for(const auto& k:right.m_Polynomial){
        sum.AddOneTerm(k);
    }
    sum.compress();
    return sum;
}
PolynomialList PolynomialList::operator-(const PolynomialList& right) const {
    PolynomialList diff(*this);
    for(const auto& k:right.m_Polynomial){
        diff.AddOneTerm(Term(k.deg,-k.cof));
    }
    diff.compress();
    return diff; // you should return a correct value
}
PolynomialList PolynomialList::operator*(const PolynomialList& right) const {
    PolynomialList product;
   for(const auto& k1:right.m_Polynomial){
    for(const auto& k2:m_Polynomial){
        product.AddOneTerm(Term(k1.deg+k2.deg,k1.cof*k2.cof));
    }
}
    return product; // you should return a correct value
}

PolynomialList& PolynomialList::operator=(const PolynomialList& right) {
    m_Polynomial = right.m_Polynomial;
    return *this;
}
void PolynomialList::Print() const {
    auto it=m_Polynomial.begin();
    if(it==m_Polynomial.end()){
        cout<<"0"<<endl;
        return;
    }
    for(;it!=m_Polynomial.end();it++){
        if(it!=m_Polynomial.begin()&&it->cof>0){
            cout<<"+";
        }
        cout<<it->cof;
        if(it->deg>0){
            cout<<"x^"<<it->deg;
        }
    }
    cout<<endl;
}

bool PolynomialList::ReadFromFile(const string& file) {
    m_Polynomial.clear();
    ifstream f;
    f.open(file.c_str());
    if(!f.is_open()){
        cout<<"ERROR::PolynomialList::ReadFromFile:"<<endl
        <<"\t"<<"file ["<<file<<"] opens failed"<<endl;
        return false;
    }
    char ch;
    int n;
    f>>ch;
    f>>n;
    for(int i=0;i<n;i++){
        Term value;
        f>>value.deg;
        f>>value.cof;
        AddOneTerm(value);
    }
    f.close();
    return true; // you should return a correct value
}

PolynomialList::Term& PolynomialList::AddOneTerm(const Term& term) {
    auto it=m_Polynomial.begin();
    for(;it!=m_Polynomial.end();it++){
        if(it->deg==term.deg){
            it->cof+=term.cof;
            return *it;
        }
        if(it->deg>term.deg){
            break;
        }
    }
    return *m_Polynomial.insert(it,term);
}