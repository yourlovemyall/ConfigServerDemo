//
// Created by xuxiaoyu on 16/9/1.
//

#ifndef COMMONCONFIG_SHMMAP_H
#define COMMONCONFIG_SHMMAP_H

#include "ConfigSetting.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUF_SIZE 1*1024*1024
#define MYKEY 1000

static int shmMap_first = 0;
class ShmMap{
public:
    ShmMap(){
        int shmid;
        //map<int,string> *configList;
        if((shmid = shmget(MYKEY, BUF_SIZE, IPC_CREAT)) == -1){
            printf("shmid :%d\n", shmid);
        }
        if((configSetting = (ConfigSetting *)shmat(shmid, 0 ,0)) == (void *)-1){
            printf("why\n");
        }
        if(!shmMap_first){
            configSetting = new ConfigSetting();
            shmMap_first ++;
        }
    }
    ConfigSetting * getMap(){
        return configSetting;
    };

private:
    ConfigSetting *configSetting;
    ~ShmMap(){}
};

#endif //COMMONCONFIG_SHMMAP_H
