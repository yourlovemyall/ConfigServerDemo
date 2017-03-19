//
// Created by xuxiaoyu on 16/8/18.
//

#ifndef COMMONCONFIG_DBBASE_H
#define COMMONCONFIG_DBBASE_H

#include <string>
#include "ConnectionWorker.h"
#include "ConnectionPool.h"
using namespace std;

class DbBase {
public:
    DbBase(){}
    ~DbBase(){};
    void exec(string sql){
        printf("exec sql:%s\n", sql.c_str());
        connectionPool->GetIdleThread()->SetJob((char *)sql.c_str());
    }

private:
    ConnectionPool* connectionPool = ConnectionPool::GetInstance();
};


#endif //COMMONCONFIG_DBBASE_H
