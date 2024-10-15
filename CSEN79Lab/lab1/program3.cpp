/*
Name: Curran McLaughlin & Julian Jackson
Program Description: The Program takes in a user file, then adds all words in
    a vector to be parsed. Once parsed all non-alphabetical characters are
    removed along with words longer then 10 char. The words left are then 
    uppercased.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]){
    vector<string> words;
    string inFile = "", stringFile = "", str = "";
    inFile = argv[1];
    //cout << inFile;

    ifstream userFile;
    userFile.open(inFile);
    if (!userFile.is_open()){
         cerr << "Error opening file: " << inFile << endl;
        return 1;
    }

    while(userFile >> str){
        words.push_back(str);
    }

    userFile.close();

    auto predicate = [](const string& word){
        return any_of(word.begin(), word.end(), [](char c){ return !isalpha(c); }) || word.size() != 10;
    };

    words.erase(remove_if(words.begin(), words.end(), predicate), words.end());

    for(string& word : words){
        transform(word.begin(), word.end(), word.begin(), [](unsigned char c){ return toupper(c); });
    }
    
    for(const string& word : words){
        cout << word << " ";
    }
    cout << endl;
    return 0;
}