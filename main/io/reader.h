//
// Created by wangpengyu6 on 18-6-29.
//

#ifndef SB123456_READER_H
#define SB123456_READER_H


#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif


//bits
#pragma pack(1)
typedef union _BITS {
    unsigned bit0:1;
} Bits;

/**
 * 某一列数据的属性
 */
#pragma pack(1)
typedef struct DataPage {
    unsigned char max_repetition_level;
    unsigned char max_definition_level;
    int64_t count;
    size_t data_offset;
    Bits bits[];    //repetition + definition
} DataPage;


#ifdef __cplusplus
}
#endif
#endif //SB123456_READER_H
