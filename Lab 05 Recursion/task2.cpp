#include<iostream>
using namespace std;

bool isPrime(int n){
    if (n < 2){
        return false;
    }
    for (int i=2; i <= n-1; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

bool isGoodNumber(const string &s, int index = 0){
    if (index == s.length()){
        return true;
    }

    int digit = s[index] - '0';
    if (index % 2 == 0){
        if (digit % 2 != 0)
            return false;
    }
    else{
        if (!isPrime(digit))
            return false;
    }

    return isGoodNumber(s, index + 1);
}

int main()
{
    string digit_strings[] = {"02468", "23478", "224365"};
    for (string digits : digit_strings)
    {
        bool is_good = isGoodNumber(digits, 0);
        cout << "Digit string: " << digits << " is " << (is_good ? "good" : "not good") << endl;
    }
    return 0;
}