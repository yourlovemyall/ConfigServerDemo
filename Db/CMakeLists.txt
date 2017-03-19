# 设置编译器
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# 源文件列表
set(SRC_LIST ConnectionWorker.cpp ConnectionWorker.h ConnectionPool.cpp ConnectionPool.h Connection.cpp Connection.h)

# 头文件目录
include_directories(
        /usr/local/mysql/include
        ../ThreadPool
)
LINK_DIRECTORIES("/usr/local/mysql/lib")
link_directories(lib)
set(LIBRARY_OUTPUT_PATH ../lib)
# 生成的库文件
add_library(Db STATIC ${SRC_LIST})
target_link_libraries(commonconfig mysqlclient ThreadPool)
