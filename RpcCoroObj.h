#ifndef __RPCCOROOBJ_H__
#define __RPCCOROOBJ_H__

#include "co/CoroutineBase.h"
#include "RpcBaseObj.h"

static int cnt = 100000;

class RpcCoroObj : public RpcBaseObj
{
public:
    RpcCoroObj(CoroutineBase *coro);
    virtual ~RpcCoroObj();

    virtual void Run();

    // void SetYieldFlag(const bool flag) { yield_flag_ = flag; }
    // bool CanYield() const { return yield_flag_; }

    CoroutineBase* GetCoro();
private:
    CoroutineBase  *coro_;
    // bool            yield_flag_;
};

#endif
