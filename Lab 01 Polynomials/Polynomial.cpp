#include"Polynomial.h"

void Polynomial:: setpolynomial(int cofi,int power)
{
    // cofficent = new int[power];

    for(int i=0; i<size; i++){
        cofficent[i] = 0;
    }

    cofficent[0] = 1;
    cofficent[power] = cofi;
} 

Polynomial::Polynomial()
{
    // cofficent = new int[size];

    for(int i=0; i<size; i++){
    cofficent[i] = 0;
    }
    
    cofficent[0] = 1;

}

// Polynomial::~Polynomial()
// {
//     delete[] cofficent;
// }

void Polynomial::addTerm(int cofi, int power)
{
    cofficent[power] = cofi;

}

int Polynomial:: getcofficent(int power)
{
    return cofficent[power];
}

int Polynomial:: getdegree()
{
    int degree = 0;
    for(int i=99; i!=0; i--){
        if(cofficent[i]!=0){
            degree = i;
            break;
        }
    }
    return degree;
}

int Polynomial:: operatorr(int x){
    int px=0;

    for(int i=0;i<size; i++){
        px = px + (cofficent[i]*(pow(i,x)));
    }

    return px;
}

void Polynomial:: clear(){
    for(int i=0; i<size; i++){
        cofficent[i] = 0;
    }
} 

Polynomial::Polynomial(const Polynomial& other){
    size = other.size;
    for(int i=0; i<size; i++){
        cofficent[i] = other.cofficent[i];
    }
}

void Polynomial:: setCofficent(int newcofi, int power){
    cofficent[power] = newcofi;
}

void Polynomial:: addtocofficent(int cofi, int power){
    cofficent[power] = cofficent[power] + cofi;
}

Polynomial Polynomial:: operator+(const Polynomial& rhs){
    Polynomial p;
    for(int i=0; i<size; i++){
      p.cofficent[i]  = this->cofficent[i] + rhs.cofficent[i];
    }
    return p;
}

Polynomial Polynomial:: operator-(const Polynomial& rhs){
    Polynomial p;
    for(int i=0; i<size; i++){
      p.cofficent[i]  = this->cofficent[i] - rhs.cofficent[i];
    }
    return p;
}
