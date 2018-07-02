//
// Created by wangpengyu6 on 18-7-2.
//

#ifndef SB123456_TEST_SCHEMA_H
#define SB123456_TEST_SCHEMA_H


//字符串暂时使用‘\A’分割  不记录长度
struct _TEST_SCHEMA {
    char max_len;
    char *owner;   //required

    char phone_nums;
    int64_t *phone_number;  //repeated

    char contacts_nums;
    char *contacts_name;    //optional_optional
    int64_t *contacts_phone_number;     //optional_repeated

} ADDRESS;

#endif //SB123456_TEST_SCHEMA_H
