#include "RpcBaseObj.h"

RpcBaseObj::RpcBaseObj()
    : id_(++g_rpc_obj_id)
{
    if (0 == id_)
    {
        id_ = ++g_rpc_obj_id;
    }
}

RpcBaseObj::~RpcBaseObj()
{
}

uint32_t RpcBaseObj::Id()
{
    return id_;
}
