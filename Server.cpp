//
// Created by xuxiaoyu on 16/8/11.
//

#include "Server.h"

int Server::start() {
    //(new CBusinessJob())->Run(NULL);return 0;
    CThreadManage *manager = new CThreadManage(10, 50, 100);//线程池

    //创建套接字
    int serverSocket= socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in server_addr;
    struct sockaddr_in clientAddr;

    int addr_len = sizeof(clientAddr);
    int client;
    char buffer[200];
    //创建地址
    bzero(&server_addr,sizeof(server_addr));
    server_addr.sin_family =AF_INET;
    server_addr.sin_port = htons(5555);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    //绑定
    bind(serverSocket,(struct sockaddr *)&server_addr,sizeof(server_addr));

    //帧听
    listen(serverSocket,5);
    printf("Success\n");
    //接收
    client=accept(serverSocket,(sockaddr *)&clientAddr,(socklen_t*)&addr_len);

    while(1)
    {
        if(recv(client,buffer,sizeof(buffer),0)>0){
            printf("客户端发过来的 : %s\n",buffer);
            manager->Run(new CBusinessJob(), buffer);
        }
    }
}