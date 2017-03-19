//
// Created by xuxiaoyu on 16/8/13.
//

#include "CCondition.h"

CCondition::CCondition(){
    pthread_cond_init(&m_cond, NULL);
}

CCondition::~CCondition(){
    pthread_cond_destroy(&m_cond);
}

void CCondition::wait(pthread_mutex_t * mutex){
    pthread_cond_wait(&m_cond, mutex);
}

void CCondition::signal(){
    pthread_cond_signal(&m_cond);
}

