//
// Created by wpy on 18-6-25.
//

#include <cstdio>
#include <sstream>
#include "C.h"

C::C(int x) {
    this->x = x;
}

const char *C::toString() const {
    std::stringstream ss;
    ss << "create class C(b: " << this->x << ").";
    ss.flush();
    const std::string str = ss.str();
    const char *c = str.c_str();
    return c;
}


