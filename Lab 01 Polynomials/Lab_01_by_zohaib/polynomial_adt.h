#include <iostream>
#include <cmath>
using namespace std;

class Polynomial
{
private:
    int *coefficients;
    int *exponents;
    int size;
    int powr;

    void mem_manager(int power)
    {
        int required = power + 1;
        if (required <= size)
            return;

        int newCapacity = size == 0 ? required : size;
        while (newCapacity < required)
        {
            newCapacity = newCapacity * 2;
        }

        int *newCoeffs = new int[newCapacity];
        int *newExps = new int[newCapacity];

        for (int i = 0; i < newCapacity; i++)
        {
            if (i < size)
            {
                newCoeffs[i] = coefficients[i];
            }
            else
            {
                newCoeffs[i] = 0;
            }
            newExps[i] = i;
        }

        delete[] coefficients;
        delete[] exponents;
        coefficients = newCoeffs;
        exponents = newExps;
        size = newCapacity;
    }

public:
    Polynomial()
    {
        coefficients = NULL;
        exponents = NULL;
        size = 0;
        powr = -1;
        mem_manager(4);
    }
    void addTerm(int coefficient, int power)
    {
        mem_manager(power);
        coefficients[power] = coefficient;
        exponents[power] = power;
        if (coefficient != 0 && power > this->powr)
        {
            this->powr = power;
        }
    }

    int getCoefficient(int power)
    {
        if (power < 0)
            return 0;
        if (power >= size)
            return 0;
        return coefficients[power];
    }

    // float operat(int value)
    // {
    //     float result = 0;
    //     for (int i = powr; i >= 0; i--)
    //     {
    //         result += (coefficients[i] * pow(value, exponents[i]));
    //     }
    //     return result;
    // }

    float operator()(int value){
        float result = 0;
        for (int i = powr; i >= 0; i--)
        {
            result += (coefficients[i] * pow(value, exponents[i]));
        }
        return result;
    }

    ~Polynomial()
    {
        delete[] coefficients;
        delete[] exponents;
        coefficients = NULL;
        exponents = NULL;
    }

    Polynomial operator+(const Polynomial &other)
    {
        Polynomial result;
        int maxPow = (this->powr > other.powr) ? this->powr : other.powr;
        result.mem_manager(maxPow);
        result.powr = -1;

        for (int i = 0; i <= maxPow; ++i)
        {
            int c1 = (i <= this->powr) ? this->coefficients[i] : 0;
            int c2 = (i <= other.powr) ? other.coefficients[i] : 0;
            int sum = c1 + c2;

            result.coefficients[i] = sum;
            result.exponents[i] = i;
            if (sum != 0 && i > result.powr)
                result.powr = i;
        }
        if (result.powr < 0)
            result.powr = 0;
        return result;
    }

    Polynomial operator-(const Polynomial &other)
    {
        Polynomial result;
        int maxPow = (this->powr > other.powr) ? this->powr : other.powr;
        result.mem_manager(maxPow);
        result.powr = -1;

        for (int i = 0; i <= maxPow; ++i)
        {
            int c1 = (i <= this->powr) ? this->coefficients[i] : 0;
            int c2 = (i <= other.powr) ? other.coefficients[i] : 0;
            int diff = c1 - c2;

            result.coefficients[i] = diff;
            result.exponents[i] = i;
            if (diff != 0 && i > result.powr)
                result.powr = i;
        }
        if (result.powr < 0)
            result.powr = 0;
        return result;
    }

    // Polynomial derivative()
    // {
    //     Polynomial result;
    //     result.mem_manager(this->powr);
    //     result.powr = -1;
    //     for (int i = 0; i <= this->powr; ++i)
    //     {
    //         result.coefficients[i] = this->coefficients[i] * this->exponents[i];
    //         cout << this->coefficients[i] * this->exponents[i] << endl;
    //         // result.addTerm(this->coefficients[i] * this->exponents[i], this->exponents[i - 1]);
    //     }
    //     return result;
    // }

    Polynomial derivative()
    {
        Polynomial result;
        if (this->powr <= 0)
        {
            result.mem_manager(0);
            result.coefficients[0] = 0;
            result.exponents[0] = 0;
            result.powr = 0;
            return result;
        }

        result.mem_manager(this->powr - 1);
        result.powr = -1;

        for (int i = 1; i <= this->powr; ++i)
        {
            int coeff = this->coefficients[i] * i;
            int newPower = i - 1;
            result.coefficients[newPower] = coeff;
            result.exponents[newPower] = newPower;
            if (coeff != 0 && newPower > result.powr)
                result.powr = newPower;
        }

        if (result.powr < 0)
            result.powr = 0;
        return result;
    }

    Polynomial antiDerivative()
    {
        Polynomial result;
        if (this->powr <= 0)
        {
            result.mem_manager(0);
            result.coefficients[0] = 0;
            result.exponents[0] = 0;
            result.powr = 0;
            return result;
        }

        result.mem_manager(this->powr - 1);
        result.powr = -1;

        for (int i = 1; i <= this->powr; ++i)
        {
            int coeff = this->coefficients[i] / (i+1);
            int newPower = i + 1;
            result.coefficients[newPower] = coeff;
            result.exponents[newPower] = newPower;
            if (coeff != 0 && newPower > result.powr)
                result.powr = newPower;
        }

        if (result.powr < 0)
            result.powr = 0;
        return result;
    }

    void addToCoefficient(int coefficient, int power)
    {
        this->coefficients[power] += power;
    }

    // Polynomial operator

    void clear()
    {
        for (int i = this->powr; i >= 0; i--)
        {
            coefficients[i] = 0;
        }
    }

    

    // Polynomial derivative

    void setCoefficient(int newCoefficient, int power)
    {
        this->coefficients[power] = newCoefficient;
    }

    friend ostream &operator<<(ostream &out, const Polynomial &p);
};

ostream &operator<<(ostream &out, const Polynomial &p)
{
    bool printedAny = false;
    // if (p.pow < 0)
    // {
    //     out << 0;
    //     return out;
    // }
    for (int i = p.powr; i >= 0; i--)
    {
        int c = p.coefficients[i];
        if (c == 0)
            continue;
        if (printedAny)
        {
            out << "+";
        }
        if (i == 0)
        {
            out << c;
        }
        else if (i == 1)
        {
            out << c << "x";
        }
        else
        {
            out << c << "x^" << i;
        }
        printedAny = true;
    }
    if (!printedAny)
    {
        out << 0;
    }
    return out;
}

int main()
{
    Polynomial p1;
    p1.addTerm(2, 2);
    p1.addTerm(3, 1);
    p1.addTerm(1, 0);
    // p1.addTerm(9, 0);
    cout << p1(2) << endl;
    // cout << p1.antiDerivative() << endl;
    // p1.clear();
    // p1.addToCoefficient(2, 2);
    // cout << p1;
    // Polynomial p2;
    // p2.addTerm(6, 4);
    // p2.addTerm(3, 2);
    // p2.addTerm(2, 0);
    // cout << p2 << endl;
    // cout << p1 - p2 << endl;
    return 0;
}