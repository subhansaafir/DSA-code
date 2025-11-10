
#include <iostream>
#include <string>
#include <cctype>
#include "stack.h"
using namespace std;

// Function to get precedence of operators
int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
    case '$':
        return 3;
    default:
        return 0; // For '(' and other characters
    }
}

// Function to check if character is an operand
bool isOperand(char c)
{
    return isalnum(c); // alphanumeric characters (a-z, A-Z, 0-9)
}
// Function to check if character is an operator
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^' || c == '$';
}

// Part (a) using two stack
// Input = infix string
// Output = prefix string
string infixToPrefixTwoStack(string infix_string)
{

    // Create a stack that can store operators in it called it as operatorstack
    Stack<char> operatorstack(100);

    // Create a stack that can store operands in it called it as operandstack
    Stack<string> operandstack(100);

    // While (Scan the infix_string from left to right till the end)
    for (int i = 0; i < infix_string.length(); i++)
    {

        // get next_character from infix_string
        char next_character = infix_string[i];

        // if (next_character is operand)
        if (isOperand(next_character))
        {
            // push next_character into operandstack
            string operand_str(1, next_character); // Convert char to string
            operandstack.push(operand_str);
        }
        // else if (next_character is operator)
        else if (isOperator(next_character) || next_character == '(' || next_character == ')')
        {

            // while (operatorstack is not empty AND precedence(stacktop) > precedence(next_character) )
            while (!operatorstack.isEmpty() && precedence(operatorstack.stackTop()) > precedence(next_character))
            {

                // operand2 = pop the operand from operandstack
                string operand2 = operandstack.pop();

                // operand1 = pop the operand from operandstack
                string operand1 = operandstack.pop();

                // operator = pop the operator from operatorstack
                char operator_char = operatorstack.pop();

                // concatenate operator+operand1+operand2
                string concatenated = operator_char + operand1 + operand2;

                // push the concatenated result into operandstack
                operandstack.push(concatenated);
            }

            // if ( next_character is not ')' )
            if (next_character != ')')
            {
                // push next_character to operatorstack
                operatorstack.push(next_character);
            }
            // else if ( next_character is ')' )
            else if (next_character == ')')
            {
                // while (stack is not empty AND stacktop != '(' )
                while (!operatorstack.isEmpty() && operatorstack.stackTop() != '(')
                {

                    // operand2 = pop the operand from operandstack
                    string operand2 = operandstack.pop();

                    // operand1 = pop the operand from operandstack
                    string operand1 = operandstack.pop();

                    // operator = pop the operator from operatorstack
                    char operator_char = operatorstack.pop();

                    // concatenate operator+operand1+operand2
                    string concatenated = operator_char + operand1 + operand2;

                    // push the concatenated result into operandstack
                    operandstack.push(concatenated);
                }
                // pop from stack //it will pop '(' bracket
                if (!operatorstack.isEmpty())
                {
                    operatorstack.pop();
                }
            }
        }
    }

    // while(operatorstack is not empty)
    while (!operatorstack.isEmpty())
    {

        // operand2 = pop the operand from operandstack
        string operand2 = operandstack.pop();

        // operand1 = pop the operand from operandstack
        string operand1 = operandstack.pop();

        // operator = pop the operator from operatorstack
        char operator_char = operatorstack.pop();

        // concatenate operator+operand1+operand2
        string concatenated = operator_char + operand1 + operand2;

        // push the concatenated result into operandstack
        operandstack.push(concatenated);
    }

    // Pop the operandstack and store it in prefix string
    string prefix_string = operandstack.pop();

    return prefix_string;
}

int main()
{
    cout << "=== Infix To Prefix Conversion Using Two Stack (Following Teacher's Pseudocode) ===\n";

    string testExpressions[] = {
        "a+b",              // Simple addition
        "a+b*c",            // Precedence test
        "(a+b)*c",          // Brackets change precedence
        "a+b*c+d",          // Multiple operators
        "(a+b)*(c+d)",      // Multiple brackets
        "a+b*c/d-e",        // Mixed operators
        "((a+b)*c)-d",      // Nested brackets
        "a^b^c",            // Right associative
        "a+b*c^d",          // Mixed precedence
        "(a+b)*(c-d)/(e+f)" // Complex expression
    };

    for (int i = 0; i < 10; i++)
    {
        cout << "\n"
             << string(50, '=') << endl;
        cout << "Test " << (i + 1) << ": ";

        cout << "Infix:  " << testExpressions[i] << endl;

        string result = infixToPrefixTwoStack(testExpressions[i]);

        cout << "Prefix: " << result << endl;

        cout << "CONVERSION COMPLETED" << endl;
    }

    return 0;
}
