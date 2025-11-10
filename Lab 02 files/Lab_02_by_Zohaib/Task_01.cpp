#include <iostream>
using namespace std;

void printND(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << 'I' << i;
        for (int j = i + 1; j <= n; j++)
        {
            cout << 'U' << j;
        }
        if(i!=n)
            cout << " + ";
    }
}

int main()
{
    printND(3);
    return 0;
}