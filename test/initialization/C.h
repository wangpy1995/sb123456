//
// Created by wpy on 18-6-25.
//

#ifndef SB123456_C_H
#define SB123456_C_H


#include "B.h"

class C : public B {
public:
    explicit C(int x);

    const char *toString() const;

//    void test() override = delete;

private:
    int x;
};

#endif //SB123456_C_H
