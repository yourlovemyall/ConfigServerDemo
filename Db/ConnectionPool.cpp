//
// Created by xuxiaoyu on 16/8/15.
//

#include "ConnectionPool.h"

ConnectionPool::ConnectionPool(unsigned int initNum, unsigned int low, unsigned int max)
{
    m_MaxNum   = max;
    m_AvailLow = low;
    m_InitNum=m_AvailNum = initNum ;
    m_AvailHigh = max/2;

    m_BusyList.clear();
    m_IdleList.clear();
    for(int i=0;i<m_InitNum;i++){
        ConnectionWorker* thr = new ConnectionWorker();
        AppendToIdleList(thr);
        thr->SetThreadPool(this);
        thr->Start();       //begin the thread,the thread wait for job
    }
}

ConnectionPool::~ConnectionPool()
{
    TerminateAll();
}

void ConnectionPool::TerminateAll()
{
    for(int i=0;i < m_ThreadList.size();i++) {
        ConnectionWorker* thr = m_ThreadList[i];
        thr->Terminate();
    }
    return;
}

ConnectionWorker* ConnectionPool::GetIdleThread(void)
{
    while(m_IdleList.size() ==0 )
        m_IdleCond.wait(m_IdleMutex.get_mutex());

    m_IdleMutex.Lock();
    if(m_IdleList.size() > 0 )
    {
        ConnectionWorker* thr = (ConnectionWorker*)m_IdleList.front();
        m_IdleMutex.Unlock();
        return thr;
    }else{
        //if the busy thread num adds to m_MaxNum,so we should wait
        if(GetBusyNum() == m_MaxNum)
            m_MaxNumCond.wait(m_BusyMutex.get_mutex());

        if(m_IdleList.size()<m_AvailLow)
        {
            if(GetAllNum()+m_InitNum-m_IdleList.size() < m_MaxNum )
                CreateIdleThread(m_InitNum - (int)m_IdleList.size());
            else
                CreateIdleThread(m_MaxNum-GetAllNum());
        }

        ConnectionWorker*  worker = GetIdleThread();
        if(worker !=NULL)
        {
            worker->m_WorkMutex.Lock();
            MoveToBusyList(worker);
            worker->SetThreadPool(this);
            m_IdleMutex.Unlock();
            return worker;
        }
    }

    m_IdleMutex.Unlock();
    return NULL;
}

//add an idle thread to idle list
void ConnectionPool::AppendToIdleList(ConnectionWorker* jobthread)
{
    m_IdleMutex.Lock();
    m_IdleList.push_back(jobthread);
    m_ThreadList.push_back(jobthread);
    m_IdleMutex.Unlock();
}

//move and idle thread to busy thread
void ConnectionPool::MoveToBusyList(ConnectionWorker* idlethread)
{
    m_BusyMutex.Lock();
    m_BusyList.push_back(idlethread);
    m_AvailNum--;
    m_BusyMutex.Unlock();

    m_IdleMutex.Lock();
    vector<ConnectionWorker*>::iterator pos;
    pos = find(m_IdleList.begin(),m_IdleList.end(),idlethread);
    if(pos !=m_IdleList.end())
        m_IdleList.erase(pos);
    m_IdleMutex.Unlock();
}


void ConnectionPool::MoveToIdleList(ConnectionWorker* busyThread)
{
    //将线程移除到空闲线程队列
    m_IdleMutex.Lock();
    m_IdleList.push_back(busyThread);
    m_AvailNum++;
    m_IdleMutex.Unlock();

    //将线程移动到忙碌线程队列
    m_BusyMutex.Lock();
    vector<ConnectionWorker*>::iterator pos;
    pos = find(m_BusyList.begin(),m_BusyList.end(),busyThread);
    if(pos!=m_BusyList.end())
        m_BusyList.erase(pos);
    m_BusyMutex.Unlock();

    //释放信号
    m_IdleCond.signal();
    m_MaxNumCond.signal();
}

//create num idle thread and put them to idlelist
void ConnectionPool::CreateIdleThread(int num)
{
    for(int i=0;i<num;i++){
        ConnectionWorker* thr = new ConnectionWorker();
        thr->SetThreadPool(this);
        AppendToIdleList(thr);
        m_VarMutex.Lock();
        m_AvailNum++;
        m_VarMutex.Unlock();
        thr->Start();       //begin the thread,the thread wait for job
    }
}

//delete
void ConnectionPool::DeleteIdleThread(int num)
{
    printf("Enter into ConnectionPool::DeleteIdleThread\n");
    m_IdleMutex.Lock();
    printf("Delete Num is %d\n",num);
    for(int i=0;i<num;i++){
        ConnectionWorker* thr;
        if(m_IdleList.size() > 0 ){
            thr = (ConnectionWorker*)m_IdleList.front();
            //printf("Get Idle thread %l\n",(unsigned long)thr->GetThreadID());
        }{
            thr = NULL;
        }

        vector<ConnectionWorker*>::iterator pos;
        pos = find(m_IdleList.begin(),m_IdleList.end(),thr);
        if(pos!=m_IdleList.end())
            m_IdleList.erase(pos);

        m_AvailNum--;
        //printf("The idle thread available num:%l \n",m_AvailNum);
        //printf("The idleList              num:%l \n",m_IdleList.size());
    }

    m_IdleMutex.Unlock();
}
