//
// Created by xuxiaoyu on 16/8/15.
//

#include "ConnectionWorker.h"
#include "ConnectionPool.h"

ConnectionWorker::ConnectionWorker()
{
    m_JobData = NULL;
    m_ThreadPool = NULL;
    m_IsEnd = false;
    taskFlag = 0;
    //初始化数据库链接
    m_conn = new Connection("rds.jfz.net", "3306", "root", "", "gunxueqiu");

}
ConnectionWorker::~ConnectionWorker()
{
    if(m_ThreadPool != NULL)
        delete m_ThreadPool;
    if(NULL != m_conn)
        delete m_conn;
}

void ConnectionWorker::Run()
{
    //SetThreadState(THREAD_RUNNING);
    for(;;)
    {
        while(!taskFlag)
            m_JobCond.wait(m_VarMutex.get_mutex());

        int res = m_conn->createCommand((char *)m_JobData)->execute();
        printf("exec res:%d\n", res);
        taskFlag = 0;
        m_ThreadPool->MoveToIdleList(this);
        if(m_ThreadPool->m_IdleList.size() > m_ThreadPool->GetAvailHighNum())
        {
            m_ThreadPool->DeleteIdleThread(m_ThreadPool->m_IdleList.size()-m_ThreadPool->GetInitNum());
        }
        m_WorkMutex.Unlock();
    }
}
void ConnectionWorker::SetJob(void* jobData)
{
    m_VarMutex.Lock();
    taskFlag = 1;
    m_JobData = jobData;
    m_VarMutex.Unlock();
    m_JobCond.signal();
}
void ConnectionWorker::SetThreadPool(ConnectionPool* pool)
{
    m_VarMutex.Lock();
    m_ThreadPool = pool;
    m_VarMutex.Unlock();
}
