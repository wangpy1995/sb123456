//
// Created by wangpengyu6 on 18-7-2.
//

#ifndef SB123456_RECORD_CONSUMER_H
#define SB123456_RECORD_CONSUMER_H

typedef struct _FSM_VAR {
    int r_level;    //r_level=0开始一条新记录
    int d_level;   //d_level>1上一个字段填充null值
} FSM_VAR;

class record_consumer {

};


#endif //SB123456_RECORD_CONSUMER_H
