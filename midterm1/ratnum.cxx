/*
 * Curran McLaughlin <cmclaughlin2@scu.edu>
 *
 * Assignment: Midterm 1
 */
#include <cstdio>
#include <numeric> 
#include <algorithm>
#include <iomanip>
#include <iostream>
#include "ratnum.h"

using namespace std;	// for ostream

namespace csen79 {
	/*
	 * Construct a rational number.  Accept one or two integers.
	 * If only one, assume the denominator is 1.
	 * Otherwise, simplify the rational number by dividing both with GCD.
	 */
	RatNum::RatNum(rat_t n, rat_t d) : num(n), den(d) {
		if (d == 0)
			num = 0;
		else {
			int todivide = gcd(abs(n), d);
			num = n/todivide;
			den = d/todivide;
		}
	}

	// trivial implementaion of GCD
	unsigned int RatNum::gcd(unsigned int a, unsigned int b) {
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}

	ostream& operator<<(ostream& os, const RatNum& n) {
		if (n.den == 1 || n.num == 0)	
			os << n.num;
		else
			os << n.num << '/' << n.den;
		return os;
	}

	RatNum RatNum::operator+(RatNum const &n1) { 
		long long finalNum = num * n1.den + n1.num * den;
		long long finalDen = den * n1.den;
		return RatNum(finalNum, finalDen);
	}

	RatNum RatNum::operator-(RatNum const &n1) { 
		long long finalNum = num * n1.den - n1.num * den;
		long long finalDen = den * n1.den;
		return RatNum(finalNum, finalDen);
	}

	RatNum RatNum::operator*(RatNum const &n1) {
		long long finalNum = num * n1.num;
		long long finalDen = den * n1.den;
		return RatNum(finalNum, finalDen);
	}

	RatNum RatNum::operator/(RatNum const &n1) {
		if (n1.num == 0){
			throw runtime_error("Division by Zero");
		}
		long long finalNum = num * n1.den;
		long long finalDen = den * n1.num; 
		return RatNum(finalNum, finalDen);
	}

	bool RatNum::operator<(RatNum const &n1) {
		int negFirst = ((long long)num * den > 0) ? 1 : -1;
		int negSecond = ((long long)n1.num * n1.den > 0) ? 1 : -1;

		return (long long)negFirst * abs(num) * abs(n1.den) < (long long)negSecond * abs(n1.num) * abs(den);
	}

	bool RatNum::operator==(RatNum const &n1) {
		return num * n1.den == n1.num * den;
	}

	long long RatNum::getNum() const {
		return num;
	}

	long long RatNum::getDen() const {
		return den;
	}
}

