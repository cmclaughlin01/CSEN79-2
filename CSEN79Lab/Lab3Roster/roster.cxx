/*
 * CSEN 79 Lab Sample Code
 */
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "roster.h"

namespace csen79 {
	std::ostream& operator<<(std::ostream& os, const Student &t) {
		os << t.first << " " << t.last;
		os << " (" << t.id << ") ";
		return os;
	}

	// state your pre-/post-conditions
	bool Roster::insert(T &rec) {
		for(const auto &item : roster){
			if (item.getID() == rec.getID()){
				return false;
			}
		}
		if(roster.size() < CAPACITY){
			roster.push_back(rec);
			return true;
		}
		
		return true;
	} 

	// state your pre-/post-conditions
	void Roster::erase(Student::ID_t id) {
		for(auto i = roster.begin(); i != roster.end(); ++i){
			if(i->getID() == id){
				roster.erase(i);
				return;
			}
		}
	}

	// rudimentary iterator
	Roster::T* Roster::begin(void) {
		if(!roster.empty()){
			idx = 0;
			return &roster[0];
		}
		return nullptr;
	}

	Roster::T* Roster::end(void) {
		if(!roster.empty()){
			return &roster[roster.size()];
		}
		return nullptr;
	}

	// The next element for interation
	Roster::T* Roster::next(void) {
		// if(idx >= last || idx >= roster.size()){
		// 	throw std::out_of_range("Roster exceeded range: " 
		// 	+ std::to_string(idx));
		// }
		if(idx + 1 < roster.size()){
			++idx;
			return &roster[idx];
		}
		return nullptr;
	}
}
