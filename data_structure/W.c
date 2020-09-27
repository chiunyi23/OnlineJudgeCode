#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    string name;
    string cas;
    while(getline(cin, name)) {
        if(name == "  ") {
            cout << "over";
            break;
        }
        name[0] = toupper(name[0]);
        cout << name[0];
        for(int i = 1; i < name.length(); i++) {
            if(name[i] != ' ') {
                if(name[i-1] == ' ') {
                    name[i] = toupper(name[i]);
                    cout << name[i];
                }
                else {
                    name[i] = tolower(name[i]);
                    cout << name[i];
                }

            }

        }
        cout << endl;
    }
    return 0;
}
