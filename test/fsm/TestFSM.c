//
// Created by wpy on 18-6-27.
//

#include <stdio.h>
#include "TestFSM.h"

typedef unsigned char STATE;

typedef STATE(*Procedure)(void *);

enum states {
    s_init, s_count, s_done, s_default
};

STATE state_init(void *event) {
    SM_VAR *e = (SM_VAR *) (event);
    e->cnt = 0;
    printf("current state: init; cnt = %d; next state: count.\n", e->cnt);
    return s_count;
}

STATE state_count(void *event) {
    SM_VAR *e = (SM_VAR *) (event);
    if (e->cnt < 3) {
        ++e->cnt;
        printf("current state: count; cnt = %d; next state: count.\n", e->cnt);
        return s_count;
    } else {
        printf("current state: count; cnt = %d; next state: done.\n", e->cnt);
        return s_done;
    }
}

STATE state_done(void *event) {
    SM_VAR *e = (SM_VAR *) (event);
    printf("current state: done; cnt = %d; next state: init.\n", e->cnt);
    return s_init;
}

STATE state_default(void *event) {
    SM_VAR *e = (SM_VAR *) (event);
    printf("wrong state.\n");
    return s_init;
}


Procedure Steps[] = {state_init, state_count, state_done, state_default};

void TestFSM(void *event) {
    static STATE NS = s_init;
    NS = Steps[NS](event);
}