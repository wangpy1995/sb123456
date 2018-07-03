//
// Created by wpy on 18-7-2.
//



#include <stdio.h>
#include <string.h>
#include "reader.h"

#ifdef __cplusplus

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
#endif
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
DataPage *n_l_country;


#pragma pack(1)
struct _TEST_DATA {
    int doc_id[2];
    char country[6];
};


const struct _TEST_DATA t_data = {
        .doc_id={10, 20},
        .country={'u', 's', '\a', 'g', 'b'}
};

char *test_data = (char *) &t_data;

void before() {

    docId.max_definition_level = 0;
    docId.max_repetition_level = 0;
    docId.count = (int64_t) 2;
    docId.data_offset = (int64_t) 0;

    n_l_country = (DataPage *) (malloc(sizeof(DataPage) + (2 + 2) * 5 * sizeof(Bits)));

    //r = 0, d = 3
    n_l_country->bits[0].bit0 = 0x0;
    n_l_country->bits[1].bit0 = 0x0;
    n_l_country->bits[2].bit0 = 0x1;
    n_l_country->bits[3].bit0 = 0x1;
    //r = 2, d =2
    n_l_country->bits[4].bit0 = 0x1;
    n_l_country->bits[5].bit0 = 0x0;
    n_l_country->bits[6].bit0 = 0x1;
    n_l_country->bits[7].bit0 = 0x0;
    //r = 1, d =1
    n_l_country->bits[8].bit0 = 0x0;
    n_l_country->bits[9].bit0 = 0x1;
    n_l_country->bits[10].bit0 = 0x0;
    n_l_country->bits[11].bit0 = 0x1;
    //r = 1, d = 3
    n_l_country->bits[12].bit0 = 0x0;
    n_l_country->bits[13].bit0 = 0x0;
    n_l_country->bits[14].bit0 = 0x1;
    n_l_country->bits[15].bit0 = 0x1;
    //r = 0, d = 1
    n_l_country->bits[16].bit0 = 0x0;
    n_l_country->bits[17].bit0 = 0x0;
    n_l_country->bits[18].bit0 = 0x0;
    n_l_country->bits[19].bit0 = 0x1;

    n_l_country->max_repetition_level = 2;
    n_l_country->max_definition_level = 3;
    n_l_country->count = (int64_t) 5;
    n_l_country->data_offset = (int64_t) 0 + docId.count * sizeof(int);
}

int readDocId(const char *data, size_t *offset) {
    data += *offset;
    *offset += sizeof(int);
    return *(int *) data;
}

char *readNLCountry(char *data, size_t *offset) {
    data += *offset;
    size_t i = 0;
    while (data[i] != '\a' && data[i] != '\0') {
        ++i;
    }
    char *cl = (char *) malloc(i * sizeof(char));
    memcpy(cl, data, i);
    *offset += i * sizeof(char) + 1;
    return cl;
}


//读取两个值     r=0,d=3,r_len=2,d_len=2  bits={0011}
void readBits(const Bits *bits, const unsigned char r_len, const unsigned char d_len,
              unsigned char *r_level,
              unsigned char *d_level) {
    int i;
    unsigned char r = 0, d = 0;
    for (i = r_len - 1; i >= 0; --i) {
        r += (bits->bit0 << i);
        ++bits;
    }
    for (i = d_len - 1; i >= 0; --i) {
        d += (bits->bit0 << i);
        ++bits;
    }
    *r_level = r;
    *d_level = d;
}

unsigned char bitCount(unsigned char x) {
    x = x - ((x >> 1) & 0x55);
    x = (x & 0x33) + ((x >> 2) & 0x33);
    x = (x & 0x0f) + ((x >> 4) & 0x0f);
    return x;
}

unsigned char highestBitPos(unsigned char x) {
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    return x ^ (x >> 1);
}

#ifdef __cplusplus
}
#endif

