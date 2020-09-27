#include <iostream>
#include <cstdlib>
using namespace std;
template <typename ty>
class Stack
{
  public:
    Stack() {}
    ty value;
    Stack *prev = 0;
    Stack *top = NULL;
    Stack *vptr = 0;
    Stack *temp = 0;

    void push(ty num)
    {
        vptr = new Stack;
        vptr->value = num;
        vptr->prev = top;
        top = vptr;
    }
    void pop()
    {
        if (top == 0)
        {
            cout << "stack is empty\n";
        }
        temp = top;
        top = top->prev;
        delete temp;
    }
    void output()
    {
        temp = top;
        while (temp)
        {
            cout << temp->value << " ";
            temp = temp->prev;
        }
    }
};

class Arithmetic
{
  public:
    Arithmetic() {}
    /*void push_op(char op)
{
Op_stack.push(op);
if(op == '*') {
float num = Num_stack.top->value * Num_stack.top->prev->value;
Num_stack.pop();
Num_stack.pop();
Num_stack.push(num);
Op_stack.pop();
}
if(op == '/') {
float num = Num_stack.top->value / Num_stack.top->prev->value;
Num_stack.pop();
Num_stack.pop();
Num_stack.push(num);
Op_stack.pop();
}
}*/
    /*void pop_op()
{
Op_stack.pop(op);
}*/
    void push_num(float num)
    {
        Num_stack.push(num);
    }
    /*void pop_num(float num)
{
Num_stack.pop(num);
}*/
    float cal()
    {

        while ((Num_stack.top->prev) != NULL)
        {
            if (Op_stack.top->value == '+')
            {
                float num = Num_stack.top->value + Num_stack.top->prev->value;
                Num_stack.pop();
                Num_stack.pop();
                Num_stack.push(num);
                Op_stack.pop();
            }
            else if (Op_stack.top->value == '-')
            {
                //float num = Num_stack.top->prev->value - Num_stack.top->value;
                float num = Num_stack.top->prev->value - Num_stack.top->value;
                Num_stack.pop();
                Num_stack.pop();
                Num_stack.push(num);
                Op_stack.pop();
            }
        }
        return Num_stack.top->value;

        /*if(Op_stack.top->value == '*' || Op_stack.top->value == '/') {
Num_stack.top->value
}
else if(Op_stack.top->value == '+' || Op_stack.top->value == '-') {

}*/
    }

  public:
    Stack<float> Num_stack;
    Stack<char> Op_stack;
};

int main()
{

    Arithmetic calculator;
    float num;
    char op;
    cin >> num;
    calculator.push_num(num);
    while (cin >> op)
    {
        //calculator.cal();
        cin >> num;
        calculator.push_num(num);

        calculator.Op_stack.push(op);
        if (op == '*')
        {
            float num = calculator.Num_stack.top->value * calculator.Num_stack.top->prev->value;
            calculator.Num_stack.pop();
            calculator.Num_stack.pop();
            calculator.Num_stack.push(num);
            calculator.Op_stack.pop();
        }
        if (op == '/')
        {
            float num = calculator.Num_stack.top->value / calculator.Num_stack.top->prev->value;
            calculator.Num_stack.pop();
            calculator.Num_stack.pop();
            calculator.Num_stack.push(num);
            calculator.Op_stack.pop();
        }
    }
    cout << calculator.cal();
    /*Stack <int >s;
s.push(1);
s.push(2);
s.output();*/

    return 0;
}