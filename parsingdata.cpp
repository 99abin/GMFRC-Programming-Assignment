#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

string substring(string input) {
    return input.substr(input.find('%') + 1, input.find('&') - input.find('%') - 1);
}

vector<int> parsing(string input) {
    stringstream ssinput(input);
    string temp;
    vector<int> result;
    while(getline(ssinput, temp, '^')) {
        result.push_back(stoi(temp));
    }
    return result;
}

int main() {
    string input;
    cout << "masukkan input: ";
    getline(cin, input);
    for (int i = 0; i < parsing(substring(input)).size(); i++) {
        cout << "data[" << i << "] : " << parsing(substring(input))[i] << endl;    }
}