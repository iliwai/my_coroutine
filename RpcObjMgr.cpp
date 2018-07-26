#include "RpcObjMgr.h"

RpcObjMgr::RpcObjMgr()
{
}

RpcObjMgr::~RpcObjMgr()
{
}

RpcObjMgr* RpcObjMgr::Instance()
{
    static RpcObjMgr mgr;
    return &mgr;
}

bool RpcObjMgr::Insert(RpcBaseObj* obj)
{
    if (!obj)
    {
        return false;
    }
    uint32_t id = obj->Id();
    if (id_2_obj_.find(id) != id_2_obj_.end())
    {
        return false;
    }
    auto ret = id_2_obj_.insert(std::pair<uint32_t, RpcBaseObj*>(id, obj));
    return ret.second;
}

RpcBaseObj* RpcObjMgr::Get(const uint32_t id)
{
    auto iter = id_2_obj_.find(id);
    if (iter == id_2_obj_.end())
    {
        return nullptr;
    }
    return iter->second;
}

RpcObjMgr::RpcObjMgr(const RpcObjMgr &obj_mgr) {}

RpcObjMgr& RpcObjMgr::operator=(const RpcObjMgr &obj_mgr) {}

