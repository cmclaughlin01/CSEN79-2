#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
   if (argc != 3) {
        cerr << "Examine expected both the output.txt and the expected values" << endl;
        return 1;
    }

    ifstream outputFile(argv[1]);
    ifstream expectedFile(argv[2]);

    if (!outputFile.is_open() || !expectedFile.is_open()) {
        cerr << "Error: Could not open one of the input files." << endl;
        return 1;
    }

    string outputLine, expectedLine;
    int testCounter = 0;
    int passedTests = 0;

    //map used to indentify which operation is being used and increment the 
    //counter
    map<string, int> operationCount = {
        {"Sum", 0}, {"Sub", 0}, {"Multi", 0},
        {"Div", 0}, {"LessThan", 0}, {"Equal", 0}
    };

    // Process both files line by line
    while (getline(outputFile, outputLine) && getline(expectedFile, expectedLine)) {
        testCounter++;

        istringstream outputStream(outputLine);
        string op, outputResult;
        int n1, d1, n2, d2;

        outputStream >> op >> n1 >> d1 >> n2 >> d2;

        getline(outputStream >> ws, outputResult);

        // Count the operation
        if (operationCount.find(op) != operationCount.end()) {
            operationCount[op]++;
        }

        // Compare the actual output with the expected outcome
        bool isCorrect = (outputResult == expectedLine);

        // Print the result of the test
        cout << "Test #" << testCounter << " (" << n1 << "/" << d1 << ", " 
             << n2 << "/" << d2 << ") " << op << ":" << endl;
        cout << "output: " << outputResult << " expected: " << expectedLine << endl;
        if (isCorrect) {
            cout << "Test passed" << endl;
            passedTests++;
        } else {
            cout << "Test failed" << endl;
        }
        cout << endl;
    }

    outputFile.close();
    expectedFile.close();

    cout << passedTests << "/" << testCounter << " tests passed" << endl;
    for (const auto& entry : operationCount) {
        cout << "Amount of " << entry.first << " operations run: " << entry.second << endl;
    }

    return EXIT_SUCCESS;
}
