#include <iostream>
using namespace std;

int countSquares(int k,int cx,int cy,int px,int py){
    if (k < 1 || k > 512)
    return 0;
    
    int noofsquares = 0;

    int top = cy - k;
    int bottom = cy + k;
    int left = cx - k;
    int right = cx + k;

    if (py >= top && py <= bottom && px >= left && px <= right){
        noofsquares = 1;
    }

    if (k == 1){
        return noofsquares;
    }

    int half = k/2;
    noofsquares += countSquares(half,cx - k,cy - k,px, py);
    noofsquares += countSquares(half,cx + k,cy - k,px, py);
    noofsquares += countSquares(half,cx - k,cy + k,px, py);
    noofsquares += countSquares(half,cx + k,cy + k,px, py);

    return noofsquares;
}

int main(){
    int k, x, y;
    cin >> k >> x >> y;
    cout << countSquares(k, 1024, 1024, x, y) << endl;
    return 0;
}