//
// Created by xuxiaoyu on 16/8/11.
//

#ifndef COMMONCONFIG_SERVER_H
#define COMMONCONFIG_SERVER_H

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ThreadPool/CThreadManage.h"
#include "Db/ConnectionPool.h"
#include "CBusinessJob.h"

class Server {

    public:
        int start();

    private:
        char *host;
        int port;

};


#endif //COMMONCONFIG_SERVER_H
