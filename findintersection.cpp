#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> parsedata(string input) {
    string temp;
    vector<int> result;
    stringstream streamin(input);
    while(getline(streamin, temp, ',')) {
        result.push_back(stoi(temp));
    }
    return result;
}

vector<int> intersection(vector<int> list1, vector<int> list2) {
    int i = 0;
    int j = 0;
    vector<int> result;
    while(i < list1.size() && j < list2.size()) {
        if (list1[i] == list2[j]) {
            result.push_back(list1[i]);
            i++;
            j++;
        }
        else if (list1[i] < list2[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    return result;
}

string output(vector<int> result) {
    string outputt;
    for (int i = 0; i < result.size(); i++) {
        outputt = outputt + to_string(result[i]);
        if ( i != result.size() - 1) {
            outputt.push_back(',');
        }
    }
    return outputt;
}

int main() {
    string input1, input2;
    cout << "input angka dengan format: angka1, angka2, angka3, ... = ";
    getline(cin, input1);
    cout << "input angka dengan format: angka1, angka2, angka3, ... = ";
    getline(cin, input2);
    cout << " " << endl;
    cout << output(intersection(parsedata(input1), parsedata(input2))) << endl;
    return 0;
}

