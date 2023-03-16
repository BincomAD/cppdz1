#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

vector<string> parse(string str, char delim)
{
    vector<string> out;
    string word;

    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] != delim) {
            word += str[i];
        }
        else {
            out.push_back(word);
            word.clear();
        }
    }

    out.push_back(word);
    return out;
};

int main(int argc, char* argv[])
{
    if (argc == 4) {
        string str;
        ifstream file(argv[1]);

        if (file) {
            vector<string> strok;
            while (getline(file, str)) {
                strok = parse(str, '\t');
                if ((strok[4] != "\\N") && (stoi(strok[4]) >= stoi(argv[2])) && (stoi(strok[4]) <= stoi(argv[3]))) {
                    cout << strok[2] << endl;
                }
            }
        }
        else {
            cout << "No file:(" << endl;
        }
    }
    else {
        cout << "Input file path." << endl;
    }
};