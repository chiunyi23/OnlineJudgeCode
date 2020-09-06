#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{

    int N;
    int longest_filename;
    string name;
    
    while(cin >> N) {
        // read filenames and sort using ASCII
        vector<string> filenames;
        longest_filename = 0;
        for(int i = 0; i < N; i++) {
            cin >> name;
            filenames.push_back(name);
            if(name.length() > longest_filename)
                longest_filename = name.length();
        }

        sort(filenames.begin(), filenames.end());

        // format
        int row, column;
        int maxcol = 60;
        column = floor((maxcol + 2) / (longest_filename + 2));
        row = ceil(float(N) / column);
        // column = (maxcol - longest_filename) / (longest_filename + 2) + 1;
        // row = (N - 1) / column + 1;

        // output
        cout << "------------------------------------------------------------\n";
        for(int r = 0; r < row; r++) {
            for(int c = 0; c < column; c++) {
                int index = r + c * row;
                if(index < N) {
                    cout.width(longest_filename + 2);
                    cout << left << filenames[index];
                }
            }
            cout << endl;
        }
    }

    return 0;
}