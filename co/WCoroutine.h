#ifndef __WCOROUTINE_H__
#define __WCOROUTINE_H__

// using libco 

#include "CoroutineBase.h"
#include "co_routine.h"

void* WLogicFun(void*);

class WCoroutine : public CoroutineBase
{
public:
    WCoroutine();
    virtual ~WCoroutine();

    stCoRoutine_t* GetContext() { return co_;}

    // create and run coroutine
    virtual int CreateCoroutine(CoroutineBase* father, RpcBaseObj *obj);
    virtual void Resume();
    virtual void Yield();

private:
    // WCoroutine*  father_;
	stCoRoutine_t*		co_;
};

#endif
