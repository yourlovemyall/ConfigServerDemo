//
// Created by xuxiaoyu on 16/8/13.
//

#include "CThreadManage.h"

CThreadManage::CThreadManage()
{
    m_Pool = new CThreadPool();
}

CThreadManage::CThreadManage(int num, int low, int max)
{
    m_Pool = new CThreadPool(num, low, max);
}

CThreadManage::~CThreadManage()
{
    if(NULL != m_Pool)
        delete m_Pool;
    m_Pool = NULL;
}

//void CThreadManage::SetParallelNum(int num)
//{
//    m_NumOfThread = num;
//}

void CThreadManage::Run(CJob* job,void* jobdata)
{
    printf("CThreadManage::Run|begin to deal job.\n");
    m_Pool->Run(job,jobdata);
}

void CThreadManage::TerminateAll(void)
{
    m_Pool->TerminateAll();
}
