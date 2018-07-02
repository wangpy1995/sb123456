//
// Created by wpy on 18-6-27.
//

#ifndef SB123456_TESTFSM_H
#define SB123456_TESTFSM_H

#ifdef __cplusplus
extern "C" {
#endif
typedef struct _SM_VAR  //对状态机参数封装
{
    int cnt;
} SM_VAR;
void TestFSM(void *event);

#ifdef __cplusplus
}
#endif

#endif //SB123456_TESTFSM_H
