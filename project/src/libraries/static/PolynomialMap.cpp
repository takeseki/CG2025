#include "PolynomialMap.h"

#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
#include <map>
#define EPSILON 1.0e-10	// zero double

using namespace std;

PolynomialMap::PolynomialMap(const PolynomialMap& other) {
    m_Polynomial = other.m_Polynomial;
}

PolynomialMap::PolynomialMap(const string& file) {
    ReadFromFile(file);
}

PolynomialMap::PolynomialMap(const double* cof, const int* deg, int n) {
    for (int i = 0; i < n; i++)
        coff(deg[i]) = cof[i];
}

PolynomialMap::PolynomialMap(const vector<int>& deg, const vector<double>& cof) {
    assert(deg.size() == cof.size());
    for (size_t i = 0; i < deg.size(); i++)
        coff(deg[i]) = cof[i];
}

double PolynomialMap::coff(int i) const
{
    auto it = m_Polynomial.find(i);
    if (it == m_Polynomial.end())
        return 0.;
    return it->second;
}



double& PolynomialMap::coff(int i) {
    return m_Polynomial[i];
}

void PolynomialMap::compress() {
    map<int, double> newtem = m_Polynomial;
    m_Polynomial.clear();
    for (const auto& term : newtem) {
        if (fabs(term.second) > EPSILON)
            coff(term.first) = term.second;
    }
}

PolynomialMap PolynomialMap::operator+(const PolynomialMap& right) const {
    PolynomialMap sum(*this);
    for(const auto& k:right.m_Polynomial){
        sum.coff(k.first)+=k.second;
    }
    sum.compress();
    return sum;
}

PolynomialMap PolynomialMap::operator-(const PolynomialMap& right) const {
    PolynomialMap diff(*this);
    for (const auto& k : right.m_Polynomial)
        diff.coff(k.first) -= k.second;
    diff.compress();
    return diff;
}

PolynomialMap PolynomialMap::operator*(const PolynomialMap& right) const {
  PolynomialMap product;
   for(const auto& k1:right.m_Polynomial){
    for(const auto& k2:m_Polynomial){
        product.coff(k1.first+k2.first)+=k1.second*k2.second;
    }
}   
    product.compress();
    return product; // you should return a correct value
}

PolynomialMap& PolynomialMap::operator=(const PolynomialMap& right) {
    m_Polynomial = right.m_Polynomial;
    return *this;
}




void PolynomialMap::Print() const {
    auto it=m_Polynomial.begin();
    if(it==m_Polynomial.end()){
        cout<<"0"<<endl;
        return;
    }
    for(;it!=m_Polynomial.end();it++){
        if(it!=m_Polynomial.begin()&&it->second>0){
            cout<<"+";
        }
        cout<<it->second;
        if(it->first>0){
            cout<<"x^"<<it->first;
        }
    }
    cout<<endl;
}

bool PolynomialMap::ReadFromFile(const string& file)
{
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
        int deg1;
        double cof1;
        f>>deg1;
        f>>cof1;
        coff(deg1)=cof1;
    }
    f.close();
    return true; // you should return a correct value

    
}

