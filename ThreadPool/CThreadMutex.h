//
// Created by xuxiaoyu on 16/8/13.
//

#ifndef COMMONCONFIG_CTHREADMUTEX_H
#define COMMONCONFIG_CTHREADMUTEX_H

#include <pthread.h>

class CThreadMutex {

public:

    CThreadMutex();

    virtual ~CThreadMutex();

    pthread_mutex_t* get_mutex();

    void Lock();

    void Unlock();

private:

    pthread_mutex_t m_threadMutex;

};


#endif //COMMONCONFIG_CTHREADMUTEX_H
