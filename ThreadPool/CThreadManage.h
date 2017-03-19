//
// Created by xuxiaoyu on 16/8/13.
//

#ifndef COMMONCONFIG_CTHREADMANAGE_H
#define COMMONCONFIG_CTHREADMANAGE_H

//https://github.com/donaldhuang/threadpool/blob/master/makefile

#include "CThreadPool.h"
#include "CJob.h"

class CThreadManage
{
private:
    CThreadPool* m_Pool;
    int          m_NumOfThread;
protected:
public:
    CThreadManage();
    CThreadManage(int num, int low, int max=100000);
    virtual ~CThreadManage();
//    void    SetParallelNum(int num);
    void    Run(CJob* job,void* jobdata);
    void    TerminateAll(void);
};

#endif //COMMONCONFIG_CTHREADMANAGE_H
