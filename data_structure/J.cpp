#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

int order(char op);
string infixToPostfix(string infix);
int Compute(string postfix);

int main()
{
    string arithmetic;
    while(getline(cin, arithmetic)) {
        string postfix = infixToPostfix(arithmetic);
        // cout << postfix << endl;
        cout << Compute(postfix) << endl;
    }
    return 0;
}

int order(char op) {
    switch (op) {
        case '+': case '-':
            return 0;
            break;
        default:
            return 1;
            break;
    }
}

string infixToPostfix(string infix) {
    stringstream input, result;
    string item;
    // operator stack
    char op[100];
    int top = -1;

    input.clear();
    input.str(infix);
    result.clear();
    
    while(input >> item) {
        if(isdigit(item[0])) {
            result << item << " ";
        }
        else {
            switch (item[0]) {
                case '+': case '-': case '*': case '/': case '%':
                    if(top >= 0) {
                        // pop out from stack & store into result 
                        while(order(op[top]) >= order(item[0]) && top >= 0) {
                            result << op[top--] << " ";
                        }
                    }
                    // push
                    op[++top] = item[0];
                    break;

                default:
                    break;
            }
        }
    }
    while(top >= 0) {
        result << op[top--] << " ";
    }

    return result.str(); 
}

int Compute(string postfix) {
    int stack[100];
    int top = -1;

    string item;
    stringstream input;
    input.clear();
    input.str(postfix);

    while(input >> item) {
        if(isdigit(item[0])) {
            stack[++top] = atoi(item.c_str());
        }
        else {
            int first, second;
            second = stack[top--];
            first = stack[top--];
            switch (item[0]) {
                case '+': 
                    stack[++top] = first + second;
                    break;
                case '-':
                    stack[++top] = first - second;
                    break;
                case '*':
                    stack[++top] = first * second;
                    break;
                case '/':
                    stack[++top] = first / second;
                    break;
                case '%':
                    stack[++top] = first % second;
                    break;
            }
        }
    }
    return stack[0];
}