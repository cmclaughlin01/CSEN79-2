#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include "ratnum.h"
#include "ratNumIntakeOp.h"

using namespace std;
using namespace csen79;

int main(int argc, char* argv[]) {
    istream* input = &cin;
    ifstream inputFile;
    ofstream outputFile("output.txt");

    if (argc == 2) {
        inputFile.open(argv[1]);
        if (!inputFile.is_open()) {
            cerr << "Error: Could not open '" << argv[1] << "'." << endl;
            return 1;
        }
        input = &inputFile;
    }

    if (!outputFile.is_open()) {
        cerr << "Error: Could not create 'output.txt'." << endl;
        return 1;
    }

    // Map operation names to their functions instead of having many if else
    map<string, Operation> operations = {
        {"Sum", add},
        {"Sub", subtract},
        {"Multi", multiply},
        {"Div", divide},
        {"LessThan", lessThan},
        {"Equal", equalTo}
    };

    string line;

    // Read each line from the input file
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string op;
        int n1, d1, n2, d2;

        if (!(iss >> op >> n1 >> d1 >> n2 >> d2)) {
            cerr << "Error: Malformed input line: " << line << endl;
            continue;
        }
		
		//creates two ratnum objects to be compared with called operation from 
		//test file
        RatNum r1(n1, d1);
        RatNum r2(n2, d2);

        string result;
		//searches map for operation then calls that function with the ratnums
        if (operations.find(op) != operations.end()) {
            result = operations[op](r1, r2);
        } else {
            result = "Error: Unknown operation";
        }

        // Write the result to the output file
        outputFile << op << " " << n1 << " " << d1 << " "
                   << n2 << " " << d2 << " " << result << endl;
    }

    inputFile.close();
    outputFile.close();

    return EXIT_SUCCESS;
}
