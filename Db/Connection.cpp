//
// Created by xuxiaoyu on 16/8/15.
//

#include "Connection.h"

Connection::Connection(const char* ip,
                       const char* port,
                       const char* user,
                       const char* password,
                       const char* database) {
    m_ip = ip;
    m_port = port;
    m_user = user;
    m_password = password;
    m_database = database;
    mysql_init(&m_conn);
    if(mysql_real_connect(&m_conn, ip, user, password, database, 3306, NULL, 0) == NULL){
        //m_conn = NULL;
    }
}

Connection::~Connection() {
    mysql_close(&m_conn);
}

void Connection::CloseConnect() {
    mysql_close(&m_conn);
}

void Connection::ReConnect() {
    int i =0;
    while(i<3){
        CloseConnect();
        if(mysql_real_connect(&m_conn, m_ip.c_str(), m_user.c_str(), m_password.c_str(), m_database.c_str(), 3306, NULL, 0) == NULL){
            //m_conn = NULL;
        }else{
            break;
        }
        i++;
    }
}

Connection* Connection::createCommand(string sql) {
    m_sql = sql;
    return this;
}

int Connection::execute() {
    try {
        if(mysql_real_query(&m_conn, m_sql.c_str(), strlen(m_sql.c_str())) != 0){
            //错误异常
            printf("whatfunk %s\n",mysql_error(&m_conn));
            return 0;
        }
        return 1;
    }catch (exception e){
        printf("whatfunk 2\n");
    }
    return 0;
}

void Connection::query() {

}