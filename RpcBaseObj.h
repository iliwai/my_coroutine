#ifndef __RPC_BASE_OBJ_H__
#define __RPC_BASE_OBJ_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#ifdef __cplusplus
}
#endif

static uint32_t g_rpc_obj_id = 0;

class RpcBaseObj
{
public:
    RpcBaseObj();
    virtual ~RpcBaseObj();

    virtual void Run() = 0;
    uint32_t Id();
protected:
    uint32_t    id_;
};

#endif

