/*
 * Curran McLaughlin <cmclaughlin2@scu.edu>, 
 *
 * Assignment: Midterm 1
 * header file to initialize the helper functions
 * when an opation is chosen the map points to these functions that then run
 * the correct overloaded operation from RatNum
 */
#ifndef RATNUM_READ_OPERATIONS_H
#define RATNUM_READ_OPERATIONS_H

#include <string>
#include <functional>
#include "ratnum.h"

namespace csen79{
    using Operation = std::function<std::string(RatNum&, RatNum&)>;

    std::string add(RatNum& r1, RatNum& r2);
    std::string subtract(RatNum& r1, RatNum& r2);
    std::string multiply(RatNum& r1, RatNum& r2);
    std::string divide(RatNum& r1, RatNum& r2);
    std::string lessThan(RatNum& r1, RatNum& r2);
    std::string equalTo(RatNum& r1, RatNum& r2);
}

#endif