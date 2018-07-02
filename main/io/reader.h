//
// Created by wangpengyu6 on 18-6-29.
//

#ifndef SB123456_READER_H
#define SB123456_READER_H

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(1)
typedef struct DataPage {
    int64_t count;
    unsiged char max_bit_len;
    int64_t data_offset;
    char bits[];
} DataPage;


#ifdef __cplusplus
}
#endif
#endif //SB123456_READER_H
