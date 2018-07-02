//
// Created by wpy on 18-6-25.
//

#include <cstdio>
#include <cstdlib>
#include <iosfwd>
#include <sstream>
#include <memory>
#include <cstring>
#include "B.h"

B::B(int x, bool b) {
    this->x = x;
    this->b = b;
}

const char *B::toString() const {
    std::stringstream ss;
    printf("class B: %x \n",this);
    ss << "create class B(x: " << this->x << ", b: " << (this->b == 0 ? "false" : "true") << ").";
    const std::string str = ss.str();
    auto c = (char *) malloc(str.length() + 1);

//    memset(c,0,str.length()+1);
//    memcpy(c, str.c_str(), str.length());
//    std::allocator<char> a;
//    auto c = a.allocate(str.length()+1);
    memset(c, 0, str.length() + 1);
    memcpy(c, str.c_str(), str.length());
//    a.deallocate(c,str.length()+1);
    return c;
}

void B::test() {
    printf("test class B.\n");
}
