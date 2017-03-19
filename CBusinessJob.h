//
// Created by xuxiaoyu on 16/8/14.
//

#ifndef COMMONCONFIG_CBUSINESSJOB_H
#define COMMONCONFIG_CBUSINESSJOB_H

#include "CJob.h"
#include <unistd.h>

#include "Db/DbBase.h"
#include "Logic/ShmMap.h"

#include "rapidjson/document.h"

using namespace rapidjson;

class CBusinessJob : public CJob{

private:
public:
    CBusinessJob() {

    }
    void Run(void* buffer)
    {
        printf("JSON decode RESULT1\n");

        ShmMap *cs = new ShmMap();
        printf("JSON decode RESULT2\n");
        string buffer2 = "{\"modId\":1001,\"cmdId\":2001,\"data\":\"121212\"}";
        Document d;
        const char* s_modId = "modId";
        const char* s_cmdId = "cmdId";
        const char* s_data = "data";
        try {
            d.Parse(buffer2.c_str());
            Value& v_modId = d[s_modId];
            Value& v_cmdId = d[s_cmdId];
            Value& v_data  = d[s_data];
            printf("JSON decode RESULT3\n");
            if ( s_modId != NULL && s_cmdId != NULL && s_data != NULL) {
                printf("JSON decode RESULT4\n");
                Config *config = new Config(v_modId.GetInt(), v_cmdId.GetInt(), v_data.GetString());
                printf("JSON decode RESULT5\n");
                cs->getMap()->set(config);
                printf("JSON decode success: %s\n", cs->getMap()->get(v_modId.GetInt(), v_cmdId.GetInt()).c_str());
            }
        }catch (exception e){
            printf("JSON decode failed:%s\n",e.what());
        }

        //DbBase *db = new DbBase();
        //db->exec("update gxq_user set ctime = 4 where uid = 1");
        //printf("Success\n");
        printf("JSON decode RESULT\n");
    }
};


#endif //COMMONCONFIG_CBUSINESSJOB_H
