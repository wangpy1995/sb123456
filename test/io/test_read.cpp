//
// Created by wpy on 18-7-2.
//

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <gtest/gtest.h>
#include "reader.h"

#pragma pack(1)
typedef union _BITS2 {
    unsigned bit2:2;
    unsigned bit4:2;
    unsigned bit6:2;
    unsigned bit8:2;
} Bits2;

//int
DataPage docId;

//char*  bit长度均为2  字符串'\a'分割
DataPage n_l_country;


#pragma pack(1)
struct _TEST_DATA {
    int doc_id[2];
    char country[5];
};

char *test_data;

void before() {

    docId.max_repetition_level_len = 0;
    docId.max_definition_level_len = 0;
    docId.count = (int64_t) 2;
    docId.data_offset = (int64_t) 0;

    Bits2 bits2[3];
    //r = 0, d = 3
    bits2[0].bit2 = 3;
    bits2[0].bit4 = 0;
    //r = 2, d = 2
    bits2[0].bit6 = 2;
    bits2[0].bit8 = 2;
    //r = 1, d = 1
    bits2[1].bit2 = 1;
    bits2[1].bit4 = 1;
    //r = 1, d = 3
    bits2[1].bit6 = 3;
    bits2[1].bit8 = 1;
    //r = 0, d = 1
    bits2[2].bit2 = 1;
    bits2[2].bit4 = 0;

    n_l_country.max_repetition_level_len = 2;
    n_l_country.max_definition_level_len = 2;
    n_l_country.count = (int64_t) 5;
    n_l_country.data_offset = (int64_t) 0 + docId.count * sizeof(int);
    n_l_country.bits[0] = *(Bits *) bits2;
    n_l_country.bits[1] = *(Bits *) (bits2 + 1);
    n_l_country.bits[2] = *(Bits *) (bits2 + 2);

    struct _TEST_DATA data = {
            .doc_id={1, 2},
            .country={'u', 's', '\a', 'g', 'b'}
    };
    test_data = (char *) &data;
}

int readDocId(const char *data, size_t *offset) {
    data += *offset;
    *offset += sizeof(int);
    return *(int *) data;
}

char *readNLCountry(char *data, size_t *offset) {
    data += *offset;
    size_t i = 0;
    while (data[i] != '\a') {
        ++i;
    }
    auto *cl = (char *) malloc(i * sizeof(char));
    memcpy(cl, data, i);
    *offset += i * sizeof(char);
    return cl;
}


//读取两个bit值    r=0,d=3,shift_right=0  => 0x000000 | 03
void readBits(unsigned char bits, unsigned char shift_right, unsigned char r_len, unsigned char d_len,
              unsigned char *r_level,
              unsigned char *d_level) {
    *d_level = static_cast<unsigned char>((bits >> shift_right) & 0x03);
    *r_level = static_cast<unsigned char>((bits >> shift_right) & 0x0a);
}

TEST(test, read) {
    before();
    unsigned char r, d = 0;
    size_t *offset = nullptr;
    unsigned char *r_level, *d_level;
    unsigned char *bits;
    r_level = &r;
    d_level = &d;
    int i;
    for (i = 0; i < 2; ++i) {
        if (docId.max_repetition_level_len == 0) {
            *offset = docId.data_offset;
            readDocId(test_data, offset);
            docId.data_offset = *offset;
        } else {

        }

        if (n_l_country.max_repetition_level_len == 0) {

        } else {
            bits = reinterpret_cast<unsigned char *>(n_l_country.bits);
            *offset = n_l_country.data_offset;
            readNLCountry(test_data, offset);
            n_l_country.data_offset = *offset;
        }
    }

}
