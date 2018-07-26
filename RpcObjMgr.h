#ifndef __RPC_OBJ_MGR_H__
#define __RPC_OBJ_MGR_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#ifdef __cplusplus
}
#endif

#include <unordered_map>

#include "RpcBaseObj.h"

class RpcObjMgr
{
public:
    explicit RpcObjMgr();
    ~RpcObjMgr();

    static RpcObjMgr* Instance();

    bool Insert(RpcBaseObj* obj);
    RpcBaseObj* Get(const uint32_t id);

private:
    RpcObjMgr(const RpcObjMgr &obj_mgr);
    RpcObjMgr& operator=(const RpcObjMgr &obj_mgr);
    
    std::unordered_map<uint32_t, RpcBaseObj*> id_2_obj_;
};

#endif

