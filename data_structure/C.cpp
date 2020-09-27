#include <iostream>
#include <string>
using namespace std;

struct Person {
    string ID;
    string name;
    string gender;
    int age;
};

int main()
{
    int people_num, search_num;
    while(cin >> people_num) {
        Person students[1000];
        for(int i = 0; i < people_num; i++) {
            cin >> students[i].ID >> students[i].name >> students[i].gender >> students[i].age;
        }
        cin >> search_num;
        for(int i = 0; i < search_num; i++) {
            string ID;
            cin >> ID;
            bool find = false;
            for(int j = 0; j < people_num; j++) {
                if(ID == students[j].ID) {
                    cout << students[j].ID << " " << students[j].name << " " << students[j].gender << " " << students[j].age << endl;
                    find = true;
                    break;
                }
            }
            if(find != true) {
                cout << "No Answer!" << endl;
            }
        }
    }

    return 0;
}
