#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int* followInstructions(vector<string>& vInst, string* keywords){
    int horizontal = 0, depth = 0;
    int instructionMagnitude;
    for (int i = 0; i < vInst.size(); ++i) {
        instructionMagnitude = vInst[i].back() - '0';  // to convert a char number to its integer equivalent
        if (vInst[i].find(keywords[0]) != std::string::npos){  //this means that function 'find' did find a match.
            horizontal += instructionMagnitude;
        } else if (vInst[i].find(keywords[1]) != std::string::npos){
            depth -= instructionMagnitude;
        } else if (vInst[i].find(keywords[2]) != std::string::npos){
            depth += instructionMagnitude;
        }else{
        }
    }
    static int arraySolution[2] = {horizontal, depth};
    return arraySolution;
}

int* followInstructions2(vector<string>& vInst, string* keywords){
    int horizontal = 0, depth = 0, aim = 0;
    int instructionMagnitude;
    for (int i = 0; i < vInst.size(); ++i) {
        instructionMagnitude = vInst[i].back() - '0';  // to convert a char number to its integer equivalent
        if (vInst[i].find(keywords[0]) != std::string::npos){  //this means that function 'find' did find a match.
            horizontal += instructionMagnitude;
            depth += aim * instructionMagnitude;
        } else if (vInst[i].find(keywords[1]) != std::string::npos){
            aim -= instructionMagnitude;
        } else if (vInst[i].find(keywords[2]) != std::string::npos){
            aim += instructionMagnitude;
        }else{
        }
    }
    static int arraySolution[2] = {horizontal, depth};
    return arraySolution;
}

int main() {
    string instructionKeywords[3] = {"forward", "up", "down"};
    vector<string> vectorInstructions;
    string line;
    ifstream instructions ("InputData.txt");
    if (instructions.is_open()){
        cout << "InputData opened." << endl;
        while (getline(instructions, line)){
            vectorInstructions.push_back(line);
        }
        instructions.close();
        cout << "InputData closed." << endl;
    } else{
        cout << "Unable to open file." << endl;
    }
    cout << "Number of instructions = " << vectorInstructions.size() << endl;
    int* pSolutionArray1 = followInstructions(vectorInstructions, instructionKeywords);
    int horizontal = *pSolutionArray1;
    int depth = *(pSolutionArray1+1);
    cout << "RESULT PROBLEM 1: " << endl;
    cout << "Horizontal: " << horizontal << endl;
    cout << "Depth: " << depth << endl;
    cout << "Horizontal * Depth: " << horizontal * depth << endl;
    cout << "RESULT PROBLEM 2: " << endl;
    int* pSolutionArray2 = followInstructions2(vectorInstructions, instructionKeywords);
    int horizontal2 = *pSolutionArray2;
    int depth2 = *(pSolutionArray2+1);
    cout << "Horizontal 2: " << horizontal2 << endl;
    cout << "Depth 2: " << depth2 << endl;
    cout << "Horizontal2 * Depth2: " << horizontal2 * depth2 << endl;
    std::cout << "END!" << std::endl;
    return 0;
}
