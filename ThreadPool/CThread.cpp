//
// Created by xuxiaoyu on 16/8/13.
//

#include "CThread.h"
CThread::CThread()
{
    m_thread = new pthread_t;
}

CThread::~CThread()
{
    if(m_thread != NULL)
        delete m_thread;
    m_thread = NULL;
}

void* CThread::ThreadFunction(void* arg)
{
    CThread* t = (CThread*) arg;
    t->Run();
    return NULL;
}

bool CThread::Start()
{
    int rc = pthread_create(m_thread, NULL, ThreadFunction, this);
    m_ThreadID = (unsigned long)*m_thread;
    printf("CThread::CThread|thread has been created, id is:%lu\n",GetThreadID());
    assert(rc == 0);
    return true;

}

bool CThread::Terminate(){
    delete this;
    return true;
}
