#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Function to parse a comma-separated string into a vector of integers
vector<int> parsedata(string input) {
    string temp; // Temporary string to hold each number as it's parsed
    vector<int> result; // Vector to store the parsed integers
    stringstream streamin(input); // Create a stringstream from the input string
    // Read each line separated by commas
    while(getline(streamin, temp, ',')) {
        result.push_back(stoi(temp)); // Convert the string to an integer and add to the result vector
    }
    return result; // Return the vector of integers
}

// Function to find the intersection of two integer vectors
vector<int> intersection(vector<int> list1, vector<int> list2) {
    int i = 0; // Index for the first list
    int j = 0; // Index for the second list
    vector<int> result; // Vector to store the intersection results
    // Loop until we reach the end of either list
    while(i < list1.size() && j < list2.size()) {
        if (list1[i] == list2[j]) { // If elements are equal, it's part of the intersection
            result.push_back(list1[i]); // Add to the result
            i++; // Move to the next element in both lists
            j++;
        }
        else if (list1[i] < list2[j]) { // If the element in list1 is smaller, move to the next element in list1
            i++;
        }
        else { // If the element in list2 is smaller, move to the next element in list2
            j++;
        }
    }
    return result; // Return the vector containing the intersection
}

// Function to format the output as a comma-separated string
string output(vector<int> result) {
    string outputt; // String to hold the final output
    // Loop through the result vector
    for (int i = 0; i < result.size(); i++) {
        outputt = outputt + to_string(result[i]); // Convert each integer to string and append to outputt
        if ( i != result.size() - 1) { // If not the last element, add a comma
            outputt.push_back(',');
        }
    }
    return outputt; // Return the formatted output string
}

int main() {
    string input1, input2; // Strings to hold user input
    cout << "input angka dengan format: angka1, angka2, angka3, ... = "; // Prompt for first input
    getline(cin, input1); // Read the first line of input
    cout << "input angka dengan format: angka1, angka2, angka3, ... = "; // Prompt for second input
    getline(cin, input2); // Read the second line of input
    cout << " " << endl; // Print a blank line for better readability
    // Output the intersection of the two parsed inputs
    cout << output(intersection(parsedata(input1), parsedata(input2))) << endl;
    return 0; // Return 0 to indicate successful execution
}
