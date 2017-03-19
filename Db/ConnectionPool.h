//
// Created by xuxiaoyu on 16/8/15.
//

#ifndef COMMONCONFIG_CONNECTIONPOOL_H
#define COMMONCONFIG_CONNECTIONPOOL_H

#include "ConnectionWorker.h"
#include "../ThreadPool/CThreadMutex.h"
#include "../ThreadPool/CCondition.h"
#include <vector>
using namespace std;

class ConnectionPool
{
    friend class ConnectionWorker;

private:
    unsigned int m_MaxNum;   //the max thread num that can create at the same time
    unsigned int m_AvailLow; //The min num of idle thread that shoule kept
    unsigned int m_AvailHigh;    //The max num of idle thread that kept at the same time
    unsigned int m_AvailNum; //the normal thread num of idle num;
    unsigned int m_InitNum;  //Normal thread num;
    static CThreadMutex poolMutex;
    ConnectionPool(unsigned int initNum, unsigned int low, unsigned int max);
    ConnectionPool(const ConnectionPool&);
    ConnectionPool&operator = (const ConnectionPool&);

protected:

    void    AppendToIdleList(ConnectionWorker* jobthread);

    void    MoveToBusyList(ConnectionWorker* idlethread);

    void    MoveToIdleList(ConnectionWorker* busythread);

    void    DeleteIdleThread(int num);

    void    CreateIdleThread(int num);

public:

    CThreadMutex m_BusyMutex;    //when visit busy list,use m_BusyMutex to lock and unlock
    CThreadMutex m_IdleMutex;    //when visit idle list,use m_IdleMutex to lock and unlock
    CThreadMutex m_VarMutex;

    CCondition       m_BusyCond; //m_BusyCond is used to sync busy thread list
    CCondition       m_IdleCond; //m_IdleCond is used to sync idle thread list
    CCondition       m_MaxNumCond;

    vector<ConnectionWorker*>   m_ThreadList;
    vector<ConnectionWorker*>   m_BusyList;     //Thread List
    vector<ConnectionWorker*>   m_IdleList; //Idle List

    virtual ~ConnectionPool();

    int     GetAvailHighNum(void){return m_AvailHigh;}
    int     GetAllNum(void){return (int)m_ThreadList.size();}
    int     GetBusyNum(void){return (int)m_BusyList.size();}
    int     GetInitNum(void){return m_InitNum;}
    void    TerminateAll(void);

    ConnectionWorker* GetIdleThread(void);
    static ConnectionPool* GetInstance(){
        static ConnectionPool connectionPool(10,10,20);
        return &connectionPool;
    }

};


#endif //COMMONCONFIG_CONNECTIONPOOL_H
