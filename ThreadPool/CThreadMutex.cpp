//
// Created by xuxiaoyu on 16/8/13.
//

#include "CThreadMutex.h"
#include <iostream>
CThreadMutex::CThreadMutex() {
    if (pthread_mutex_init(&m_threadMutex,NULL)) {
        std::cout << "init ThreadMutex failed!" << std::endl;
    }
}
CThreadMutex::~CThreadMutex() {
    if (pthread_mutex_destroy(&m_threadMutex)){
        std::cout << "destroy ThreadMutex failed!" << std::endl;
    }
}

pthread_mutex_t* CThreadMutex::get_mutex() {
    return &m_threadMutex;
}
void CThreadMutex::Lock() {
    if (pthread_mutex_lock(&m_threadMutex))
        std::cout << "lock failed!" << std::endl;
}
void CThreadMutex::Unlock() {
    if (pthread_mutex_unlock(&m_threadMutex))
        std::cout << "unlock failed!" << std::endl;
}