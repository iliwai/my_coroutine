#include "WCoroutine.h"
#include <iostream>
#include <string>

void* WLogicFun(void* p)
{
    if (!p)
    {
        return nullptr;
    }
	RpcBaseObj* obj = static_cast<RpcBaseObj*>(p);
    obj->Run();
	return nullptr;
}

WCoroutine::WCoroutine() : co_(nullptr)
{
}

WCoroutine::~WCoroutine()
{
	if (co_)
	{
		co_release(co_);
	}
}

int WCoroutine::CreateCoroutine(CoroutineBase* father, RpcBaseObj *obj)
{
	int ret = co_create(&co_, nullptr, (void* (*)(void*))WLogicFun, (void*)obj);
	if (0 == ret)
	{
		state_ = INIT;
	}
	return ret;
}

void WCoroutine::Resume()
{
    state_ = RUNNING;
    co_resume(co_);
}

void WCoroutine::Yield()
{
    state_ = SUSPEND;
    co_yield(co_);
}
