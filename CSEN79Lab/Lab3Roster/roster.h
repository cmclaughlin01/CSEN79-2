/*
 * CSEN 79 Lab Sample Code
 */
#ifndef ROSTER_H
#define ROSTER_H


#include <vector>

// Class declaration for roster
namespace csen79 {
	// base data for the roster
	class Student {
	public:
		using ID_t = unsigned int;	// really should be a 7-digit unsigned int
		Student(): Student(0, "", "") {};
		Student(ID_t n, std::string fn, std::string ln){
			id = n; first = fn; last = ln;
		};
		const ID_t getID(void) const {return id;};
	friend std::ostream& operator<<(std::ostream& os, const Student &);
	private:
		ID_t id;
		std::string first;
		std::string last;
	}; 

	class Roster {
	public:
		using T = Student;
		static const int CAPACITY=30;

		Roster(): idx(0), last(0) {}
		bool insert(T &);
		void erase(Student::ID_t);

		T* begin(void);
		T* end(void);
		T* next(void);
	private:
		std::vector<T> roster;
		int idx;
		int last;
	};
}
#endif // ROSTER_H
