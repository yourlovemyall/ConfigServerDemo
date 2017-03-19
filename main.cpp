#include <iostream>
#include "Server.h"
#include "Db/ConnectionPool.h"

int main() {
    std::cout << "Hello, World1!" << std::endl;
    //ConnectionPool *pool = ConnectionPool::GetInstance();
    Server *server = new Server();
    server->start();
    return 0;
}