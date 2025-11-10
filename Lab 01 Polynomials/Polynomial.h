
#include<iostream>
#include<cmath>
using namespace std;

class Polynomial{
    int cofficent[100];
    int size=100;

    public:
    void setpolynomial(int,int);
    Polynomial();
    // ~Polynomial();
    void addTerm(int, int);
    int getcofficent(int);
    int getdegree();  // means highest index of array
    int operatorr(int);

    Polynomial(const Polynomial& other);  
    void clear();
    void setCofficent(int,int);
    void addtocofficent(int,int);
    Polynomial operator+(const Polynomial& rhs);
    Polynomial operator-(const Polynomial& rhs);
};