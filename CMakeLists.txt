cmake_minimum_required(VERSION 3.6)
project(commonconfig)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Server.cpp Server.h CBusinessJob.h Logic/ShmMap.h)
set(EXECUTABLE_OUTPUT_PATH bin)
include_directories(
        /usr/local/mysql/include
        ThreadPool
        Db
        Logic
)
find_package(RapidJSON)
LINK_DIRECTORIES("/usr/local/mysql/lib" "Db" "ThreadPool" "Logic")
add_library(dbthread
        ThreadPool/CThreadManage.cpp ThreadPool/CThreadPool.cpp ThreadPool/CJob.cpp ThreadPool/CWorkerThread.cpp
        ThreadPool/CThreadMutex.cpp ThreadPool/CThread.cpp ThreadPool/CCondition.cpp
        Db/ConnectionWorker.cpp Db/ConnectionPool.cpp Db/Connection.cpp Db/DbBase.cpp
        )
add_executable(commonconfig ${SOURCE_FILES})
target_link_libraries(commonconfig mysqlclient dbthread)


