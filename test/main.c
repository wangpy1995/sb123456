#include <stdio.h>
#include <stdlib.h>
#include "initialization/B.h"
#include "fsm/TestFSM.h"
#include "io/test_read.h"

#include <reader.h>

const void testFunc(const int *(*func)(const int *)) {
    int a = 123;
    printf("%d\n", *(func(&a)));
}

/*void doSomething(B bObject) {
    auto c = bObject.toString();
    printf("%s\n", c);
    free((void *) c);
}*/

/*TEST(test, fsm) {
    int i;
    for (i = 0; i < 8; ++i) {
        TestFSM(&i);
    }
}

TEST(test, bit_len) {
    int len = bitCount(3);
    printf("\n%d\n", len);
}*/

int main() {
    before();

    unsigned char r = 0, d = 0;
    unsigned char *r_level, *d_level;
    Bits *bits;
    r_level = &r;
    d_level = &d;
    unsigned char max_r_len, max_d_len;
    max_r_len = highestBitPos(n_l_country->max_repetition_level);
    max_d_len = highestBitPos(n_l_country->max_definition_level);
    int i;
    int64_t country_count = n_l_country->count;
    bits = n_l_country->bits;
    size_t country_offset = n_l_country->data_offset;
    size_t id_offset = docId.data_offset;

    if (n_l_country->max_repetition_level != 0 && country_count > 0) {
        --country_count;
        readBits(bits, max_r_len, max_d_len, r_level, d_level);
        bits += (max_r_len + max_d_len);
    }

    for (i = 0; i < 2; ++i) {
        if (docId.max_repetition_level == 0) {
            printf("row_%d: ", i);
            int id = readDocId(test_data, &id_offset);
            printf("%d\t", id);
        } else {

        }


        if (n_l_country->max_repetition_level == 0) {

        } else {

            if (*r_level == 0) {
                char *country = readNLCountry(test_data, &country_offset);
                printf("%s\t", country);
                //读取下一条记录
                readBits(bits, max_r_len, max_d_len, r_level, d_level);
                bits += (max_r_len + max_d_len);
                while (*r_level != 0) {
                    if (*d_level > *r_level) {
                        char *col2 = readNLCountry(test_data, &country_offset);
                        printf("%s\t", col2);
                    } else {
                        printf("NULL\t");
                    }
                    readBits(bits, max_r_len, max_d_len, r_level, d_level);
                    bits += (max_r_len + max_d_len);
                }
            }
            printf("\n");
        }

    }
}

/*
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
}*/
