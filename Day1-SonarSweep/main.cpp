/* LINK TO WEBPAGE
 * Problem statement: https://adventofcode.com/2021/day/1
 * Problem 2 statement: https://adventofcode.com/2021/day/1#part2
 * Input data: https://adventofcode.com/2021/day/1/input
 * Input data from the webpage has been copied to file InputData.
 */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int countIncreases(const vector<int>& vData){
    int counter = 0;
    // because the first case cannot be compared with any previous one, for loop starts at element 1.
    for (int i = 1; i < vData.size(); ++i) {
        if (vData[i] - vData[i-1] > 0) {
            counter += 1;
        }
    }
    return counter;
}

int countIncreasesWindow(const vector<int>& vData){
    int counter = 0;
    int previous;
    int current;
    for (int i = 3; i <= vData.size(); ++i) {
        if (vData[i]-vData[i-3] > 0){
            counter += 1;
        }
    }
    return counter;
}


int main() {
    vector<int> vectorData;
    // READ FILE
    ifstream myDataFile ("InputData.txt", ios::in);
    if (myDataFile.is_open()){
        cout << "File opened." << endl;
        int number;
        while (myDataFile >> number){
            vectorData.push_back(number);
        }
        myDataFile.close();
        cout << "File closed." << endl;
    }else{
        cout << "Unable to open file" << endl;
    }
    cout << "Input data size = " << vectorData.size() << endl;

    cout << "PROBLEM 1: Number of increases." << endl;
    int nIncreases = countIncreases(vectorData);
    cout << "SOLUTION 1: Number of increases = " << nIncreases << endl;
    cout << "PROBLEM 2: Number of increases with a 3 measurement window sliding." << endl;
    int nIncreases2 = countIncreasesWindow(vectorData);
    cout << "SOLUTION 1: Number of increases = " << nIncreases2 << endl;
    cout << "END" << endl;
    return 0;
}
