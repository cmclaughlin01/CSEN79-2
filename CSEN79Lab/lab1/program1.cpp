/*
Name: Curran McLaughlin & Julian Jackson
Program Description: The Program takes in a user input and counts the amount of
    alphanumeric characters and non-alphanumeric charaters. Skips over whitespaces
*/
#include <iostream>

using namespace std;


int main(){
    string stringOne;
    int stringLen, alphaNumCount = 0, nonAlphaCount = 0;

    cout << "please type in a string" << endl;
    getline (cin, stringOne);

    stringLen = stringOne.length();
    for(int i = 0; i < stringLen; i++){
        if (isalnum(stringOne[i])){
            alphaNumCount++;
        }
        else{
            if(!isspace(stringOne[i])){
                nonAlphaCount++;
            }
        }
    }

    cout << "\"" << stringOne << "\"" << " has " << alphaNumCount 
        << " alphanumberic characters and " << nonAlphaCount 
        << " non-alphanumberic characters." << endl;
    
}
