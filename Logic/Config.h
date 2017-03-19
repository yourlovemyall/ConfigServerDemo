//
// Created by xuxiaoyu on 16/8/26.
//

#ifndef COMMONCONFIG_CONFIG_H
#define COMMONCONFIG_CONFIG_H

#include <string.h>

    class Config {
    public:

        Config(int modId, int cmdId, std::string configString) {
            p_modId = modId;
            p_cmdId = cmdId;
            p_configString = configString;
        }

        int getModId() { return p_modId; }

        int getCmdId() { return p_cmdId; }

        std::string getConfigString() {
            return p_configString;
        }

        int getConfigKey() {
            return p_modId * 10000 + p_cmdId;
        }

    private:
        int p_modId;
        int p_cmdId;
        std::string p_configString;
    };

#endif //COMMONCONFIG_CONFIG_H
