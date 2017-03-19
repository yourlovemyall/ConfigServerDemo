//
// Created by xuxiaoyu on 16/8/13.
//

#ifndef COMMONCONFIG_CCONDITION_H
#define COMMONCONFIG_CCONDITION_H

#include "pthread.h"

class CCondition{
public:
    CCondition();
    ~CCondition();
public:
    void wait(pthread_mutex_t *);
    void signal();
private:
    pthread_cond_t m_cond;
};

#endif //COMMONCONFIG_CCONDITION_H
