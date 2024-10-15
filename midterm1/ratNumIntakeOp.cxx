#include <sstream>
#include <stdexcept>
#include "ratNumIntakeOp.h"

using namespace std;

//helper functions for the map; when an operation is picked its functions runs
//and uses the overloaded operators from RatNum
namespace csen79{
    string add(RatNum& r1, RatNum& r2) {
        RatNum res = r1 + r2;
        std::ostringstream oss;
        oss << res.getNum() << "/" << res.getDen();
        return oss.str();
    }

    string subtract(RatNum& r1, RatNum& r2) {
        RatNum res = r1 - r2;
        std::ostringstream oss;
        oss << res.getNum() << "/" << res.getDen();
        return oss.str();
    }

    string multiply(RatNum& r1, RatNum& r2) {
        RatNum res = r1 * r2;
        std::ostringstream oss;
        oss << res.getNum() << "/" << res.getDen();
        return oss.str();
    }

    string divide(RatNum& r1, RatNum& r2) {
        ostringstream oss;
        try {
            RatNum res = r1 / r2;
            oss << res.getNum() << "/" << res.getDen();
        } catch (const std::runtime_error& e) {
            oss << "Error: Division by zero";
        }
        return oss.str();
    }

    string lessThan(RatNum& r1, RatNum& r2) {
        return r1 < r2 ? "true" : "false";
    }

    string equalTo(RatNum& r1, RatNum& r2) {
        return r1 == r2 ? "true" : "false";
    }
}