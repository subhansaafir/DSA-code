#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Postfix: " << infix_to_postfix("(A+B)*(C-D)") << endl;
    cout << "Prefix: "  << infix_to_prefix("(A+B)*(C-D)") << endl;
    return 0;
}
