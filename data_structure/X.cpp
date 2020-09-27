#include <iostream>

using namespace std;

int main()
{
    int num;
    int ch;
    cin >> num;
    while(num--) {
        cin >> ch;
        cout << char(ch);
    }

    return 0;
}
