/*
 * CSEN 79 Lab Sample Code
 */
#include <cstddef>
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "roster.h"

using namespace std;
using namespace csen79;

// Test code for class roster
// Input file: <CMD> [ID] [FIRST LAST]
// CMD : A | X | L
// ID: 7-digit unsigned integer
// FIRST, LAST: string 
int main() {
	Roster r;
	Student::ID_t id;
	string cmd, first, last;

	// Read cmd first, then branch accordingly
	while (cin >> cmd) {
		if (cmd == "A") {
			cin >> id >> first >> last;
			Student t(id, first, last);
			if(!r.insert(t)){
				cerr << t << "not inserted" << endl;
			}
		} else if (cmd == "X") {
			// your code to erase
			cin >> id;
			r.erase(id);
			cout << "Erase " << id << endl;
		} else if (cmd == "L") {
			// this should just work, if you did your begin/end/next correctly
			int i = 1;
			for (auto st = r.begin(); st != nullptr && r.end(); st = r.next(), i++)
				if(st != nullptr){
					cout << i << ": " << *st << endl;
				}
		} 
	}

	// cout << "Testing next" << endl;
	// try {
	// 	while (auto i = r.next());
	// } catch (out_of_range &e) {
	// 	string reason = e.what();
	// 	cerr << reason << endl;
	// }
	return EXIT_SUCCESS;
}

