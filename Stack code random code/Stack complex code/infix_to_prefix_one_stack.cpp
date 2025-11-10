
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
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

// Function to reverse string and swap brackets
string reverseAndSwapBrackets(string infix)
{
    string reversed = "";

    // Reverse the string and swap brackets
    for (int i = infix.length() - 1; i >= 0; i--)
    {
        char c = infix[i];
        if (c == '(')
        {
            reversed += ')'; // Replace ( with )
        }
        else if (c == ')')
        {
            reversed += '('; // Replace ) with (
        }
        else
        {
            reversed += c;
        }
    }

    return reversed;
}

// Part (b) using one stack
// Input = Infix string
// Output = Prefix string
string infixToPrefixOneStack(string infix_string)
{

    // Create a stack that can store operators in it
    Stack<char> stack(100);

    string prefix_string = "";

    // Reverse the infix string, While reversing, replace ( with ) and ) with (
    string reversed_infix = reverseAndSwapBrackets(infix_string);

    // While (Scan reversed infix string from left to right till the end)
    for (int i = 0; i < reversed_infix.length(); i++)
    {

        // get next_character from infix_string
        char next_character = reversed_infix[i];

        // if (next_character is operand)
        if (isOperand(next_character))
        {
            // Append next_character to prefix_string
            prefix_string += next_character;
        }
        // else if (next_character is operator)
        else if (isOperator(next_character) || next_character == '(' || next_character == ')')
        {

            // while (stack is not empty AND precedence(stacktop) > precedence(next_character))
            while (!stack.isEmpty() && precedence(stack.stackTop()) > precedence(next_character))
            {
                // pop the operator from stack and append it to prefix_string
                prefix_string += stack.pop();
            }

            // if ( next_character is not ')' )
            if (next_character != ')')
            {
                // push next_character to stack
                stack.push(next_character);
            }
            // else if ( next_character is ')' )
            else if (next_character == ')')
            {
                // while (stack is not empty AND stacktop != '(' )
                while (!stack.isEmpty() && stack.stackTop() != '(')
                {
                    // pop from stack and append it to prefix_string
                    prefix_string += stack.pop();
                }
                // pop from stack //it will pop '(' bracket
                if (!stack.isEmpty())
                {
                    stack.pop();
                }
            }
        }
    }

    // while(stack is not empty)
    while (!stack.isEmpty())
    {
        // pop the operator from stack and append it to prefix_string
        prefix_string += stack.pop();
    }

    // Reverse prefix_string → Final Answer
    reverse(prefix_string.begin(), prefix_string.end());

    return prefix_string;
}

int main()
{
    cout << "=== Infix To Prefix Conversion Using One Stack (Following Teacher's Pseudocode) ===\n";

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

        // Show the reversed string for demonstration
        string reversed = reverseAndSwapBrackets(testExpressions[i]);
        cout << "Reversed: " << reversed << endl;

        string result = infixToPrefixOneStack(testExpressions[i]);

        cout << "Prefix: " << result << endl;

        cout << "CONVERSION COMPLETED" << endl;
    }

    return 0;
}
