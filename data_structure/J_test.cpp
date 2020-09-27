#include <iostream>
#include <cctype>
#include <sstream>
#include <typeinfo>

using namespace std;

int main()
{
    string a;
    cout << typeid(a).name;
    return 0;
}