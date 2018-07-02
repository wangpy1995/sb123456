#include <cstdio>
#include <cstdlib>
#include "initialization/B.h"
#include "fsm/TestFSM.h"

#include <gtest/gtest.h>

const void testFunc(const int *(*func)(const int *)) {
    int a = 123;
    printf("%d\n", *(func(&a)));
}

void doSomething(B bObject) {
    auto c = bObject.toString();
    printf("%s\n", c);
    free((void *) c);
}

TEST(test, fsm) {
    int i;
    for (i = 0; i < 8; ++i) {
        TestFSM(&i);
    }
}

int main() {
//    std::cout << "Hello, World!" << std::endl;
//    testFunc([](const int *a) -> const int * { return a; });
//    auto p = A<char>::npos;
//    printf("%x\n", p);
//    B bObj1;
//    doSomething(bObj1);
//    B bObj2(28);
//    doSomething(bObj2);

    SM_VAR var;
    int i;
    for (i = 0; i < 8; ++i) {
        TestFSM(&var);
    }
    return 0;
}