//
// Created by xuxiaoyu on 16/8/26.
//

#ifndef COMMONCONFIG_CONFIGSETTING_H
#define COMMONCONFIG_CONFIGSETTING_H

#include <map>
#include "Config.h"
/*
#ifdef __GNUC__
#include <ext/hash_map>
using __gnu_cxx::hash_map;
#else
#include <hash_map>
#endif*/

    class ConfigSetting {
    public:
        ConfigSetting() {
        }

        ~ConfigSetting() {}

        void set(Config *config) {

            printf("JSON decode RESULT21\n");
            int configKey = config->getConfigKey();
            //插入内存缓存
            printf("JSON decode RESULT22---%d\n", configKey);
            printf("JSON decode RESULT22---%s\n", config->getConfigString().c_str());
            //configList[configKey] = config.getConfigString();
            //configList.insert(pair<int,string>(configKey, config->getConfigString()));
            //configList.insert(configKey, );
            printf("JSON decode RESULT23\n");
            //保存到文件
            setFile(configKey, config->getConfigString());
            //printf("List Count: %d", (int)configList.size());
        }

        string get(int modId, int cmdId) {

            Config *config = new Config(modId, cmdId, "");
            int configKey = config->getConfigKey();
            //插入内存缓存
            //printf("JSON decode RESULT20\n");
            //return configList[configKey];
            return "";
        }

    private:
        void setFile(int configKey, string configString) {}
        //map<int,string> configList;

    };


#endif //COMMONCONFIG_CONFIGSETTING_H
