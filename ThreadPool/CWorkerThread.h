//
// Created by xuxiaoyu on 16/8/13.
//

#ifndef COMMONCONFIG_CWORKTHREAD_H
#define COMMONCONFIG_CWORKTHREAD_H


#include "CThread.h"
#include "CJob.h"
#include "CCondition.h"
#include "CThreadMutex.h"

class CThreadPool;

class CWorkerThread:public CThread
{
private:
    CThreadPool *m_ThreadPool;
    CJob *m_Job;
    void* m_JobData;

    CThreadMutex m_VarMutex;
    bool      m_IsEnd;
protected:
public:
    CCondition   m_JobCond;
    CThreadMutex m_WorkMutex;
    CWorkerThread();
    virtual ~CWorkerThread();
    void Run();
    void    SetJob(CJob* job,void* jobdata);
    CJob*   GetJob(void){return m_Job;}
    void    SetThreadPool(CThreadPool* thrpool);
    //CThreadPool* GetThreadPool(void){return m_ThreadPool;}
};


#endif //COMMONCONFIG_CWORKTHREAD_H
