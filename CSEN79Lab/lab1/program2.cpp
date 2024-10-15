/*
Name: Curran McLaughlin & Julian Jackson
    Program Description: The Program takes in a user input and reverses the input 
    given then prints both values with each new print adding spaces to offset the
    line
*/
#include <iostream>

using namespace std;

void reverseString(string userString){
    string userReverse = "";
    int spaceAmount = 3;
    for(int i = userString.length(); i >= 0; i--){
        userReverse = userReverse + userString[i];
    }
    for(int i = 0; i <=5; i++){
        string spaces(spaceAmount,' ');
        cout << spaces << userString << "       " << userReverse << endl;
        spaceAmount = spaceAmount + 3;
    }
}

bool isValidInput(string userString){
    bool valid = true; 
    for(int i = 0; i < userString.length(); i++){
        if(isspace(userString[i])){
            cout << "has a space";
            return false;
            break;
        }
        else if(userString.length() != 10){
            cout << "is not 10";
            return false;
            break;
        }
    }
    return true;
}

int main(){
    string userNum = "";

    cout << "Enter 10 digits (no whitespaces):" << endl;
    getline(cin, userNum);

    if (isValidInput(userNum)){
        reverseString(userNum);
    }
    else{
        cout << "The inputted digits do not follow the format" << endl;
        exit;
    }
}