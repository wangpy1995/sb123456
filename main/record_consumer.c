//
// Created by wangpengyu6 on 18-7-2.
//

#include "record_consumer.h"

typedef unsigned char State;

typedef State(*Procedure)(void *);

enum States {
    INIT,
    READ_NEXT,
    READ_CURRENT,
    FINISH
};

static State init(void *event) {
    FSM_VAR *e = (FSM_VAR *) (event);
    e->r_level = 0;
    e->d_level = 0;
    return READ_NEXT;
}

static State readNext(void *event) {
    FSM_VAR *e = (FSM_VAR *) (event);
    if (e->r_level != 0) {
        while (e->d_level > 1) {

        }
        return READ_CURRENT;
    } else {
        return READ_NEXT;
    }
}

static State readCurrent(void *event) {
    FSM_VAR *e = (FSM_VAR *) (event);
    if (e->r_level != 0) {
        while (e->d_level > 1){

        }
            return READ_CURRENT;
    } else {
        return READ_NEXT;
    }
}

static State finish(void *event) {
    FSM_VAR *e = (FSM_VAR *) (event);
    return FINISH;
}

Procedure Step[] = {init,};
