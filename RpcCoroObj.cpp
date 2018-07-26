#include "RpcCoroObj.h"
#include "co/UCoroutine.h"
#include "RpcObjMgr.h"

#include <iostream>

RpcCoroObj::RpcCoroObj(CoroutineBase *coro)
    : coro_(coro)  // , yield_flag_(false)
{
}

RpcCoroObj::~RpcCoroObj()
{
}

void RpcCoroObj::Run()
{
    std::cout << "Run() is call, id = " << id_ << std::endl;
	int i = 0;
	while (++i < cnt)
	{
		coro_->Yield();
	}
}

/*
void RpcCoroObj::Run()
{
    if (id_ > 3)
    {
        std::cout << "id = " << id_ << ", will not create sub coroutine" << std::endl;
        return;
    }
    std::cout << "Run() is call, id = " << id_ << ", yield_flag = " << yield_flag_ << std::endl;

    if (yield_flag_)
    {
        std::cout << "id = " << id_ << ", going to yield" << std::endl;
        coro_->Yield();
        std::cout << "Run() resume, id = " << id_ << std::endl;
    }

    CoroutineBase *co3 = new UCoroutine();

    RpcBaseObj *obj3 = new RpcCoroObj(co3);
    static_cast<RpcCoroObj*>(obj3)->SetYieldFlag(true);
    RpcObjMgr::Instance()->Insert(obj3);


    co3->CreateCoroutine(coro_, obj3);
    co3->Resume();
    std::cout << "id = " << id_ << ", continue" << std::endl;
}
*/

CoroutineBase* RpcCoroObj::GetCoro()
{
    return coro_;
}

