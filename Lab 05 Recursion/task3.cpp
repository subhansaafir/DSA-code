#include <iostream>
using namespace std;

int countWays(int numStairs){
    if (numStairs == 1){
        return 1;
    }
    if (numStairs == 2){
        return 2;
    }
    return countWays(numStairs-1) + countWays(numStairs-2);
}

int main(){
    cout << countWays(6) << endl;
    return 0;
}