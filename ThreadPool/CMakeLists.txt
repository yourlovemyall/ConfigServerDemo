# 设置编译器
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# 源文件列表
set(SRC_LIST CThreadManage.cpp CThreadManage.h CThreadPool.cpp CThreadPool.h CWorkerThread.cpp CWorkerThread.h CThread.cpp CThread.h CJob.cpp CJob.h CThreadMutex.cpp CThreadMutex.h CCondition.cpp CCondition.h)

set(LIBRARY_OUTPUT_PATH ../lib)

# 生成的库文件
add_library(ThreadPool STATIC ${SRC_LIST})
