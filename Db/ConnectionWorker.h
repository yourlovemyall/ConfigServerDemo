//
// Created by xuxiaoyu on 16/8/15.
//

#ifndef COMMONCONFIG_CONNECTIONWORKER_H
#define COMMONCONFIG_CONNECTIONWORKER_H

#include "../ThreadPool/CThread.h"
#include "../ThreadPool/CThreadMutex.h"
#include "../ThreadPool/CCondition.h"
#include "Connection.h"

class ConnectionPool;

class ConnectionWorker:public CThread
{
private:
    ConnectionPool *m_ThreadPool;
    int taskFlag;
    void* m_JobData;
    Connection *m_conn;

    CThreadMutex m_VarMutex;
    bool      m_IsEnd;
protected:
public:
    CCondition   m_JobCond;
    CThreadMutex m_WorkMutex;
    ConnectionWorker();
    virtual ~ConnectionWorker();
    void Run();
    void SetThreadPool(ConnectionPool* pool);
    void SetJob(void* jobdata);
    Connection* GetConnection(){return m_conn;}
};



#endif //COMMONCONFIG_CONNECTIONWORKER_H
