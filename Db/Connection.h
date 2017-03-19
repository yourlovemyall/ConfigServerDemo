//
// Created by xuxiaoyu on 16/8/15.
//

#ifndef COMMONCONFIG_CONNECTION_H
#define COMMONCONFIG_CONNECTION_H

#include <string>
#include <cstdlib>
#include "mysql.h"
using namespace std;

class Connection {
public:
    Connection(const char* ip, const char* port, const char* user, const char* password, const char* database);
    ~Connection();
    MYSQL* getConn(){return &m_conn;};
    void CloseConnect();
    void ReConnect();
    Connection* createCommand(string sql);
    int execute();
    void query();

private:
    MYSQL m_conn;
    string m_ip;
    string m_port;
    string m_user;
    string m_password;
    string m_database;

    string m_sql;
};


#endif //COMMONCONFIG_CONNECTION_H
