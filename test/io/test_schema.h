//
// Created by wangpengyu6 on 18-7-2.
//

#ifndef SB123456_TEST_SCHEMA_H
#define SB123456_TEST_SCHEMA_H


//字符串暂时使用‘\A’分割  不记录长度
typedef struct _TEST_SCHEMA {
    char max_len;
    char *owner;   //required

    char phone_nums;
    char *phone_number;  //repeated

    char contacts_nums;
    char *contacts_name;    //optional_optional
    char *contacts_phone_number;     //optional_repeated

} ADDRESS;


//offset + length
typedef struct _INTERNAL_ROW{
    char row[];
};

#endif //SB123456_TEST_SCHEMA_H

